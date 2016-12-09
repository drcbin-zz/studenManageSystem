#include"header.h"
COUNT *count_course_num(course *head, student_course *SC_head)
{
	student_course* q=SC_head;
	course *p = head;
	COUNT *ccn_head, *p1, *p2;
	p1 = p2 = ccn_head = (COUNT*)calloc(1, sizeof*p1);
	while (p != NULL)
	{
		p1 = p2;
		p1->type_num = p->data->Cno;
		strcpy(p1->type, p->data->Cname);
		p1->count = 0;
		p2 = (COUNT*)calloc(1, sizeof*p1);
		p1->next = p2;
		p = p->next;
	}
	p1->next = NULL;
	while (q != NULL)
	{
		p1 = ccn_head;
		while (p1 != NULL)
		{
			if (p1->type_num == q->data->Cno)
			{
				p1->count++;
				break;
			}
			p1 = p1->next;
		}
		q = q->next;
	}
	return ccn_head;
}

void output_ccn(COUNT *head)
{
	COUNT *p = head;
	system("cls");
	puts("课程号\t课程名称\t人数");
	while (p != NULL)
	{
		printf("%d\t%s\t%d\n", p->type_num, p->type, p->count);
		p = p->next;
	}
	system("pause");
}