#include"myheader.h"
float lookover_course_infor(STU *head,char *subject)
{
	char course_infor_choose;
	while (1)
	{
		system("cls");
		puts("1��������\n"
			"2����߷�\n"
			"3��ƽ����\n"
			"4�������β�ѯ\n"
			"0������\n");
		puts("��ѡ��");
		course_infor_choose = getch();
		switch (course_infor_choose)
		{
		case '1': {
			float passrate=passRate(head, subject);
			system("cls");
			printf("�ÿƵļ�����Ϊ��%f",passrate);
			getch();
			break; 
		}
		case '2': {
			int max=max_grade(head, subject); 
			system("cls");
			printf("�ÿƵ���߷�Ϊ��%d",max);
			getch();
			break; 
		}
		case '3': {
			float _average = Average(head, subject); 
			system("cls");
			printf("�ÿƵ�ƽ����Ϊ:%f",_average); 
			getch();
			break;
		}
		case '4': {
			system("cls");
			int grade1, grade2;
			printf("��������ʼ������"); 
			while ((!scanf("%d", &grade1)) || grade1 < 0)
			{
				GRADE_WARING;
				FFLUSH;
			}FFLUSH;
			printf("��������ֹ������");
			while ((!scanf("%d", &grade2)) || grade2 < 0)
			{
				GRADE_WARING;
				FFLUSH;
			}FFLUSH;
			int count=grade_part(head, subject,grade1,grade2); 
			system("cls");
			printf("%d~%d�����ε�����Ϊ��%d",grade1,grade2,count);
			getch();
			break;
		}
		case '5':ranking(head, subject); break;
		case '0':  return 0;
		}
	}
}



float Average(STU *head,char *subject)
{

	STU *p = head;
	int  sum=0;
	float average;
	if ((strcmp(subject, "chinese")) == 0)
	{
		while (p)
		{
			sum += p->stu_data.grade.chinese;
			p = p->next;
		}
	}
	if ((strcmp(subject, "math" ))== 0)
	{
		while (p)
		{
			sum+=p->stu_data.grade.math;
			p = p->next;
		}
	}
	if ((strcmp(subject, "english")) == 0)
	{
		while (p)
		{
			sum += p->stu_data.grade.english;
			p = p->next;
		}

	}
	average = (float)countPersonNum(head) / (float)sum;
	return average;
}

float passRate(STU *head, char *subject)
{
	if (head == NULL)
	{
		MessageBox(hWnd, _T("����û��ѧ����Ϣ���������ѧ����"), _T("��ʾ"), NULL);
		return 0;
	}
	STU *p = head;
	float passrate;
	int count = 0;
	if ((strcmp(subject, "chinese")) == 0)
	{
		while (p)
		{
			if ((p->stu_data.grade.chinese) >= 60)
			{
				count++;
			}
			p = p->next;
		}
	}
	if ((strcmp(subject, "math")) == 0)
	{
		while (p)
		{
			if ((p->stu_data.grade.math) >= 60)
			{
				count++;
			}
			p = p->next;
		}
	}
	if ((strcmp(subject, "ehglish"))== 0)
	{
		while (p)
		{
			if ((p->stu_data.grade.english) >= 60)
			{
				count++;
			}
			p = p->next;
		}
	}
	passrate = (float)CountClipboardFormats(head) / (float)count;
	return passrate;
}


int max_grade(STU* head,char *subject)
{
	STU *p = head;
	int max;
	if ((strcmp(subject, "chinese")) == 0)
	{
		max = p->stu_data.grade.chinese;
		while (p)
		{
			if (p->stu_data.grade.chinese > max)
				max = p->stu_data.grade.chinese;
			p = p->next;
		}
	}
	if ((strcmp(subject, "math")) == 0)
	{
		max = p->stu_data.grade.math;
		while (p)
		{
			if (p->stu_data.grade.math > max)
				max = p->stu_data.grade.math;
			p = p->next;
		}
	}
	if ((strcmp(subject, "english")) == 0)
	{
		max = p->stu_data.grade.english;
		while (p)
		{
			if (p->stu_data.grade.english > max)
				max = p->stu_data.grade.english;
			p = p->next;
		}
	}
	return max;
}


int grade_part(STU* head, char *subject,int grade1, int grade2)
{
	STU *p = head;
	int count = 0;
	if ((strcmp(subject, "chinese")) == 0)
	{
		while (p)
		{
			if (p->stu_data.grade.chinese >= grade1&&p->stu_data.grade.chinese < grade2)
				count++;
			p = p->next;
		}
	}
	if ((strcmp(subject, "math")) == 0)
	{
		while (p)
		{
			if (p->stu_data.grade.math >= grade1&&p->stu_data.grade.math < grade2)
				count++;
			p = p->next;
		}
	}
	if ((strcmp(subject, "english")) == 0)
	{
		while (p)
		{
			if (p->stu_data.grade.english >= grade1&&p->stu_data.grade.english < grade2)
				count++;
			p = p->next;
		}
	}
	return count;
}


void ranking()
{
	
}
