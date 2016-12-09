#include"myheader.h"
void main_menu()
{
	STU *head=NULL;
	while (1)
	{
		system("cls");
		puts("1、录入学生信息。\n"
			"2、查看学生信息。\n"
			"3、编辑学生信息。\n"
			"4、教师实用功能。\n"
			"0、退出。\n");
		char main_choose;
		main_choose = getch();
		switch (main_choose)
		{
		case '1':head=infor_login_menu(head); break;
		case '2':look_over_stu_infor_menu(head); break;
		case '3':head=edit_stu_infor_menu(head); break;
		case '4':teacher_menu(head); break;
		case '0':
		{
			system("cls");
			puts("欢迎再次使用...");
			Sleep(500);
			exit(0);
		}
		}
	}
}