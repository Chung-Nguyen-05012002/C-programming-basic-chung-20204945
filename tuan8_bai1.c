#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
struct node
{
	int data;
	struct node *left, *right;
};
int empty(struct node *t)  // ham kiem tra nut do co rong khong
{
	return t == NULL;
};
struct node *search(int x , struct node *root)  //hàm tìm kiêm
{
    if(root == NULL)
	   return NULL;   // khong tim thay x
	else if(root->data == x)  // tim thay khoa x 
	   return root;
	else if (root->data < x)  // tim tiep cay ben phai
	   return search(x,root->right);
	else  // tim tiep cay ben trai
	   return search(x,root->left);   
} 
void insert(int x, struct node **t)   // hàm thêm 1 nút vào cây
{
	if((*t) == NULL)
	{
	   (*t) = (struct node *)malloc(sizeof(struct node));
	   (*t)->data = x;
	   (*t)->left = NULL;
	   (*t)->right = NULL;	
	}
    else
    if((*t)->data == x)
	    printf("da ton tai gia tri x");
	else
	    if((*t)->data > x)
		    insert(x,&(*t)->left);
		else
		    insert(x,&(*t)->right); 
}
void inorder(struct node *t)  // duyet trung tu 
{
	if(t != NULL)
	{
		inorder(t->left);
		printf("%d ",t->data);
		inorder(t->right);
	}
}
int deletemin(struct node **t)//ham xoa gia tri nho nhat trong cay va tra ve no 
{
	int k; 
	if((*t)->left == NULL)
	{
		k = (*t)->data;
		(*t) = (*t)->right;
		return k; 
	}
	return deletemin(&(*t)->left); 
} 
void deletenode(int x, struct node **t) //ham xoa 1 nut tren cay
{
	if((*t) != NULL)  // kiem tra cay khac rong
	  if(x < (*t)->data)  // hi vong cay nam ben trai nut
	       deletenode(x,&(*t)->left);
	  else
	        if(x > (*t)->data)
	           deletenode(x,&(*t)->right);
			else  // tim thay khoa x tren cay   
		        if(((*t)->left == NULL) && ((*t)->right == NULL)) // x la nut la 
	                (*t) = NULL; // xoa nut la  
	            else  // x co it nhat 1 con 
	              if((*t)->left == NULL)  // chac chan co con phai 
	                (*t) = (*t)->right; 
	              else
				     if((*t)->right == NULL)   // chac chan co con trai 
	                     (*t) = (*t)->left;
	                  else  // x co 2 con
	                    (*t)->data = deletemin(&(*t)->right);
}
int main ()
{
	struct node *tree;
	tree = (struct node *)malloc(sizeof(struct node));
	tree = NULL;
	int n;
	printf("nhap so nut : ");
	scanf("%d", &n);
	int a[n];
	int i;
	srand(time(NULL));
	for(i = 0  ; i < n ; i++)
	{
		a[i] = rand() % 20;
		printf("\n%d\n", a[i]);
		insert(a[i],&tree); 
	};
    printf("duyet trung tu : ");
    inorder(tree);
    printf("nhap i : ");
    scanf("%d", &i );
    deletenode(i,&tree);
    inorder(tree);
    printf("\n %d" ,tree->data);
    printf("nhap gia tri tim kiem : ");
    scanf("%d", &i);
    struct node *timkiem = search(i, tree);
    if(timkiem == NULL)
       printf("khong co !\n");
    else
      {
      	 printf("ton tai %d ", i);
	  };
    return 0;
}



