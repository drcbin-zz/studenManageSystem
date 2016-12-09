#include"header.h"
COUNT *found_sex(stu *head)
{
	if (head == NULL)
	{
		return head;
	}
	stu *p = head;
	COUNT *head_found_sex = (COUNT *)calloc(1, sizeof(COUNT));
	COUNT *fdp = head_found_sex, *fdq = head_found_sex;
	while (p != NULL)
	{
		if (p == head)
		{
			strcpy(fdp->type, p->data->sex);
			fdp->count = 1;
			fdp->next = NULL;
		}
		else {
			for (fdp = head_found_sex;; fdp = fdp->next)
			{
				if ((strcmp(p->data->sex, fdp->type)) == 0)
				{
					fdp->count++;
					break;
				}
				if (fdp->next == NULL)
				{
					fdq = (COUNT*)calloc(1, sizeof(COUNT));
					fdp->next = fdq;
					fdp = fdq;
					strcpy(fdp->type, p->data->sex);
					fdp->count = 1;
					fdp->next = NULL;
					break;
				}
			}
		}
		p = p -> next;
	}
	return head_found_sex;
}
