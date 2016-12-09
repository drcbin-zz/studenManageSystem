#include"myheader.h"
STU* infor_login_menu(STU *head)
{
	int judge=NO;
	char infor_login_choose;
	while (1)
	{
		system("cls");
		puts("1、手动录入学生信息\n"
			"2、批量导入文件信息\n"
			"0、返回\n");
		puts("请选择：");
		infor_login_choose = getch();
		switch (infor_login_choose)
		{
		case '1':head = create_stu_infor_linklist(); break;
		case '2':{
			head = open_stu_linklist();
			if (head)
			{
				MessageBox(hWnd, _T("导入成功！"), _T("提示"), MB_OK);
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

