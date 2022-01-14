// nguyen van chung 20204945
//tinh toan tu bieu thuc ngich dao balan
#include<stdio.h>
#include<string.h>
# define max 100
struct stack
{
	int  data[max];
	int top;
};
void push(struct stack *s, int  item)  // them vao stack
{
	if(s->top < max - 1)
	   {
	   	  s->top += 1;
	   	  s->data[s->top] = item;
	   }
};
void pop(struct stack *s)  // xoa phan tu
{
	if(s->top >= 0)
	   s->top -= 1;
};
int main ()
{
	char s[100];
	printf("nhap phep toan dao balan : ");
	fflush(stdin);
	gets(s);
	struct stack st;
	st.top = -1;
	int i;
	for(i = 0 ; i < strlen(s); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
		  push(&st,s[i] - 48);
		else
		{
           if(s[i] == '*')
		    {
		       int x = st.data[st.top] * st.data[st.top -1];
		       pop(&st);
		       pop(&st);
		       push(&st, x);
			};
			if(s[i] == '/')
		    {
		       int x =st.data[st.top -1 ]*1.0/st.data[st.top];
		       pop(&st);
		       pop(&st);
		       push(&st, x);
			};
			if(s[i] == '+')
		    {
		       int  x = st.data[st.top -1] + st.data[st.top];
		       pop(&st);
		       pop(&st);
		       push(&st, x);
			};
			if(s[i] == '-')
		    {
		       int x = st.data[st.top -1 ] - st.data[st.top];
		       pop(&st);
		       pop(&st);
		       push(&st, x);
			};
		};
	};
	printf("\n %d", st.data[st.top]);
	return 0;
}













