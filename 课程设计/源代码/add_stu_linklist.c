#include"myheader.h"
STU* add_stu_linklist(STU *head)
{
	int judge = 0;
	STU  *p, *q, *NewHead;
	p = NewHead = (STU*)calloc(1, sizeof(STU));
	NewHead->last = NULL;
	while (1)
	{
		system("cls");
		printf("***��¼��%d��ѧ��***\n", judge);
		printf("ѧ��(����0����¼��)��");
		while (!scanf("%d", &p->stu_data.num) || judge_repeat(NewHead, p->stu_data.num)||judge_Oldrepeat(head,p->stu_data.num))
		{
			if ((judge_repeat(NewHead, p->stu_data.num))||(judge_repeat(head,p->stu_data.num)))
			{
				FFLUSH;
				MessageBox(hWnd, _T("ѧ���Ѵ��ڣ�"), _T("��ʾ"), MB_OK);
				continue;
			}
			FFLUSH;
			MessageBox(hWnd, _T("ѧ�Ų���ȷ��"), _T("��ʾ"), MB_OK);
		}
		FFLUSH;
		if (p->stu_data.num == 0)
		{
			if (judge == 0)
			{
				int RetryOrCancel = MessageBox(hWnd, _T("δ¼��ѧ����"), _T("��ʾ"), MB_RETRYCANCEL);
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
			MessageBox(hWnd, _T("�������������Ա�"), _T("��ʾ"), MB_OK);
			gets(p->stu_data.sex);
		}

		printf("���䣺");
		while ((!scanf("%d", &p->stu_data.age)) || p->stu_data.age < 0 || p->stu_data.age > 150)
		{
			AGE_WARING;
			FFLUSH;
		}FFLUSH;


		printf("���ĳɼ���");
		while ((!scanf("%d", &p->stu_data.grade.chinese) || p->stu_data.grade.chinese < 0))
		{
			GRADE_WARING;
			FFLUSH;
		}FFLUSH;


		printf("��ѧ�ɼ���");
		;
		while ((!scanf("%d", &p->stu_data.grade.math)) || p->stu_data.grade.math < 0)
		{
			GRADE_WARING;
			FFLUSH;
		}FFLUSH;
		printf("Ӣ��ɼ���");
		while (!(scanf("%d", &p->stu_data.grade.english)) || p->stu_data.grade.english < 0)
		{
			GRADE_WARING;
			FFLUSH;
		}FFLUSH;
		p->next = (STU*)calloc(1, sizeof(STU));
		p->next->last = p;
		p = p->next;
		judge++;
	}
	p->last->next = NULL;
	free(p);
	return NewHead;
}
