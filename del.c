#include"header.h"
stu* del(stu *head,int no)//删除学生
{
	if (head == NULL)
	{
		puts("No student!");
		system("pause");
		return head;
	}
	stu *p1, *p2;
	p1 = p2 = head;
	if (p1->data->no == no)//删除首节点时单独处理
	{
		head = p1->next;
	}
	else
	{
		while (p1->data->no != no)//循环用于查找目标
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
		p2->next = p1->next;//删除的核心的代码
	}
	free(p1);
	savefile(head);
	return head;
}