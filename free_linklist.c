#include"header.h"
void free_linklist(stu *head)  //�ͷŲ�Ҫ������
{
	stu *p;
	p = head;
	while (head->next != NULL)
	{
		head = head->next;
		free(p->data);
		free(p);
		p = head;
	}
	free(p->data);
	free(head);
}
