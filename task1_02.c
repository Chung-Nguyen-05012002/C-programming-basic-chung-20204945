// Nguyen Van Chung 20204945
// chuong trinh tim kiem ten bang danh sach lien ket
// neu tim thay thi dua len dau  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nameLength 40
#define emailLength 40
#define phoneLength 11
typedef struct Address {
	char name[nameLength];
	char email[emailLength];
	char phone[phoneLength];
} Address;

typedef struct danhBa {
	Address data;
	struct danhBa * next;
} danhBa;

danhBa * nodeList;
int soLuongLienHe = 0;

danhBa * makeNode(Address data)
{
	danhBa * tmp;
	tmp = (danhBa *)malloc(sizeof(danhBa));
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

danhBa * insertLast(danhBa * list, Address data)
{
	danhBa * newNode = makeNode(data);
	if(list == NULL)
	{
		
		list = newNode;
	} 	
	else
	{
		danhBa *tmp = list;
		while(tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
	return list;
}



void docDuuLieu()
{
	FILE * fin = NULL;
	fin = fopen("danh_ba_in.txt", "r+");
	if(fin == NULL)
	{
		printf("File khong ton tai");
		exit(-1);
	}
	fscanf(fin, "%d", &soLuongLienHe);
	if(soLuongLienHe == 0)
	{
		printf("Khong co lien he nao");
		exit(-1);
	}
	Address tmp;
	int i;
	for( i = 0; i < soLuongLienHe; i++)
	{
		fscanf(fin, "%s", tmp.name);	
		fscanf(fin, "%s", tmp.phone);	
		fscanf(fin, "%s", tmp.email);	
		nodeList = insertLast(nodeList, tmp);
	}

}

void inDanhBa(danhBa * nodeList)
{
	danhBa *tmp;
	tmp = nodeList;
	int num = 0;
	while(tmp)
	{
		printf("Thong tin lien he nguoi thu %d \n", num +1);
		printf("\tHo ten: %s\n", tmp->data.name);
		printf("\tPhone: %s\n", tmp->data.phone);
		printf("\tEmail: %s\n", tmp->data.email);
		printf("\n");
		tmp = tmp->next;
		num++;
	}
}

void swapElement(danhBa * i, danhBa * j)
{
	Address tmp;
	tmp = i->data;
	i->data = j->data;
	j->data = tmp;
}

void sort_by_name(danhBa * nodeList)
{
	danhBa *i, *j;
	for( i = nodeList; i != NULL; i = i->next)
	{
       for( j = i->next; j != NULL; j = j->next)
       {
       		if(strcmp(i->data.name, j->data.name) > 0)
       		{
       			swapElement(i, j);
			}
	   }
    }
}

int ghiKetQua(Address result)
{
	FILE * fout = NULL;
	fout = fopen("danh_ba_out.txt", "w+");
	if(fout == NULL)
	{
		printf("Loi mo file ghi\n");
		exit(-1);
	}
	
	fprintf(fout, "Ho ten: %s\nPhone: %s\nEmail: %s\n", result.name, result.phone, result.email);
	fclose(fout);
}

danhBa * find(danhBa * nodeList, char name[])
{
	danhBa * tmp = nodeList;
	while(tmp->next != NULL)
	{
		if(strcmp(tmp->next->data.name, name) == 0)
		{
			printf("Tim thay %s trong danh ba\n", name);
			printf("\tHo ten: %s\n", tmp->next->data.name);
			printf("\tDien thoai: %s\n", tmp->next->data.phone);
			printf("\tEmail: %s\n", tmp->next->data.email);
			ghiKetQua(tmp->next->data);
			return tmp;
		}
		tmp =  tmp->next;
	}
	printf("Khong tim thay %s trong danh ba\n", name);
	return NULL;
}


int main()
{
	int chucNang = 0;
	char tmp[nameLength];
	docDuuLieu();
	inDanhBa(nodeList);
	sort_by_name(nodeList);
	printf("\nSau khi sap xep\n");
	inDanhBa(nodeList);
	while(1)
	{
		fflush(stdin);
		printf("Cac tinh nang cua chuong trinh: \n");
		printf("1. Tim kiem theo ten\n");
		printf("-1. Thoat chuong trinh\n");
		printf("Nhap tinh nang: ");
		scanf("%d", &chucNang);
		switch(chucNang)
		{
			case 1:
				printf("Nhap ten can tim kiem: ");
				fflush(stdin);
				scanf("%s", tmp);
				danhBa * item = find(nodeList, tmp);	
				if(item != NULL)
				{
					danhBa * moveItem = item->next;
					item->next = item->next->next;
					moveItem->next = nodeList;
					nodeList = moveItem;
				}
				printf("Danh sach sau khi tim kiem\n");
				inDanhBa(nodeList);
				getch(); 
			break;
			case -1:
				return 0;
			break;
		}
	}
	return 0;
}
