#include<stdio.h>
#include<stdlib.h>
struct list_int 
{
	int val;
	struct list_int *next;
};
struct list_int *head = NULL;
void input()
{
	struct list_int *cur;
	int i = 0 , n;
	printf("nhap du lieu cho nut dau : \n");
	head = (struct list_int *)malloc(sizeof(struct list_int));
	printf("nhap gia tri : \n");
	scanf("%d", &n);
	head->val = n;
	head->next = NULL;
	cur = (struct list_int *)malloc(sizeof(struct list_int));
	cur = head;
	
	do
	{
		struct list_int *tmp;
		tmp = (struct list_int *)malloc(sizeof(struct list_int));
		printf("ban co muon nhap data nua khong : \n");
	   scanf("%d", &i);
	   if(i == 1)
	   {
	   	  printf("nhap du lieu : \n");
	   	  printf("nhap gia tri : \n");
	   	  scanf("%d", &n);
	   	  tmp->val = n;
	   	  tmp->next = NULL;
	   	  cur->next = tmp;
	   	  cur= cur->next;
	   }
	}while(i == 1);
}
void print()
{
   struct list_int *cur;
   cur = head;
   printf("danh sach da nhap la : \n");
   while(cur != NULL)
   {
       printf("%d ", cur->val);
	   cur = cur->next;   	
	};	
}
void dao_nguoc()
{
	struct list_int *cur,*prev;
	cur = prev = NULL; 
	while(head != NULL)
	{
		cur = head;
		head = head->next;
		cur->next = prev;
		prev = cur; 
	};
	head = prev; 
} 
int main()
{
	input();
	print();
	printf("\n dao nguoc danh sach : \n");
	dao_nguoc();
	print(); 
	return 0;
}


