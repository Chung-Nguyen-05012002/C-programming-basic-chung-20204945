// Nguyen Van Chung 20204945
// tim kiem nhi phan bang queue
#include<stdio.h>
#include<stdlib.h>
# define max 100
struct address
{
    char name[30];
    char telephone[30];
    char email[30];
};
struct queue
{
	struct address data[max]; 
	int  front , rear;
};  
void makenullqueue(struct queue *q)  // tao queue rong
{
	q->front = -1;
	q->rear =  -1;
}
int emptyqueue(struct queue q)  // ham kiem tra queue co rong khong 
{
	return (q.front == -1);
}
int full_queue(struct queue q)  // ham kiem tra queue day chua
{
	return (q.rear-q.front + 1) == max;  
	 
 } 
void push(struct address v, struct queue *q)
{
	if(!full_queue(*q))
	{
		if(emptyqueue(*q))
		    q->front = 0;
		q->rear = q->rear + 1;
		q->data[q->rear] = v;
	}
	else
	    printf("ngan xep da day !\n");
}
void pop(struct queue *q)   // ham xoa 
{
	if(!emptyqueue(*q))
	{
		q->front = q->front + 1;
		if(q->front > q->rear)
		   makenullqueue(q); // queue tro thanh rong
	}
	else
	  printf("queue rong !\n");
}
void print(struct queue q)  // in ra queue
{
	int i;
	for(i = q.front; i <=  q.rear; i++ )
	{
		printf("%s %s %s\n",q.data[i].name,q.data[i].telephone,q.data[i].email);
	}
}
int tim_kiem_nhi_phan(struct queue q, char s[]) // ham tim kiem nhi phan
{
	int low , mid , high;
	low = q.front ; high = q.rear;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(strcmp(q.data[mid].name,s) < 0)
		  low = mid + 1;
		else if(strcmp(q.data[mid].name,s) > 0)
		  high = mid - 1;
		else
		  return mid - q.front; 
	};
	return -1; 
} 
int main()
{
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
	char k[30];
	printf("nhap ten can tim kiem : ");
	fflush(stdin);
	gets(k);
	if(tim_kiem_nhi_phan(q,k) == -1)
	   printf("khong ton tai !\n");
	else 
	printf("%s o vi tri %d trong day \n", k, tim_kiem_nhi_phan(q,k));
	FILE *p;
	p = fopen("dau_ra_tknp.txt","w");
	i =  tim_kiem_nhi_phan(q,k);
	fprintf(p,"%-10s%-15s%-20s",q.data[i].name,q.data[i].telephone,q.data[i].email); 
    return 0;	
}
