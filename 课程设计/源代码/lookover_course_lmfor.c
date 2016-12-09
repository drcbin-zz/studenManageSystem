#include"myheader.h"
float lookover_course_infor(STU *head,char *subject)
{
	char course_infor_choose;
	while (1)
	{
		system("cls");
		puts("1、及格率\n"
			"2、最高分\n"
			"3、平均分\n"
			"4、分数段查询\n"
			"0、返回\n");
		puts("请选择：");
		course_infor_choose = getch();
		switch (course_infor_choose)
		{
		case '1': {
			float passrate=passRate(head, subject);
			system("cls");
			printf("该科的及格率为：%f",passrate);
			getch();
			break; 
		}
		case '2': {
			int max=max_grade(head, subject); 
			system("cls");
			printf("该科的最高分为：%d",max);
			getch();
			break; 
		}
		case '3': {
			float _average = Average(head, subject); 
			system("cls");
			printf("该科的平均分为:%f",_average); 
			getch();
			break;
		}
		case '4': {
			system("cls");
			int grade1, grade2;
			printf("请输入起始分数："); 
			while ((!scanf("%d", &grade1)) || grade1 < 0)
			{
				GRADE_WARING;
				FFLUSH;
			}FFLUSH;
			printf("请输入终止分数：");
			while ((!scanf("%d", &grade2)) || grade2 < 0)
			{
				GRADE_WARING;
				FFLUSH;
			}FFLUSH;
			int count=grade_part(head, subject,grade1,grade2); 
			system("cls");
			printf("%d~%d分数段的人数为：%d",grade1,grade2,count);
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
		MessageBox(hWnd, _T("真是没有学生信息，请先添加学生！"), _T("提示"), NULL);
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
