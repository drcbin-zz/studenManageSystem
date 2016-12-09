#include"header.h"
void search(stu *head,course* C_head,student_course *SC_head)
{
	if (head == NULL)
	{
		puts("No student!");
		system("pause");
		return head;
	}
	int choose;
	while (1)
	{
		output_linklist(head);
		puts("1、查询学生人数");
		puts("2、查询男女生各人数");
		puts("3、按学号查询学生全部信息");
		puts("4、按姓氏查询学生人数");
		puts("5、将某学生年龄加一");
		puts("6、查询每个系人数各是多少");
		puts("7、查询每个年龄对应的人数分别是多少");
		puts("8、查询与女生最大年龄相同的男生的信息");
		puts("9、查询男女生平均成绩各是多少");
		puts("10、统计每个课程的选课人数");
		puts("0、返回上一级菜单");
		int n = 0;
		scanf("%d", &choose); getchar();
		switch (choose)
		{
		case 1: {
			n = found_sum(head);
			output_found_num(n); 
			break;
		}
		case 2:
		{
			REVISE *head_found_sex=found_sex(head);
			output_found_linklist(head_found_sex);
			break;
		}
		case 3: {
			int no;
			printf("please input no:");
			scanf("%d", &no); getchar();
			REVISE *student_linklist = found_by_no(head,no);
			output_revise_linklist(student_linklist);
			break;
		}
		case 4: {
			char firstname[20];
			printf("please input fristname:");
			gets(firstname);
			int n = found_by_firstname(head,firstname);
			system("cls");
			printf("姓%s的人数为：%d个.",firstname,n);
			system("pause");
			break;
		}
		case 5: {
			char name[20];
			printf("please input the name:");
			gets(name);
			head = age_add(head,name);
			output_linklist(head);
			break;
		}
		case 6: {
			COUNT *head_dept = found_dept(head);
			output_found_linklist(head_dept);
			break;
		}
		case 7: {
			COUNT *head_age = found_age(head);
			output_found_linklist_num(head_age);
			break;
		}
		case 8: {
			REVISE *head_max_age = found_max_age(head);
			output_revise_linklist(head_max_age);
			break;
		}
		case 9: {
			COUNT *head_average = count_average(head);
			output_count_score(head_average);
			break;
		}
		case 10: {
			COUNT *ccn_head = count_course_num(C_head, SC_head);
			output_ccn(ccn_head);
			break;
		}
		case 0:menu(head,C_head,SC_head);
		}
	}
}