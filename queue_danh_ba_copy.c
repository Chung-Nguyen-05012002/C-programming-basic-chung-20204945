#include<stdio.h>
#include<stdlib.h>
struct address
{
    char name[30];
    char telephone[30];
    char email[30];
};
struct node
{
	struct address data;
	struct node *next; 
};
struct queue
{
	struct node  *front , *rear;
};  
void makenullqueue(struct queue *q)  // tao queue rong
{
	struct node *header;
	header = (struct node *)malloc(sizeof(struct node));
	header->next = NULL;
	q->front = header;
	q->rear = header;
}
int emptyqueue(struct queue q)
{
	return (q.front == q.rear);
}
void push(struct address v, struct queue *q)
{
	q->rear->next = (struct node *)malloc(sizeof(struct node));
	q->rear = q->rear->next;
	q->rear->data = v;
	q->rear->next = NULL;
}
void pop(struct queue *q)
{
	if(!emptyqueue(*q))
	{
		struct node *t;
		t = q->front;
		q->front = q->front->next;
		free(t);
	}
	else
	  printf("queue rong !\n");
}
void print(struct queue q)
{
	struct node *tmp;
	for(tmp = q.front->next; tmp != NULL; tmp= tmp->next )
	{
		printf("%s %s %s\n",tmp->data.name,tmp->data.telephone,tmp->data.email);
	}
}
int main()
{
	printf("nhap so du lieu can them : ");
    int i ;
	struct queue q;
	makenullqueue(&q);
    FILE *f;
    f = fopen("danh_ba_dien_thoai.txt", "r");
    while(!feof(f))
    {
        struct address tmp;
        fscanf(f,"%s %s %s",&tmp.name,&tmp.telephone,&tmp.email);
        push(tmp,&q);    
    };
    printf("danh ba dien thoai : \n");
	print(q);
    FILE *p;
    p = fopen("copy.txt", "w");
    struct node *tmp;
    tmp = q.front->next;
    while(tmp != NULL)
    {
        fprintf(p,"%s %s %s\n",tmp->data.name,tmp->data.telephone,tmp->data.email);
        tmp=tmp->next;
    }
	return 0;	
} 





