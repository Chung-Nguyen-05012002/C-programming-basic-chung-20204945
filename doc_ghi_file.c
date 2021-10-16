#include<stdio.h>
enum {SUCCESS, FAIL , MAX_LEN = 80};
void blockreadwrite(FILE *fin, FILE *fout);
int  main ()
{
    FILE *fptr1, *fptr2;
    char filename1[] = "writefile.txt";
    char filename2[] = "readfile.txt";
    int reval = SUCCESS;
    if((fptr1 = fopen(filename1,"w+")) == NULL)
      {
          printf("khong the mo file %s\n", filename1);
          reval = FAIL;
      }
    else if((fptr2 = fopen(filename2, "r+")) == NULL)
    {
        printf("khong the mo file %s\n", filename2);
        reval == FAIL;
    }
    else
    {
        blockreadwrite(fptr2, fptr1);
        fclose(fptr1);
        fclose(fptr2);
    }
    return reval;
}
void blockreadwrite(FILE *fin,FILE *fout)
{
    int num ;
    char buff[MAX_LEN + 1];
    num = fread(buff, sizeof(char), MAX_LEN,fin);
    buff[num * sizeof(char)] = '\0';
    printf("%s", buff);
    fwrite(buff, sizeof(char), num , fout);
}