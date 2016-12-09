#include"myheader.h"
void teacher_menu(STU *head)
{
	char teacher_choose;
	while (1)
	{
		system("cls");
		puts("1、各科成绩相关信息\n"
			"2、学生选课信息\n"
			"0、返回\n");
		puts("请选择：");
		teacher_choose = getch();
		switch (teacher_choose)
		{
		case '1':course_menu(head); break;
		case '2':subject_choose_menu(head); break;
		case '0':return 0;
		}
	}
}