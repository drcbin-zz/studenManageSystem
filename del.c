#include"header.h"
stu* del(stu *head,int no)//ɾ��ѧ��
{
	if (head == NULL)
	{
		puts("No student!");
		system("pause");
		return head;
	}
	stu *p1, *p2;
	p1 = p2 = head;
	if (p1->data->no == no)//ɾ���׽ڵ�ʱ��������
	{
		head = p1->next;
	}
	else
	{
		while (p1->data->no != no)//ѭ�����ڲ���Ŀ��
		{
			p2 = p1;
			p1 = p1->next;
			if (p1 == NULL)
			{
				printf("Not found!\n");
				system("pause");
				return head;
			}
		}
		p2->next = p1->next;//ɾ���ĺ��ĵĴ���
	}
	free(p1);
	savefile(head);
	return head;
}