#include"myheader.h"
void course_menu(STU* head)
{
	if (head == NULL)
	{
		MessageBox(hWnd, _T("����û��ѧ����Ϣ���������ѧ����"), _T("��ʾ"), NULL);
		return 0;
	}
	char subject[10];
	char course_choose;
	while (1)
	{
		system("cls");
		puts("1������\n"
			"2����ѧ\n"
			"3��Ӣ��\n"
			"0������\n");
		puts("��ѡ��");
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
