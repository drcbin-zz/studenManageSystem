#include"header.h"
REVISE *found_max_age(stu *head)
{
	if (head == NULL)
	{
		return head;
	}
	stu *p = head;
	REVISE *p_max=(REVISE *)calloc(sizeof(REVISE)),*head_max=(REVISE *)calloc(1,sizeof(REVISE));
	REVISE *p1 = head_max, *p2;
	p_max->p_data = p;
	while(p != NULL)
	{
		if (strcmp(p->data->sex, "女") == 0)
		{
			if (p_max->p_data->data->age < p->data->age)
			{
                p_max->p_data = p;
			}
		}	
		p = p->next;
	}
	p = head;
	p2=p1 = head_max;
	while (p != NULL)//循环用于查找目标学生
	{
		if (p->data->age == p_max->p_data->data->age&& (strcmp(p->data->sex, "男")) == 0)
		{
			p1 = p2;
			p1->p_data = p;
			p2 = (REVISE*)calloc(1, sizeof(REVISE));
			p1->next = p2;
		}
		p = p->next;
	}
	p1->next = p2 = NULL;
	if (head_max->p_data == NULL)head_max=NULL;
	return head_max;
}