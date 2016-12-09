#include"myheader.h"
STU* number_sort(STU*head)
{
	if (head == NULL)
	{
		MessageBox(hWnd,_T("��û���κ�ѧ����Ϣ�أ�"),_T("��ʾ"),MB_OK);
		return NULL;
	}
	STU  *p,*mark;
	int judge = NO;
	p = head;
	while (p->next)   //Ѱ�����һ��
	{
		p = p->next;
	}
	mark = p;
	while (mark != head)  //ð������
	{
		judge = NO;
		p = head;//
		while (p != mark)
		{
				if (p->stu_data.num > p->next->stu_data.num)
				{
					if (p->next == mark)judge = YES;
					if (p == head)
					{
						if (p->next->next == NULL)
						{
							head = p->next;
							head->last = NULL;
							head->next = p;
							p->last = head;
							p->next = NULL;
							if (judge == YES)
							{
								judge = 3;
								break;
							}
							continue;
						}
						head = p->next;
						head->last = NULL;
						p->last = head;
						head->next->last = p;
						p->next = head->next;
						head->next = p;
						if (judge==YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
					else {
						if (p->next->next == NULL)
						{
							p->next->last = p->last;
							p->next->next = p;
							p->last->next = p->next;
							p->last = p->next;
							p->next = NULL;
							if (judge==YES)
							{
								judge = 3;
								break;
							}
							continue;
						}
						else {
							STU* temp = p->next->next;
							p->last->next = p->next;
							p->next->last = p->last;
							temp->last = p;
							p->next->next = p;
							p->last = p->next;
							p->next = temp;
							if (judge==YES)
							{
								judge = 3;
								break;
							}
							continue;
						}
					}
			}
			p = p->next;
		}
		if (judge == 3)continue;
		mark = mark->last;
	}
	return head;
}

STU* age_sort(STU* head)
{
	if (head == NULL)
	{
		MessageBox(hWnd, _T("��û���κ�ѧ����Ϣ�أ�"), _T("��ʾ"), MB_OK);
		return NULL;
	}
	STU  *p, *mark;
	int judge = NO;
	p = head;
	while (p->next)   //Ѱ�����һ��
	{
		p = p->next;
	}
	mark = p;
	while (mark != head)  //ð������
	{
		judge = NO;
		p = head;//
		while (p != mark)
		{
			if (p->stu_data.age < p->next->stu_data.age)
			{
				if (p->next == mark)judge = YES;
				if (p == head)
				{
					if (p->next->next == NULL)
					{
						head = p->next;
						head->last = NULL;
						head->next = p;
						p->last = head;
						p->next = NULL;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
					head = p->next;
					head->last = NULL;
					p->last = head;
					head->next->last = p;
					p->next = head->next;
					head->next = p;
					if (judge == YES)
					{
						judge = 3;
						break;
					}
					continue;
				}
				else {
					if (p->next->next == NULL)
					{
						p->next->last = p->last;
						p->next->next = p;
						p->last->next = p->next;
						p->last = p->next;
						p->next = NULL;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
					else {
						STU* temp = p->next->next;
						p->last->next = p->next;
						p->next->last = p->last;
						temp->last = p;
						p->next->next = p;
						p->last = p->next;
						p->next = temp;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
				}
			}
			p = p->next;
		}
		if (judge == 3)continue;
		mark = mark->last;
	}
	return head;
}
STU* sex_sort(STU* head)
{
	if (head == NULL)
	{
		MessageBox(hWnd, _T("��û���κ�ѧ����Ϣ�أ�"), _T("��ʾ"), MB_OK);
		return NULL;
	}
	STU  *p, *mark;
	int judge = NO;
	p = head;
	while (p->next)   //Ѱ�����һ��
	{
		p = p->next;
	}
	mark = p;
	while (mark != head)  //ð������
	{
		judge = NO;
		p = head;//
		while (p != mark)
		{
			if ((strcmp(p->stu_data.sex,p->next->stu_data.sex))>1)
			{
				if (p->next == mark)judge = YES;
				if (p == head)
				{
					if (p->next->next == NULL)
					{
						head = p->next;
						head->last = NULL;
						head->next = p;
						p->last = head;
						p->next = NULL;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
					head = p->next;
					head->last = NULL;
					p->last = head;
					head->next->last = p;
					p->next = head->next;
					head->next = p;
					if (judge == YES)
					{
						judge = 3;
						break;
					}
					continue;
				}
				else {
					if (p->next->next == NULL)
					{
						p->next->last = p->last;
						p->next->next = p;
						p->last->next = p->next;
						p->last = p->next;
						p->next = NULL;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
					else {
						STU* temp = p->next->next;
						p->last->next = p->next;
						p->next->last = p->last;
						temp->last = p;
						p->next->next = p;
						p->last = p->next;
						p->next = temp;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
				}
			}
			p = p->next;
		}
		if (judge == 3)continue;
		mark = mark->last;
	}
	return head;
}

STU* name_sort(STU* head)
{
	if (head == NULL)
	{
		MessageBox(hWnd, _T("��û���κ�ѧ����Ϣ�أ�"), _T("��ʾ"), MB_OK);
		return NULL;
	}
	STU  *p, *mark;
	int judge = NO;
	p = head;
	while (p->next)   //Ѱ�����һ��
	{
		p = p->next;
	}
	mark = p;
	while (mark != head)  //ð������
	{
		judge = NO;
		p = head;//
		while (p != mark)
		{
			if ((strcmp(p->stu_data.name, p->next->stu_data.name))>1)
			{
				if (p->next == mark || p->next == NULL)judge = YES;
				if (p == head)
				{

					if (p->next->next == NULL)
					{
						head = p->next;
						head->last = NULL;
						head->next = p;
						p->last = head;
						p->next = NULL;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
					head = p->next;
					head->last = NULL;
					p->last = head;
					head->next->last = p;
					p->next = head->next;
					head->next = p;
					if (judge == YES)
					{
						judge = 3;
						break;
					}
					continue;
				}
				else {
					if (p->next->next == NULL)
					{
						p->next->last = p->last;
						p->next->next = p;
						p->last->next = p->next;
						p->last = p->next;
						p->next = NULL;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
					else {
						STU* temp = p->next->next;
						p->last->next = p->next;
						p->next->last = p->last;
						temp->last = p;
						p->next->next = p;
						p->last = p->next;
						p->next = temp;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
				}
			}
			p = p->next;
		}
		if (judge == 3)continue;
		mark = mark->last;
		p = head;
	}
	return head;
}
STU* grade_sort(STU* head)
{
	char subject_choose;
	while (1)
	{
		system("cls");
		puts("1�������ĳɼ���������\n"
			"2������ѧ�ɼ���������\n"
			"3����Ӣ��ɼ���������\n"
			"0������\n");
		puts("��ѡ��");
		subject_choose = getch();
		switch (subject_choose)
		{
		case '1':head=chinese_sort(head); return head;;
		case '2':head=math_sort(head); return head;
		case '3':head=english_sort(head); return head;
		case '0':return NULL;
		}
	}
}



STU* chinese_sort(STU* head)
{
	if (head == NULL)
	{
		MessageBox(hWnd, _T("��û���κ�ѧ����Ϣ�أ�"), _T("��ʾ"), MB_OK);
		return NULL;
	}
	STU  *p, *mark;
	int judge = NO;
	p = head;
	while (p->next)   //Ѱ�����һ��
	{
		p = p->next;
	}
	mark = p;
	while (mark != head)  //ð������
	{
		judge = NO;
		p = head;//
		while (p != mark)
		{
			if (p->stu_data.grade.chinese < p->next->stu_data.grade.chinese)
			{
				if (p->next == mark)judge = YES;
				if (p == head)
				{
					if (p->next->next == NULL)
					{
						head = p->next;
						head->last = NULL;
						head->next = p;
						p->last = head;
						p->next = NULL;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
					head = p->next;
					head->last = NULL;
					p->last = head;
					head->next->last = p;
					p->next = head->next;
					head->next = p;
					if (judge == YES)
					{
						judge = 3;
						break;
					}
					continue;
				}
				else {
					if (p->next->next == NULL)
					{
						p->next->last = p->last;
						p->next->next = p;
						p->last->next = p->next;
						p->last = p->next;
						p->next = NULL;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
					else {
						STU* temp = p->next->next;
						p->last->next = p->next;
						p->next->last = p->last;
						temp->last = p;
						p->next->next = p;
						p->last = p->next;
						p->next = temp;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
				}
			}
			p = p->next;
		}
		if (judge == 3)continue;
		mark = mark->last;
	}
	return head;
}
STU* math_sort(STU* head)
{
	if (head == NULL)
	{
		MessageBox(hWnd, _T("��û���κ�ѧ����Ϣ�أ�"), _T("��ʾ"), MB_OK);
		return NULL;
	}
	STU  *p, *mark;
	int judge = NO;
	p = head;
	while (p->next)   //Ѱ�����һ��
	{
		p = p->next;
	}
	mark = p;
	while (mark != head)  //ð������
	{
		judge = NO;
		p = head;//
		while (p != mark)
		{
			if (p->stu_data.grade.math < p->next->stu_data.grade.math)
			{
				if (p->next == mark)judge = YES;
				if (p == head)
				{
					if (p->next->next == NULL)
					{
						head = p->next;
						head->last = NULL;
						head->next = p;
						p->last = head;
						p->next = NULL;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
					head = p->next;
					head->last = NULL;
					p->last = head;
					head->next->last = p;
					p->next = head->next;
					head->next = p;
					if (judge == YES)
					{
						judge = 3;
						break;
					}
					continue;
				}
				else {
					if (p->next->next == NULL)
					{
						p->next->last = p->last;
						p->next->next = p;
						p->last->next = p->next;
						p->last = p->next;
						p->next = NULL;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
					else {
						STU* temp = p->next->next;
						p->last->next = p->next;
						p->next->last = p->last;
						temp->last = p;
						p->next->next = p;
						p->last = p->next;
						p->next = temp;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
				}
			}
			p = p->next;
		}
		if (judge == 3)continue;
		mark = mark->last;
	}
	return head;
}
STU* english_sort(STU* head)
{
	if (head == NULL)
	{
		MessageBox(hWnd, _T("��û���κ�ѧ����Ϣ�أ�"), _T("��ʾ"), MB_OK);
		return NULL;
	}
	STU  *p, *mark;
	int judge = NO;
	p = head;
	while (p->next)   //Ѱ�����һ��
	{
		p = p->next;
	}
	mark = p;
	while (mark != head)  //ð������
	{
		judge = NO;
		p = head;//
		while (p != mark)
		{
			if (p->stu_data.grade.english < p->next->stu_data.grade.english)
			{
				if (p->next == mark)judge = YES;
				if (p == head)
				{
					if (p->next->next == NULL)
					{
						head = p->next;
						head->last = NULL;
						head->next = p;
						p->last = head;
						p->next = NULL;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
					head = p->next;
					head->last = NULL;
					p->last = head;
					head->next->last = p;
					p->next = head->next;
					head->next = p;
					if (judge == YES)
					{
						judge = 3;
						break;
					}
					continue;
				}
				else {
					if (p->next->next == NULL)
					{
						p->next->last = p->last;
						p->next->next = p;
						p->last->next = p->next;
						p->last = p->next;
						p->next = NULL;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
					else {
						STU* temp = p->next->next;
						p->last->next = p->next;
						p->next->last = p->last;
						temp->last = p;
						p->next->next = p;
						p->last = p->next;
						p->next = temp;
						if (judge == YES)
						{
							judge = 3;
							break;
						}
						continue;
					}
				}
			}
			p = p->next;
		}
		if (judge == 3)continue;
		mark = mark->last;
	}
	return head;
}