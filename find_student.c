#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student_t
{
	char id[20];
	char name[30];
	int grade;
	struct student_t *next; 
};
struct student_t *find_student (struct student_t *root, char s[])
{
	struct student_t *tmp;
	tmp = root;
	for(tmp = root; tmp != NULL ; tmp = tmp->next)
		if(strcmp(tmp->id, s) == 0)    // neu trung
			return tmp;
	return 0;
}
int main ()
{
	struct student_t *head;
	struct student_t *cur;
	int i , n;
	struct student_t student;
	printf("nhap so luong sinh vien ban them vao : ");
	scanf("%d", &n);
	head = (struct student_t *)malloc(sizeof(struct student_t));
	cur = head;
	head->next = NULL; 
	for(i = 1 ; i <= n ; i++)     // nhap list
	{
		struct student_t *tmp;
		tmp = (struct student_t *)malloc(sizeof(struct student_t));
		printf("nhap du lieu cho sinh vien thu %d : \n", i);
		printf("nhap ten : ");
		fflush(stdin);
		gets(student.name);
		printf("nhap mssv : ");
		fflush(stdin);
		gets(student.id);
		printf("nhap diem  : ");
		scanf("%d", &student.grade); 
	    strcpy(tmp->name,student.name);
		strcpy(tmp->id,student.id);
		tmp->grade = student.grade;
		tmp->next = NULL;
		if(i == 1)        // con tro o dau
		{
			head = tmp;
			cur = head;
		}
		else
		{
			cur->next = tmp;
			cur = cur->next;
		}
	}
    char s[30];
	printf("\n nhap MSSV ban muon tim : ");
	fflush(stdin);
	gets(s);
	struct student_t *a;
	a = find_student(head,s);
	if(a != NULL)
	{
	  printf("tim thay sinh vien : \n");
	  printf("%-19s%-11s%-3d \n", a->name, a->id, a->grade);
    }
    else
    printf("khong tim thay ! ");
    return 0;
}































