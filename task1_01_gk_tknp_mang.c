//  Nguyen Van Chung 20204945
// tim kiem nhi phan bang mang cau truc
#include<stdio.h>
#include<string.h>
struct address
{
	char name[30];
	char telephone[30];
	char email[30]; 
};
void print(struct address a[], int n)
{
	int i;
	for(i = 0 ; i < n ; i++) 
	  printf("%-10s%-18s%-25s\n",a[i].name,a[i].telephone,a[i].email); 
};
void sap_sep(struct address a[], int n)
{
	int i , j;
	for(i = 0 ; i < n ; i++)
	  for(j = i + 1; j < n ; j++)
	    if(strcmp(a[i].name,a[j].name) > 0)
		  {
		  	struct address tmp;
			  tmp = a[i];
			  a[i] = a[j];
			  a[j] = tmp; 
			}; 
};
int tim_kiem_nhi_phan(struct address a[], struct address x[], int n)
{
	int low , mid , high;
	low = 0 ; high = n - 1;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(strcmp(a[mid].name,x) < 0)
		  low = mid + 1;
		else if(strcmp(a[mid].name,x) > 0)
		  high = mid - 1;
		else
		  return mid; 
	};
	return -1; 
} 
int main ()
{
	struct address a[100]; 
	FILE *f;
	f = fopen("email.txt", "r");
	int i = 0; 
	while(!feof(f))
	{
		fscanf(f,"%s %s %s",&a[i].name, &a[i].telephone, &a[i].email);
		i += 1; 
	}; 
	int n = i - 1; 
	printf("danh sach address vua nhap : \n");
	print(a,n);
	printf("danh sach sau khi sap xep la : \n");
	sap_sep(a,n);
	print(a,n);
	char k[30];
	printf("nhap ten can tim kiem : ");
	fflush(stdin);
	gets(k);
	if(tim_kiem_nhi_phan(a,k,n) == -1)
	   printf("khong ton tai !\n");
	else 
	printf("%s o vi tri %d trong day \n", k, tim_kiem_nhi_phan(a,k,n));
	FILE *p;
	p = fopen("dau_ra_tknp.txt","w");
	i =  tim_kiem_nhi_phan(a,k,n);
	fprintf(p,"%-10s%-15s%-20s",a[i].name, a[i].telephone, a[i].email); 
	return 0; 
} 






















