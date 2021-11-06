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
struct student_t *change_grade(struct student_t *root, char s[])
{
	struct student_t *tmp;
	tmp = root;
	for(tmp = root; tmp != NULL ; tmp = tmp->next)
		if(strcmp(tmp->id, s) == 0)    // neu trung
			{
				struct student_t *new;
				new = (struct student_t*)malloc(sizeof(struct student_t));
				strcpy(new->name, tmp->name);
				strcpy(new->id, tmp->id);
				// int new_grade;
				printf("nhap diem moi : ");
				scanf("%d", &new->grade);
				new->next = NULL;
				if(tmp == root)
				{
					new->next = root->next;
					root = new;
					return root;
				}
				else
				{
					struct student_t *a;
					a= root;
					while(a->next != tmp)  // a->new == tmp
					   a = a->next;       
					new->next = tmp->next;
					a->next = new;
					return root;
				}
			break;
			}
	if(tmp == NULL)
	printf("khong tim thay !");
	return root;
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
	printf("\n nhap MSSV ban muon sua diem : ");
	fflush(stdin);
	gets(s);
	head = change_grade(head,s);
	printf("danh sach sinh vien : \n");
	cur = head;
	while(cur != NULL)
	{
		printf("%-19s%-11s%-3d \n", cur->name, cur->id, cur->grade);
		cur = cur->next;
	};
	return 0;
}


















