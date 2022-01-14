//nguyen van chung 20204945
// chuyen bieu thuc toan hoc sang balan
#include<stdio.h>
#include<string.h>
# define max 100
struct stack
{
	char data[max];
	int top;
};
void push(struct stack *s, char item)  // them phan tu
{
	if(s->top < max - 1)
	{
		s->top += 1;
		s->data[s->top] = item;
	}
 }
void pop(struct stack *s)   // xoa phan tu 
{
   if(s->top >= 0)
    s->top -= 1;	
}
void print(struct stack *s)     
{
	printf("%c", s->data[s->top]);
};
int main ()
{
	struct stack st;
	st.top = -1;
    char s[100];
	printf("nhap phep toan : ");
	fflush(stdin);
	gets(s);
	int i;
	printf("sau khi chuyen : ");
	for(i = 0 ; i < strlen(s); i++)
	{
	    if(s[i] < '0' || s[i] > '9')
	    {
	    	if(st.top == -1)  // stack rong
		      push(&st,s[i]);
		    else     // co 1 phan tu trong stack
		    {
		    	if(st.data[st.top] == '*' || st.data[st.top] == '/')
				{
					printf("%c ", st.data[st.top]);
					pop(&st);
					if(s[i] == '*' || s[i] == '/') // neu s[i] nhan chia 
					push(&st, s[i]);
					else      // neu s[i] cong tru thi in ra tiep roi xoa
					{
					  	printf("%c ", st.data[st.top]);
					    pop(&st);
						push(&st,s[i]);	
					};  
				}
				else    
				{
					if(s[i] == '+' || s[i] == '-')
					{
						printf("%c ", st.data[st.top]);
						pop(&st);
						push(&st,s[i]);
					}
					else   // s[i] == '*'
					    push(&st,s[i]); 
				} 
			}
		}
		else
		  printf("%c ", s[i]);   // neu la so thi in ra
    }
	for(i = st.top; i >= 0 ; i--)
	   printf("%c ", st.data[i]);
	return 0;	 
} 






























