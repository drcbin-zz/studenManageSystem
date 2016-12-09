#include"myheader.h"
STU* create_stu_infor_linklist()
{
	int judge = 0;
	STU *head, *p, *q;
	p = head = (STU*)calloc(1, sizeof(STU));
	head->last = NULL;
	while (1)
	{
		system("cls");
		printf("***��¼��%d��ѧ��***\n",judge);
		printf("ѧ��(����0����¼��)��");
		while (!scanf("%d", &p->stu_data.num)||judge_repeat(head,p->stu_data.num))
		{
			if (judge_repeat(head, p->stu_data.num))
			{
				FFLUSH;
				MessageBox(hWnd,_T("ѧ���Ѵ��ڣ�"),_T("��ʾ"),MB_OK);
				continue;
			}
			FFLUSH;
			MessageBox(hWnd,_T("ѧ�Ų���ȷ��"),_T("��ʾ"),MB_OK);
		}
		FFLUSH;
		STU* q = head;//�������ѧ���ظ��ж�
		while(q!=p)
		{
			q = q->next;
		}
		if (p->stu_data.num == 0)
		{
			if (judge == 0)
			{
				int RetryOrCancel=MessageBox(hWnd,_T("δ¼��ѧ����"),_T("��ʾ"),MB_RETRYCANCEL);
				if (RetryOrCancel == 4)continue;
				if (RetryOrCancel == 2)return NULL;
				else exit(0);
			}
			break;
		}
		printf("������");
		gets(p->stu_data.name);

		printf("�Ա�");
		gets(p->stu_data.sex);
		while (strcmp(p->stu_data.sex, "F") && strcmp(p->stu_data.sex, "M") && strcmp(p->stu_data.sex, "f")
			&& strcmp(p->stu_data.sex, "m") && strcmp(p->stu_data.sex, "��") && strcmp(p->stu_data.sex, "Ů"))
		{
			MessageBox(hWnd,_T("�������������Ա�"),_T("��ʾ"),MB_OK);
			gets(p->stu_data.sex);
		}

		printf("���䣺");
		while ((!scanf("%d", &p->stu_data.age))||p->stu_data.age < 0|| p->stu_data.age > 150)
		{
			AGE_WARING;
			FFLUSH;
		}FFLUSH;


		printf("���ĳɼ���");
		while ((!scanf("%d", &p->stu_data.grade.chinese)||p->stu_data.grade.chinese < 0))
		{
			GRADE_WARING;
			FFLUSH;
		}FFLUSH;


		printf("��ѧ�ɼ���");
		;
		while ((!scanf("%d", &p->stu_data.grade.math))||p->stu_data.grade.math < 0)
		{
			GRADE_WARING;
			FFLUSH;
		}FFLUSH;
		printf("Ӣ��ɼ���");
		while (!(scanf("%d", &p->stu_data.grade.english))||p->stu_data.grade.english < 0)
		{
			GRADE_WARING;
			FFLUSH;
		}FFLUSH;
		p->next = (STU*)calloc(1,sizeof(STU));
		p->next->last = p;
		p = p->next;
		judge++;
	}
	p->last->next = NULL;
	free(p);
	return head;
}

void save_stu_infor(STU *head,FILE *fp)
{
	STU* p = head;
	while (p)
	{
		if ((fwrite(&p->stu_data, sizeof(p->stu_data), 1, fp)) != 1)
		{
			MessageBox(hWnd, _T("����ʧ��"), _T("��ʾ"), MB_OK);
			return 0;
		}
		p = p->next;
	}
	MessageBox(hWnd, _T("����ɹ�:'student.txt'"), _T("��ʾ"), MB_OK);
}

int judge_repeat(STU* head,int num)
{
	if (head == NULL)
	{
		return NO;
	}
	STU* p = head;
	while (p->next)
	{
		if (p->stu_data.num == num)
		{
			return YES;
		}
		p = p->next;
	}
	return NO;
}

int judge_Oldrepeat(STU* head, int num)
{
	if (head == NULL)
	{
		return NO;
	}
	STU* p = head;
	while (p)
	{
		if (p->stu_data.num == num)
		{
			return YES;
		}
		p = p->next;
	}
	return NO;
}