#include"myheader.h"
void teacher_menu(STU *head)
{
	char teacher_choose;
	while (1)
	{
		system("cls");
		puts("1�����Ƴɼ������Ϣ\n"
			"2��ѧ��ѡ����Ϣ\n"
			"0������\n");
		puts("��ѡ��");
		teacher_choose = getch();
		switch (teacher_choose)
		{
		case '1':course_menu(head); break;
		case '2':subject_choose_menu(head); break;
		case '0':return 0;
		}
	}
}