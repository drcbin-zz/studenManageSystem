#include"header.h"
COUNT *found_dept(stu *head)
{
	if (head == NULL)
	{
		return head;
	}
	stu *p = head;
	COUNT *head_found_dept = (COUNT *)calloc(1, sizeof(COUNT));
	COUNT *fdp = head_found_dept, *fdq = head_found_dept;
	while (p != NULL)
	{
		if (p == head)
		{
			strcpy(fdp->type, p->data->dept);
			fdp->count = 1;
			fdp->next = NULL;
		}
		else 
		{
			for (fdp = head_found_dept;; fdp = fdp->next)
			{
				if ((strcmp(p->data->dept, fdp->type)) == 0)
				{
					fdp->count++;
					break;
				}
				if (fdp->next == NULL)
				{
					fdq = (COUNT*)calloc(1, sizeof(COUNT));
					fdp->next = fdq;
					fdp = fdq;
					strcpy(fdp->type, p->data->dept);
					fdp->count = 1;
					fdp->next = NULL;
					break;
				}
			}
		}
		p = p->next;
	}
	return head_found_dept;
}