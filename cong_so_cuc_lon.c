// cong nhung so cuc lon 
#include<stdio.h>
#include<stdlib.h>
# define max 40
struct stack
{
	int data;
	struct stack *next;
};
struct stack *push(struct stack *s, int i)
{
	struct stack *tmp;
	tmp = (struct stack *)malloc(sizeof(struct stack));
	tmp->data = i;
    tmp->next = s;
    s = tmp;
    return s;
}
struct stack *pop(struct stack *s, int *i)
{
   	struct stack *tmp;
   	*i += s->data;
   	tmp = s;
   	s= s->next;
   	free(tmp);
   	return s;
}
void print(struct stack *s)
{
	printf("\n");
	struct stack *tmp;
	tmp = s;
	while(tmp != NULL)
	{
		printf("%d",tmp->data);
		tmp = tmp->next; 
	}; 
}
struct stack *close(struct stack *s)
{
	while(s->next != NULL)
	  s = s->next;
	return s;
}
int main()  // chuong trinh cong cac so cuc lon 
{
	int i= 0 , n;
	struct stack *s1, *s2, *sum;
	s1 = (struct stack *)malloc(sizeof(struct stack));
	s2 = (struct stack *)malloc(sizeof(struct stack));
	sum =(struct stack *)malloc(sizeof(struct stack));
	s1 = NULL;
	s2 = NULL;
	sum = NULL; 
	int so1[max], so2[max];
	printf("nhap so 1 : ");
    scanf("%d", &n);
	for(i = 0 ; i < n ; i++)
	 {
	 	scanf("%d", &so1[i]);
		s1 = push(s1,so1[i]); 
	  } ;
	printf("nhap so 2 : ");
	for(i = 0 ; i < n ; i++)
	 {
	 	scanf("%d", &so2[i]);
		s2 = push(s2,so2[i]); 
	  };
	int d = 0;
	while(s1 != NULL || s2 != NULL)
	{
		int tmp;
		tmp = (d + s1->data + s2->data ) % 10 ;
		d =  (d + s1->data + s2->data ) / 10;
		sum =  push(sum,tmp);
		s1= s1->next;
		s2=s2->next;
	};
	if(d != 0)
	sum = push(sum,d) ;
	print(sum);
	free(sum);
	free(s1);
	free(s2); 
	return 0; 
}





















