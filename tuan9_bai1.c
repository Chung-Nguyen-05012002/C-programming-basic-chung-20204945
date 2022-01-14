#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
{
	char email[40];
	struct node *left, *right;
};
int empty(struct node *t)     // ham kiem tra xem cay nhi phan co rong khong
{
	return t == NULL;
};
void insert(struct node **t, char s[])
{
	if( (*t)  == NULL)
	{
		(*t) = (struct node *)malloc(sizeof(struct node));
		strcpy((*t)->email,s);
		(*t)->left = NULL;
		(*t)->right = NULL;
	}
	else
	    if(strcmp((*t)->email,s) == 0)
	        printf("da ton tai email !\n");
	    else
	        if(strcmp((*t)->email,s) > 0)
	            insert(&(*t)->left,s);
	        else if(strcmp((*t)->email,s) < 0)
	            insert(&(*t)->right,s);
}
void inorder(struct node *t)    // duyet trung tu
{
	if(t != NULL)
	{
        inorder(t->left);
		printf("%s \n", t->email);
		inorder(t->right);		
	};
}
struct node *search(struct node *t, char s[])
{
	if(t == NULL)
	    return NULL;
    else 
	    if(strcmp(t->email,s) == 0)
	        return t;
		else
		    if(strcmp(t->email,s) > 0)
			    return search(t->left,s);
			else
			    return search(t->right,s);
}
int main ()
{
	struct node *root;
	root = (struct node *)malloc(sizeof(struct node));
	root = NULL;
	int n , i;
	char email[40];
	FILE *f;
	f = fopen("email.txt","r");
	while(!feof(f))
	{
		fscanf(f,"%s", &email);
		insert(&root,email);
	};
    inorder(root);
	printf("nhap dia chi can tim : ");
	char tim[40];
	scanf("%s", &tim);
	struct node *tmp = search(root,tim);
	if(tmp == NULL)
	   printf("khong ton tai \n");
	else
	   printf("ton tai email : %s",tmp->email);
	FILE *p;
	p = fopen("data.txt", "w");
	fprintf(p,"%s",tmp->email);
    return 0;
}


















