#include"header.h"
COUNT *count_average(stu *head)
{
	COUNT *ave_head,*p1;
	stu *p=head;
	p1 = ave_head = (COUNT*)calloc(1, sizeof*p1);
	strcpy(p1->type,"��");
	p1->type_num = 0;   //num��ʱͳ�Ƴɼ�����
	p1->type_num_1 = 0;  //sum_1ͳ������
	p1->next = (COUNT*)calloc(1, sizeof*p1);
	p1 = p1->next;
	strcpy(p1->type,"Ů");
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
		p1->type_float = (float)(p1->type_num / p1->type_num_1);//num��������ƽ����
		p1 = p1->next;
	}
	return ave_head;
}