#include<stdio.h>
int main ()
{
    FILE *f;
    f = fopen("file.txt", "r");
    char ch[100];
    int i = 1;
    while (fgets(ch,100,f) )
    {
        printf("%d ", i);
        puts(ch);
        i++;
    };
    return 0;
}