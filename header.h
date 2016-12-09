#include<stdio.h>
#include<string.h>
#define  SPACE printf("                           ");
typedef struct student_data
{
	int no;
	char name[20];
	char sex[6];
	char dept[50];
	int age;
	int score;
}stu_data;
typedef struct student
{
	stu_data *data;
	struct student *next;
}stu;

typedef struct {
	int Cno;
	char Cname[60];
	int Credit;
}course_data;
typedef struct Course{
	course_data *data;
	struct Course *next;
}course;

typedef struct {
	int Sno;
	int Cno;
	int gread;
}SC_data;
typedef struct SC{
	SC_data *data;
	struct SC *next;
}student_course;

typedef struct a{
	char type[50];
	char type_1[50];
	char type_3[50];
	int type_num;
	int type_num_1;
	int type_num_2;
	int count;
	float type_float;
	struct a *next;
}COUNT;



typedef struct Revise
{
	stu *p_data;
	struct Revise *next;
}REVISE;

void menu(stu *head,course *C_head,student_course *SC_head);


stu *create_new();
stu *create_open();
course *open_course();
stu* add(stu *head, stu *pnew, int choose);
stu *del(stu *head,int no);


stu *revise(stu *head,course *C_head,student_course *SC_head);
stu *revise_no(stu *head);
stu *revise_name(stu *head);
stu *revise_age(stu *head);
stu *revise_dept(stu *head);
stu *revise_crore(stu *head);
stu *revise_sex(stu *head);

void search(stu *head, course* C_head, student_course *SC_head);
int found_sum(stu *head);
void output_found_num(int n);
void output_found_linklist(COUNT *head);
COUNT *found_sex(stu*head);
REVISE *found_by_no(stu* head,int no);
int found_by_firstname(stu *head, char *name);
stu *age_add(stu *head,char *name);
COUNT *found_dept(stu *head);
COUNT *found_age(stu *head);
REVISE *found_max_age(stu* head);


void free_linklist(stu *head);
void free_revise_linklist(REVISE *head);
void savefile(head);
void output_linklist(stu* head);
void output_revise_linklist(REVISE *head);
void output_found_linklist_num(COUNT *head);


course *create_course();
void save_course(course *head);
void output_course(course *head);


student_course *create_sc();
void save_student_course(student_course *head);
void output_student_course(student_course *head);
COUNT *count_average(stu *head);
void output_count_score(COUNT *head);

COUNT *count_course_num(course *head,student_course* SC_head);
void output_ccn(COUNT *head);