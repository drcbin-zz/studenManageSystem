#include"header.h"
stu* add(stu *head,stu *pnew,int choose)//���ѧ��
{

	stu *p1, *p2;
	p1 = p2 = head;
	if (head == NULL)
	{
		head = pnew;
		pnew->next = p1;
		savefile(head);
		return head;
	}
		switch (choose)
		{
		case 1://�嵽�׽ڵ�
		{
			head = pnew;
			pnew->next = p1;
			break;
		}
		case 2://�嵽ĩ�ڵ�
		{
			while (p1->next != NULL)
			{
				p1 = p1->next;
			}
			pnew->next = p1->next;
			p1->next = pnew;
			break;
		}

		case 3://��Ϊ�м�ڵ�
		{
			printf("add before (input NO)��");
			int pnew_no;
			scanf("%d", &pnew_no); getchar();
			if (p1->data->no != pnew_no)
			{
				while (p1->data->no != pnew_no)//ѭ�����ڲ���Ŀ��ѧ��
				{
					p2 = p1;
					p1 = p1->next;
				}
			}
			else p1 = p1->next;
			p2->next = pnew;//����ĺ��Ĵ���
			pnew->next = p1;
			break;
		}
		}
	savefile(head);
	return head;
}
