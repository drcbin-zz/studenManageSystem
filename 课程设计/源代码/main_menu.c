#include"myheader.h"
void main_menu()
{
	STU *head=NULL;
	while (1)
	{
		system("cls");
		puts("1��¼��ѧ����Ϣ��\n"
			"2���鿴ѧ����Ϣ��\n"
			"3���༭ѧ����Ϣ��\n"
			"4����ʦʵ�ù��ܡ�\n"
			"0���˳���\n");
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
			puts("��ӭ�ٴ�ʹ��...");
			Sleep(500);
			exit(0);
		}
		}
	}
}