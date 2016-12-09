#include"header.h"
REVISE *found_by_no(stu * head, int no)  //统计学号相同的学生人数
{
	if (head == NULL)
	{
		return head;
	}
	stu *p = head;
	//开创新链表来保存目标学生
	REVISE *new_head, *p1, *p2;
	new_head = p1 = p2 = (REVISE*)calloc(1, sizeof(REVISE));
	while (p != NULL)//循环用于查找目标学生
	{
		if (p->data->no == no)
		{
			p1 = p2;
			p1->p_data = p;
			p2 = (REVISE*)calloc(1, sizeof(REVISE));
			p1->next = p2;
		}
		p = p->next;
	}
	p1->next = p2 = NULL;
	return new_head;
}