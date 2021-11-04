#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student_t
{
	char id[20];
	char name[30];
	int grade;
	struct student_t *next; 
} ;
struct student_t *head;
void input()
{
	struct student_t *cur;
	int i , n;
	struct student_t student;
	printf("nhap so luong sinh vien ban them vao : ");
	scanf("%d", &n);
	head = (struct student_t *)malloc(sizeof(struct student_t));
	cur = head;
	head->next = NULL; 
	for(i = 1 ; i <= n ; i++)
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
		if(i == 1)
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
} 
void print()
{
	printf("danh sach sinh vien : \n");
	struct student_t *cur;
	cur = head;
	while(cur != NULL)
	{
		printf("%-19s%-11s%-3d \n", cur->name, cur->id, cur->grade);
		cur = cur->next;
	};
}
void sap_xep_diem()
{
	struct student_t *t1, *t2;
	for(t1 = head; t1 != NULL; t1 = t1->next)
	{
		for(t2 = t1->next; t2 != NULL ; t2 = t2->next)
		{
			if(t1->grade <= t2->grade)
			{ 
			  char tmp_id[20];  // tao 1 bien trung gian cua id
			  strcpy(tmp_id, t1->id); // doi id cho 2 con tro  
			  strcpy(t1->id, t2->id);
			  strcpy(t2->id, tmp_id);
			  char tmp_name[30];           // doi name  
			  strcpy(tmp_name, t1->name);
			  strcpy(t1->name, t2->name);
			  strcpy(t2->name, tmp_name); 
			  int diem;              // doi diem  
			  diem = t1->grade;
			  t1->grade = t2->grade;
			  t2->grade = diem; 
		    }
			 
		} 
	} 
}
void chen()
{
	printf("\n nhap thong tin cho nut moi : \n");
	struct student_t *them;
	them = (struct student_t *)malloc(sizeof(struct student_t)); 
	printf("nhap ten : ");
	fflush(stdin);
	gets(them->name);
	printf("nhap mssv : ");
	fflush(stdin);
	gets(them->id);
	printf("nhap diem : ");
	scanf("%d", &them->grade);
	them->next = NULL;
	struct student_t *cur;  // tao 1 con tro tim vi tri thich hop  
	cur = head;
	if(cur->grade <= them->grade)   // neu them vao lon nhat 
	{
			them->next = cur;
			head = them;   
	}
	else                      // o giua  
	{ 
	   for(cur = head;cur->next != NULL ; cur = cur->next)
	   {
		  if(cur->next->grade <= them->grade)
		  {
			them->next = cur->next;
			cur->next = them; 
			break; 
		  } 
	   }
	   if(cur->next == NULL)  // neu be nhat 
	   cur->next = them; 
   }
}
struct student_t *tim_kiem(char s[])    // tim kiem 1 hoc sinh qua mssv tra ve 1 con tro 
{
	struct student_t *cur;
    cur = head; 
	while(cur != NULL)
	{
		if(strcmp(s,cur->id) == 0)
			return cur; 
		else
		cur=cur->next; 
	}
	return cur; 
}
void xoa(char s[])
{
	struct student_t *cur;
	cur = head ; 
	while(cur != NULL)
	{
		if(strcmp(s,cur->id) == 0)
		{
			if(cur == head)
				head = head->next; 
			else
			{
				struct student_t *tmp; // tao 1 con tro tro vao sau cur
				tmp = head; 
				while(tmp->next != cur)
				 tmp = tmp->next;     // tmp->next = cur 
				tmp->next = cur->next;   
			} 
		}
	    cur = cur->next; 
    }
} 
int main ()
{
    input();
    print();
    sap_xep_diem();
	int chon;
	while(1)
	{
		system("cls");
		printf("chuong trinh co cac chuc nang sau : \n");
		printf("1. them 1 new student in vao dung vi tri trong bang diem \n");
		printf("2. tim 1 student qua MSSV \n");
		printf("3. xoa 1 student qua MSSV \n");
		printf("4. in ra danh sach \n");
		printf("5. thoat chuong trinh \n"); 
		printf("**********************************\n");
		printf("nhap chuc nang ban muon : ");
		scanf("%d", &chon);
		switch(chon)
		{
			case 1 : 
			    printf("chuc nang them 1 sinh vien : \n");
			    chen();
			    break;
			case 2 : 
			    printf("chuc nang tim 1 sinh vien : \n");
				char s[30];
	            printf("nhap mssv cua sinh vien can tim : ");
	            fflush(stdin);
	            gets(s);
	            struct student_t *a;
	            a = tim_kiem(s);
	            printf("thong tin sinh vien tim duoc : \n");
	            if(a != NULL) 
	               printf("%-19s%-11s%-3d \n", a->name, a->id, a->grade);
	            else
	               printf("khong tim thay sinh vien yeu cau ! \n");
	            getch();
				break;
			case 3 : 
			       printf("chuc nang xoa 1 sinh vien : \n");
				   printf("nhap MSSV muon xoa : \n");
	               char s_xoa[30]; 
	               fflush(stdin);
	               gets(s_xoa);
	               xoa(s_xoa);
				   break;
			case 4 : 
			       print();
			       getch();
			       break;
			case 5 :
			       printf("thoat chuong trinh !");
				   return ;
		    default :
		    	  printf("khong ton tai chuc nang nay !\n");
				  getch();
				  break; 
		} 
	}  
	return 0;	 	
} 
























