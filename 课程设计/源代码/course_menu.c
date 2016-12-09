#include"myheader.h"
void course_menu(STU* head)
{
	if (head == NULL)
	{
		MessageBox(hWnd, _T("真是没有学生信息，请先添加学生！"), _T("提示"), NULL);
		return 0;
	}
	char subject[10];
	char course_choose;
	while (1)
	{
		system("cls");
		puts("1、语文\n"
			"2、数学\n"
			"3、英语\n"
			"0、返回\n");
		puts("请选择：");
		course_choose = getch();
		switch (course_choose)
		{
		case '1':strcpy(subject,"chinese"); lookover_course_infor(head, subject); break;
		case '2':strcpy(subject, "math"); lookover_course_infor(head, subject); break;
		case '3':strcpy(subject, "english"); lookover_course_infor(head, subject); break;
		case '0': return 0;
		}
	}
}
