#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct address
{
	char name[30];
	char phone[15];
	char email[30]; 
}; 
struct node
{
 	struct address data;
	struct node *next;
};
struct node *list;
void insert() // ham them 1 phan tu vao phia ngay sau phan tu hien thoi 
{
	struct node *chen, *tmp;
	struct address add;
	tmp = list;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	};
	chen = (struct node *)malloc(sizeof(struct node));
	printf("nhap du lieu cua node ma ban muon them vao : \n");
	printf("nhap name : ");
	fflush(stdin);
	gets(add.name);
	printf("nhap phone : ");
	fflush(stdin);
	gets(add.phone);
	printf("nhap email : ");
	fflush(stdin);
	gets(add.email);
	strcpy(chen->data.name, add.name);
	strcpy(chen->data.phone, add.phone);
	strcpy(chen->data.email, add.email);
	chen->next = NULL;
	tmp->next = chen;
}
void input(int n) //ham nhap danh sach lien ket don chua phone address
{
	int i; 
	struct address add;
	struct node *hientai, *cur; 
	list = (struct node *)malloc(sizeof(struct node));
   if(list == NULL)
     printf("khong the cap phat bo nho ! ");
	else
	{
	   printf("nhap du lieu cua nguoi thu 1 : \n");
	   printf("nhap name : ");
	   fflush(stdin);
	   gets(add.name);
	   printf("nhap phone : ");
	   fflush(stdin);
	   gets(add.phone);
	   printf("nhap email : ");
	   fflush(stdin);
	   gets(add.email); 
	   strcpy(list->data.name,add.name);
	   strcpy(list->data.phone,add.phone);
	   strcpy(list->data.email,add.email);
	   list->next = NULL;
	   cur = list; 
	   for(i = 2 ; i <= n ;i++)
	    {
	     hientai = (struct node*)malloc(sizeof(struct node));
	   	  printf("nhap du lieu cua nguoi thu %d : \n", i);
		  printf("nhap name : ");
	      fflush(stdin);
	      gets(add.name);
	      printf("nhap phone : ");
	      fflush(stdin);
	      gets(add.phone);
	      printf("nhap email : ");
	      fflush(stdin);
	      gets(add.email);
		  strcpy(hientai->data.name, add.name);
		  strcpy(hientai->data.phone, add.phone);
		  strcpy(hientai->data.email, add.email);
		  hientai->next = NULL;
		  cur->next= hientai;
		  cur = cur->next; 
		} 
	} 
 } 
 void xuatdanhsach() // ham in ra danh sach 
{
 	int i = 1  ; 
 	struct node *cur;
 	cur = list;
 	while (cur != NULL)
 	{
 		printf("du lieu cua nguoi thu %d : \n", i);
 		puts(cur->data.name);
 		puts(cur->data.phone);
 		puts(cur->data.email);
 		cur = cur->next;
 		i++;
	}
} 
void xoa()  // ham xoa 1 phan tu  
{
	printf("nhap ten ban muon xoa : ");
	char ten[30];
	fflush(stdin);
	gets(ten); 
	struct node *cur, *tmp;
	tmp = list->next;
	cur = list;
	if(strcmp(list->data.name,ten) == 0)
	{
		list = list->next; 
	}
	else
	{
		while(strcmp(tmp->data.name,ten) != 0)
	       {
		     tmp = tmp->next;
			 cur = cur->next; 
	       };
		cur->next = tmp->next;  
    };
} 
int main ()
{
	int i , n;
	printf("nhap so du lieu can nhap : ");
	scanf("%d", &n); 
    input(n); 
    while(1)
    {
    	system("cls");
    	int luachon; 
    	printf("chuong trinh co cac chuc nang sau : \n");
		printf("1. xuat ra danh sach : \n");
		printf("2. them 1 phan tu ngay sau phan tu hien thoi \n");
		printf("3. xoa 1 node bat ki nhap ten tu ban phim \n"); 
		printf("4. thoat chuong trinh \n"); 
		printf("*************************************\n");
		printf("nhap chuc nang ban chon : ");
		scanf("%d", &luachon);
		switch(luachon)
		{
			case 1 : 
			   printf("xuat danh sach : \n"); 
			   xuatdanhsach();
			   getch();
			   break;
			case 2 : 
			   printf("them 1 phan tu : \n"); 
			   insert();
			   break;
			case 3 : 
			   printf("ban chon chuc nang xoa 1 node : \n");
			   xoa(); 
			   break; 
			case 4 : 
			  printf("thoat chuong trinh ");
			  return 0;
			default :
				printf("khong co chuc nang nay : ");
				break;
		} 
    }
   return 0;	
} 




