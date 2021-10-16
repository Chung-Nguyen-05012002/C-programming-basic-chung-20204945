#include<stdio.h>
#include<stdlib.h>
#include<string.h>
enum {SUCCESS , FAIL , MAX_ELEMENT = 20};
// the phone book structure
typedef struct phoneaddress_t
{
    char name[20];
    char tell[11];
    char email[25];
}phoneaddress;
int main ()
{
    FILE *fp;
    phoneaddress phonearr[MAX_ELEMENT];
    int i , n , irc ;
    int reval = SUCCESS;
    printf("how many contacts do you want to enter (<20) : ");
    scanf("%d", &n);
    for(i = 0 ; i < n ; i++)
    {
        printf("name:"); 
        scanf("%s",phonearr[i].name);
        phonearr[i].name[strlen(phonearr[i].name)] = '\0';
        printf("tel:");
        scanf("%s",phonearr[i].tell);
        printf("email:"); 
        scanf("%s",phonearr[i].email);
    };
    if((fp = fopen("phonebook.dat", "w+b")) == NULL)
    {
        printf("khong the mo  tep %s. \n", "phonebook.txt");
        reval = FAIL;
    }
    //write the entire array into the file
    irc = fwrite(phonearr, sizeof(phoneaddress), n , fp);
    printf("fwrite return code = %d \n", irc);
    fclose(fp);
    // read from thi file to array again
    if((fp = fopen("phonebook.dat", "r+b")) == NULL)
    {
       printf("cannot open %s.\n", "phonebook.dat");
       reval = FAIL;      
    }
    irc = fread(phonearr, sizeof(phoneaddress), n , fp);
    printf("fread return code = %d\n" , irc);
    for( i = 0 ; i < n ; i++)
    {
        printf("%s-", phonearr[i].name);
        printf("%s-", phonearr[i].tell);
        printf("%s\n", phonearr[i].email);
    }
    fclose (fp);
    return 0; 
}










