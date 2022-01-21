#include<stdio.h>   //ham de quy tim kiem nhi phan
int binarysearch(int a[], int x, int low, int high)
{
	if(low > high)
	  return -1;
	int mid = (low + high) / 2;
	if(a[mid] < x)
	    return binarysearch(a,x,mid + 1, high);
	else if(a[mid] > x)
	    return binarysearch(a,x,low,mid - 1);
	else
	    return mid;
	return -1;
};
int main ()
{
	int n;
	scanf("%d" , &n);
	int i , a[n];
	for( i = 0 ; i < n ; i++)
	 scanf("%d", &a[i]);
	printf("\n");
	for(i = 0 ; i < n ; i++)
	  printf("%d ", a[i]);
	int x;
	scanf("%d", &x);
	printf("\n");
	printf("%d", binarysearch(a,x,0,n-1));
	return 0;
}

         
