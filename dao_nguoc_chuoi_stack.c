#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char data;
	struct node *link; 
 }; 
 struct node *push(struct node *p, char value)
 {
 	struct node *temp;
 	temp = (struct node *)malloc(sizeof(struct node));
 	if(temp == NULL)
 	{
 	    printf("khong the cap phat bo nho !\n");
		 exit(0);	
	}
	temp->data = value;
	temp->link = p;
	p = temp;
	return p;
 }
 struct node *pop(struct node *p , char *value)
 {
 	struct node *temp;
 	if(p == NULL)
 	{
 		printf("stack trong ! khong the xoa !");
 		exit(0);
	}
	*value = p->data;
	temp = p;
	p = p->link;
	free(temp);
	return p;
 }
 // dao nguoc 1 xau nhan tu nguoi dung
 int main()
 {
 	struct node *p;
 	p = (struct node *)malloc(sizeof(struct node));
 	char chuoi[100]; // nhp chuoi tu nguoi dung 
 	printf("nhap chuoi : ");
 	fflush(stdin);
 	gets(chuoi);
 	int i;
 	for(i = 0 ; i < strlen(chuoi); i++)
 	{
 		p = push(p,chuoi[i]);
	};
	for(i = 0 ; i < strlen(chuoi); i++)
	{
	    p = pop(p, &chuoi[i]);	
	};
	printf("chuoi sau khi dao nguoc la : \n");
	puts(chuoi);
	return 0; 
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
