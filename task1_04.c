// Nguyen Van Chung 20204945
// doc 11 danh ba bang queue den khi queue day thi xoa danh ba roi them danh ba thu 11 vao queue
// max queue = 10
#include<stdio.h>
#include<stdlib.h>
# define max 10
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
int dem_pt(struct queue q)
{
	int i = 0; 
	struct node *tmp;
	for(tmp = q.front->next; tmp != NULL; tmp = tmp->next)
	   i++;
	return i; 
};
int main()
{
    int i ;
	struct queue q;
	makenullqueue(&q);
    FILE *f;
    f = fopen("danh_ba_dien_thoai.txt", "r");
	FILE *p;
    p = fopen("copy.txt", "w");
    while(!feof(f))
    {
        struct address tmp;
        fscanf(f,"%s %s %s",&tmp.name,&tmp.telephone,&tmp.email);
        push(tmp,&q);
		if(dem_pt(q) > max)
		{
			struct node *tmp;
            tmp = q.front->next;
			fprintf(p,"%s %s %s\n",tmp->data.name,tmp->data.telephone,tmp->data.email);
            pop(&q);
		}
	};
    printf("danh ba dien thoai : \n");
	print(q);
    return 0;	
} 