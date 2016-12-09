#include<stdio.h>
#include<Windows.h>
#include<WinUser.h>
#include<tchar.h>
#include<conio.h>
#define AGE_WARING age_waring()
#define GRADE_WARING grade_waring()
#define SaveOrNo saveorno()
#define YES 1
#define NO 0
#define CANCEL 2
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define F1 59
typedef struct _grade
{
	int chinese;
	int math;
	int english;
}GRADE;
typedef struct _student_data
{
	int num;
	int age;
	char name[20];
	char sex[5];
	GRADE grade;
}STU_DATA;

typedef struct _student
{
	STU_DATA stu_data;
	struct _student *next, *last;
}STU;
HWND hWnd;

void _fflush();
#define FFLUSH  _fflush() 
#define SPACE printf("                    ")

/***************************************/
/*各种函数签名                           */

void demand_stu_infor_menu();
void main_menu();
int return_menu1(STU* head);
int return_menu(STU* head);

void age_waring();
void grade_waring();
int judge_repeat(STU* head, int num);
int judge_Oldrepeat(STU* head, int num);



/*录入学生信息*/
STU* open_stu_linklist();
STU* infor_login_menu(STU *head);
STU* create_stu_infor_linklist();
STU* batch_import_menu();
void batch_add_stu();
void save_stu_infor(STU *head, FILE *fp);
int input();


/*查看学生信息*/
void look_over_stu_infor_menu(STU *head);
STU* number_sort(STU* head);
STU* age_sort(STU* head);
STU* name_sort(STU* head);
STU* sex_sort(STU* head);
STU* grade_sort(STU* head);
STU* chinese_sort(STU* head);
STU* math_sort(STU* head);
STU* english_sort(STU* head);
void save_stu_infor();
void print_stu_infor(STU* head);
STU *FindLastPageHead(STU* PageHead);
STU* FindNextPageHead(STU* PageHead);
int judge_FinalPage(STU *PageHead);
int judge_FirstPage(STU *PageHead);
int input();

/*编辑学生信息*/
STU* edit_stu_infor_menu(STU* head);
STU* add_student(STU* head,STU* NewHead);
STU *del_student(STU* head,int num);
STU* revise_stu_infor(STU* head);
STU* add_stu_linklist(STU *head);

/*教师助手*/
void teacher_menu(STU *head);
void subject_choose_menu(STU *head);
void course_menu(STU* head);
float lookover_course_infor(STU *head,char *subject);
int countWomanNum(STU *head);
int countManNum(STU *head);
float passRate(STU  *head,char *subject);
int max_grade(STU *head,char *subject);
//void excellent_rate();
int grade_part(STU *head,char *subject,int grade1,int grade2);
void ranking();
float Average(STU *head, char *subject);
int countPersonNum(STU *head);
