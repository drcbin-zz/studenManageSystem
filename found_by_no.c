#include"header.h"
REVISE *found_by_no(stu * head, int no)  //ͳ��ѧ����ͬ��ѧ������
{
	if (head == NULL)
	{
		return head;
	}
	stu *p = head;
	//����������������Ŀ��ѧ��
	REVISE *new_head, *p1, *p2;
	new_head = p1 = p2 = (REVISE*)calloc(1, sizeof(REVISE));
	while (p != NULL)//ѭ�����ڲ���Ŀ��ѧ��
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