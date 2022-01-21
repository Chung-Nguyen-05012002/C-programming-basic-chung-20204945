//Nguyen Van Chung 
//mssv 20204945 
#include <stdio.h>
#include <stdlib.h>
int soPhanTu = 0;
void inMang(int number[])
{
	for(int i = 0; i < soPhanTu; i++)
	{
		printf("%d ", number[i]);
	}	
}

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

int main()
{
	int number[1000];
	int n = 0;
	fflush(stdin);
	scanf("%d", &soPhanTu);
	for(int i = 0; i< soPhanTu; i++)
	{
		number[i] = rand();
	}
	inMang(number);
	insertionSort(number, soPhanTu);
	printf("\nSau khi sap xep:\n");
	inMang(number);
	
}
