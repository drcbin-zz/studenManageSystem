#include"myheader.h"
STU* infor_login_menu(STU *head)
{
	int judge=NO;
	char infor_login_choose;
	while (1)
	{
		system("cls");
		puts("1���ֶ�¼��ѧ����Ϣ\n"
			"2�����������ļ���Ϣ\n"
			"0������\n");
		puts("��ѡ��");
		infor_login_choose = getch();
		switch (infor_login_choose)
		{
		case '1':head = create_stu_infor_linklist(); break;
		case '2':{
			head = open_stu_linklist();
			if (head)
			{
				MessageBox(hWnd, _T("����ɹ���"), _T("��ʾ"), MB_OK);
			}
			return head;
		}
		case '0':
		{
			if (head == NULL)return NULL;
			judge = return_menu1(head);
			if (judge==YES)
			{
				return head;
			}
			if (judge == NO)
			{
				return NULL;
			}
			else 
			{
				continue;
			}
		}
		}
	}
}

