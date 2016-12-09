#include"header.h"
COUNT *count_average(stu *head)
{
	COUNT *ave_head,*p1;
	stu *p=head;
	p1 = ave_head = (COUNT*)calloc(1, sizeof*p1);
	strcpy(p1->type,"男");
	p1->type_num = 0;   //num临时统计成绩总数
	p1->type_num_1 = 0;  //sum_1统计人数
	p1->next = (COUNT*)calloc(1, sizeof*p1);
	p1 = p1->next;
	strcpy(p1->type,"女");
	p1->type_num = 0;
	p1->type_num_1 = 0;
	p1->next = NULL;
	while (p != NULL)
	{
		p1 = ave_head;
		while (p1 != NULL)
		{
			if (strcmp(p->data->sex, p1->type) == 0)
			{
				p1->type_num_1++;
				p1->type_num += p->data->score;
			}
			p1 = p1->next;
		}
		p = p->next;
	}
	p1 = ave_head;
	while (p1 != NULL)
	{
		p1->type_float = (float)(p1->type_num / p1->type_num_1);//num用来保存平均数
		p1 = p1->next;
	}
	return ave_head;
}