#include"header.h"
COUNT *found_age(stu *head)
{
	if (head == NULL)
	{
		return head;
	}
	stu *p = head;
	COUNT *head_found_age = (COUNT *)calloc(1, sizeof(COUNT));
	COUNT *fdp = head_found_age, *fdq = head_found_age;
	while (p != NULL)
	{
		if (p == head)
		{
			fdp->type_num = p->data->age;
			fdp->count = 1;
			fdp->next = NULL;
		}
		else {
			for (fdp = head_found_age;; fdp = fdp->next)
			{
				if (p->data->age == fdp->type_num)
				{
					fdp->count++;
					break;
				}
				if (fdp->next == NULL)
				{
					fdq = (COUNT*)calloc(1, sizeof(COUNT));
					fdp->next = fdq;
					fdp = fdq;
					fdp->type_num = p->data->age;
					fdp->count = 1;
					fdp->next = NULL;
					break;
				}
			}
		}
		p = p->next;
	}
	return head_found_age;
}