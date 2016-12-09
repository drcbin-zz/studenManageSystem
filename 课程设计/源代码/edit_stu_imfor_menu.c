#include"myheader.h"
STU* edit_stu_infor_menu(STU* head)
{

	char edit_choose;
	while (1)
	{
		system("cls");
		puts("1、增加学生\n"
			"2、删除学生\n"
			"3、修改学生信息\n"
			"0、返回\n");
		puts("请选择：");
		edit_choose = getch();
		switch (edit_choose)
		{
		case '1': {
			STU *NewHead;
			if (head == NULL)
			{
				if ((MessageBox(hWnd, _T("现在添加会清除原磁盘中的数据，是否继续？"), _T("提示"), MB_YESNOCANCEL)) != 6)
				{
					break;
				}
			}
			NewHead = add_stu_linklist(head);
			if ((MessageBox(hWnd, _T("确认添加？"), _T("提示"), MB_YESNO)) == 6)
			{
				head = add_student(head, NewHead);
			}
			break;
		}
		case '2': {
			int num;
			puts("请输入你要删除的学号：");
			while (!scanf("%d", &num) || num < 0)
			{
				MessageBox(hWnd, _T("输入错误，请重新输入！"), _T("提示"), NULL);
				FFLUSH;
			}
			FFLUSH;
			head = del_student(head, num); break;
		}
		case '3': {
			revise_stu_infor(head); break;
		}
		case '0': {
			if (head == NULL)return NULL;
			if (return_menu1(head) == YES)
			{
				return head;
			}
			else {
				head = open_stu_linklist();
				return head;
			}
		}
		}
	}
}

STU* add_student(STU* head, STU* NewHead)
{
	if (head == NULL)
	{
		return NewHead;
	}
	STU *p = head;
	while (p->next)
	{
		p = p->next;
	}
	p->next = NewHead;
	NewHead->last = p;
	return head;
}
STU* del_student(STU* head, int num)
{
	if (head == NULL)
	{
		MessageBox(hWnd, _T("没有学生信息,请先录入！"), _T("提示"), NULL);
		return NULL;
	}
	if (head->stu_data.num == num)
	{
		if ((MessageBox(hWnd, _T("确认删除？"), _T("警告"), MB_YESNOCANCEL)) == 6)
		{
			head = head->next;
			free(head->last);
			head->last = NULL;
			MessageBox(hWnd, _T("删除成功！"), _T("提示"), NULL);
		}
		return head;
	}
	STU *p = head;
	while (p)
	{
		if (p->stu_data.num == num)
		{
			if ((MessageBox(hWnd, _T("确认删除？"), _T("警告"), MB_YESNOCANCEL)) == 6) {
				if (p->next == NULL)
				{
					p->last->next = NULL;
				}
				else {
					p->next->last = p->last;
					p->last->next = p->next;
				}
				free(p);
				MessageBox(hWnd, _T("删除成功！"), _T("提示"), NULL);
				return head;
			}
		}
		p = p->next;
	}
	MessageBox(hWnd, _T("找不到该生。"), _T("提示"), NULL);
	return head;
}

STU* revise_stu_infor(STU* head)
{
	puts("revise_stu_infor");
	system("pause");
}