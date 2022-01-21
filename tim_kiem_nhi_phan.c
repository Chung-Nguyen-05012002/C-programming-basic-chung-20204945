#include<stdio.h>
int binarysearch(int a[], int x, int n)
{
	int low, mid, high;
	low = 0 ; high = n - 1;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(a[mid] < x)
		  low = mid + 1;
		else if(a[mid] > x)
		  high = mid - 1;
		else
		  return mid;   // da tim thay		
	}
	return -1;
}
int main ()
{
	int n, i;
	printf("nhap so gia tri cua day : ");
	scanf("%d", &n);
	int a[n];
	for(i = 0 ; i < n ; i++)
	   scanf("%d", &a[i]);
	printf("day vua nhap la : \n");
	for(i = 0 ; i < n ; i++)
	  printf("%d ", a[i]);
	int x;
	printf("nhap gia tri can tim : ");
	scanf("%d", &x);
	printf("\n %d", binarysearch(a,x,n));
	return 0;
}
