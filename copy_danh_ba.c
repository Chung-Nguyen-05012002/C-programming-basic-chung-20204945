#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct address
{
	char name[20];
	char telephone_number[30];
	char e_mail[30]; 
};
struct  node
{
	struct address danh_ba;
	struct node *next;
};
struct node *push(struct node *s,struct address item)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->danh_ba = item;
	temp->next = s;
	s = temp;  
	return s; 
}
struct node *pop(struct node *s, struct address *item)
{
	struct node *temp;
	*item = s->danh_ba;
	temp = s;
	s = s->next;
	free(temp);
	return s; 
}
void  print(struct node *s)
{
	struct node *tmp;
	tmp = s;
	while(tmp != NULL)
	{
		printf("%s %s %s\n",tmp->danh_ba.name,tmp->danh_ba.telephone_number
		                    ,tmp->danh_ba.e_mail);
		tmp = tmp->next;
	}
 } 
// chuong trinh copy danh ba sanh 1 file khac su dung stack
int main()
{
	struct node *head ;
	
	head = (struct node *)malloc(sizeof(struct node));
	head = NULL;
	FILE *p;
	struct address data; 
	p = fopen("danh_ba_dien_thoai.txt", "r");
	while(!feof(p))
	{
		fscanf(p,"%s %s %s",&data.name,&data.telephone_number,&data.e_mail);
		head = push(head,data);
		//printf("%s", head->danh_ba.name); 
	};
	printf("danh ba la :\n");
    print(head);
	FILE *output;
	output = fopen("danh_ba_copy.txt", "w");
    if(output == NULL)
       printf("no ");
    struct node *cur ;
    cur = head;
	while(cur != NULL)
	{
		//head = pop(head,&data);
        data = cur->danh_ba;
        fprintf(output,"%s %s %s\n",data.name,data.telephone_number,data.e_mail);
        cur = cur->next; 
	};  
	return 0;
} 

