#include"myheader.h"
void look_over_stu_infor_menu(STU *head)
{
	char look_over_choose;
	while (1)
	{
		system("cls");
		puts(
			"1、按学号排序\n"
			"2、按年龄排序\n"
			"3、按姓名排序\n"
			"4、按性别排序\n"
			"5、按成绩排序\n"
			"6、按录入顺序\n"
			"0、返回\n"
			);
		puts("请选择排序方式：");
		look_over_choose = getch();
		switch (look_over_choose)
		{
		case '1':head = number_sort(head);
			    print_stu_infor(head); break;
		case '2':head=age_sort(head); print_stu_infor(head); break;
		case '3':head=name_sort(head); print_stu_infor(head); break;
		case '4':head=sex_sort(head); print_stu_infor(head); break;
		case '5':head=grade_sort(head); print_stu_infor(head); break;
		case '6':print_stu_infor(head); break;
		case '0':return head;
		}
	}
}