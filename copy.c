// chương trình copy file nay sang file khác
#include<stdio.h>
int main()
{
    FILE *input, *output;
    char inputfile[20],outputfile[20], ch[40] ;
    printf("nhap ten file muon copy : ");
    fflush(stdin);
    gets(inputfile);
    printf("nhap ten file muon copy sang : ");
    fflush(stdin);
    gets(outputfile);
    input = fopen(inputfile, "r");
    output = fopen(outputfile, "w");
    while(fgets(ch, 40 , input))
    {
        fputs(ch,output);
    };
    return 0;
}
