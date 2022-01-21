// Nguyen Van Chung20204945 
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

Address danhBa[100];
int soLuongLienHe = 0;

void KhoiTaoDuLieu() // Khi chua co file danh ba thi su dung ham nay
{
	FILE * fin = NULL;
	fin = fopen("danh_ba_in.dat", "wb+");
	char tmp[40];
	char * eof;
	if(fin == NULL)
	{
		printf("Loi mo file ghi du lieu\n");
		exit(-1);
	}
	printf("Nhap thong tin lien he cua 10 nguoi\n");
	for(int i = 0; i < 10; i++) // Khoi tao 10 thong tin lien lac
	{
		printf("Thong tin lien lac cua nguoi %d: \n", i + 1);
		fflush(stdin);
		printf("\tHo ten: ");
		fgets(tmp, 40, stdin);
		if(eof = strchr(tmp, '\n')) // xoa ky tu xuong dong o cuoi
		{
			*eof = '\0';
		}
		strcpy(danhBa[i].name, tmp);
		fflush(stdin);
		printf("\tEmail: ");
		scanf("%40s", danhBa[i].email);
		fflush(stdin);
		printf("\tPhone: ");
		scanf("%11s", danhBa[i].phone);
	}
	fwrite(danhBa, sizeof(Address), 10, fin);
	fclose(fin);
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
	for(int i = 0; i < soLuongLienHe; i++)
	{
		fscanf(fin, "%s", danhBa[i].name);	
		fscanf(fin, "%s", danhBa[i].phone);	
		fscanf(fin, "%s", danhBa[i].email);	
	}

}

void inDanhBa()
{
	for(int i = 0; i < soLuongLienHe; i++)
	{
		printf("Thong tin lien he nguoi thu %d \n", i +1);
		printf("\tHo ten: %s\n", danhBa[i].name);
		printf("\tPhone: %s\n", danhBa[i].phone);
		printf("\tEmail: %s\n", danhBa[i].email);
		printf("\n");
	}
}

void swapElement(Address *a, Address *b)
{
	Address temp;
	strcpy(temp.email, a->email);
	strcpy(temp.name, a->name);
	strcpy(temp.phone, a->phone);
	
	strcpy(a->phone, b->phone);
	strcpy(a->email, b->email);
	strcpy(a->name, b->name);
	
	strcpy(b->phone, temp.phone);
	strcpy(b->name, temp.name);
	strcpy(b->email, temp.email);
}

void quicksort(int first, int last){
   int i, j, pivot, temp;

   if(first<last)
   {
      pivot = first;
      i = first;
      j = last;

      while(i<j){
      	
         while((strcmp(danhBa[i].name, danhBa[pivot].name) < 0) && i<last)
            i++;
         while(strcmp(danhBa[j].name, danhBa[pivot].name) > 0)
            j--;
         if(i < j) {
         	swapElement(&danhBa[i], &danhBa[j]);
         }
      }
	  swapElement(&danhBa[pivot], &danhBa[j]);
      quicksort(first,j-1);
      quicksort(j+1,last);

   }
}

int ghiKetQua(int index)
{
	FILE * fout = NULL;
	fout = fopen("danh_ba_out.txt", "w+");
	if(fout == NULL)
	{
		printf("Loi mo file ghi\n");
		exit(-1);
	}
	
	fprintf(fout, "Ho ten: %s\nPhone: %s\nEmail: %s\n", danhBa[index].name, danhBa[index].phone, danhBa[index].email);
	fclose(fout);
	return 1;
}


int main()
{
	int chucNang = 0;
	char tmp[nameLength];
	docDuuLieu();
	inDanhBa();
	quicksort(0, soLuongLienHe - 1);
	printf("Sau khi sap xep\n");
	inDanhBa();
	

	return 0;
}
