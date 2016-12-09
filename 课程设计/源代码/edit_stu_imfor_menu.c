#include"myheader.h"
STU* edit_stu_infor_menu(STU* head)
{

	char edit_choose;
	while (1)
	{
		system("cls");
		puts("1������ѧ��\n"
			"2��ɾ��ѧ��\n"
			"3���޸�ѧ����Ϣ\n"
			"0������\n");
		puts("��ѡ��");
		edit_choose = getch();
		switch (edit_choose)
		{
		case '1': {
			STU *NewHead;
			if (head == NULL)
			{
				if ((MessageBox(hWnd, _T("������ӻ����ԭ�����е����ݣ��Ƿ������"), _T("��ʾ"), MB_YESNOCANCEL)) != 6)
				{
					break;
				}
			}
			NewHead = add_stu_linklist(head);
			if ((MessageBox(hWnd, _T("ȷ����ӣ�"), _T("��ʾ"), MB_YESNO)) == 6)
			{
				head = add_student(head, NewHead);
			}
			break;
		}
		case '2': {
			int num;
			puts("��������Ҫɾ����ѧ�ţ�");
			while (!scanf("%d", &num) || num < 0)
			{
				MessageBox(hWnd, _T("����������������룡"), _T("��ʾ"), NULL);
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
		MessageBox(hWnd, _T("û��ѧ����Ϣ,����¼�룡"), _T("��ʾ"), NULL);
		return NULL;
	}
	if (head->stu_data.num == num)
	{
		if ((MessageBox(hWnd, _T("ȷ��ɾ����"), _T("����"), MB_YESNOCANCEL)) == 6)
		{
			head = head->next;
			free(head->last);
			head->last = NULL;
			MessageBox(hWnd, _T("ɾ���ɹ���"), _T("��ʾ"), NULL);
		}
		return head;
	}
	STU *p = head;
	while (p)
	{
		if (p->stu_data.num == num)
		{
			if ((MessageBox(hWnd, _T("ȷ��ɾ����"), _T("����"), MB_YESNOCANCEL)) == 6) {
				if (p->next == NULL)
				{
					p->last->next = NULL;
				}
				else {
					p->next->last = p->last;
					p->last->next = p->next;
				}
				free(p);
				MessageBox(hWnd, _T("ɾ���ɹ���"), _T("��ʾ"), NULL);
				return head;
			}
		}
		p = p->next;
	}
	MessageBox(hWnd, _T("�Ҳ���������"), _T("��ʾ"), NULL);
	return head;
}

STU* revise_stu_infor(STU* head)
{
	puts("revise_stu_infor");
	system("pause");
}