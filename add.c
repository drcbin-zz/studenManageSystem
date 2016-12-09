#include"header.h"
stu* add(stu *head,stu *pnew,int choose)//添加学生
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
		case 1://插到首节点
		{
			head = pnew;
			pnew->next = p1;
			break;
		}
		case 2://插到末节点
		{
			while (p1->next != NULL)
			{
				p1 = p1->next;
			}
			pnew->next = p1->next;
			p1->next = pnew;
			break;
		}

		case 3://插为中间节点
		{
			printf("add before (input NO)：");
			int pnew_no;
			scanf("%d", &pnew_no); getchar();
			if (p1->data->no != pnew_no)
			{
				while (p1->data->no != pnew_no)//循环用于查找目标学生
				{
					p2 = p1;
					p1 = p1->next;
				}
			}
			else p1 = p1->next;
			p2->next = pnew;//插入的核心代码
			pnew->next = p1;
			break;
		}
		}
	savefile(head);
	return head;
}
