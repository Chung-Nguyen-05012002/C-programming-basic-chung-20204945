#include<stdio.h> 
#include<string.h> 
int so_sanh(char s1[], char s2[])  // so sanh s1 co phai sau con cua s2 
{
	if(strlen(s1) > strlen(s2))
	  return -1;
	else
	{
		int i;
		for(i = 0 ; i < strlen(s1); i++)
			if(s1[i] != s2[i])
			  return -1; 
	};
	return 1; 
}
int main ()
{
	char s1[40],s2[40];
	printf("nhap sau con can tim : ");
	fflush(stdin);
	gets(s1); 
	FILE *f;
	f = fopen("bai4tuan6.txt","r");
	printf("cac tu khoa co chua trong file la : \n"); 
	while(!feof(f))
	{
		fscanf(f,"%s",&s2);
		if(so_sanh(s1,s2)== 1)
		  printf("%s\n",s2); 
	}; 
	return 0; 
} 
