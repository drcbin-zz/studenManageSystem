#include"header.h"
int found_by_firstname(stu *head, char *firstname)//´íÎó
{
	if (head == NULL)
	{
		return head;
	}
	int n = 0;
		int i;
		stu *p = head;
		while (p != NULL)
		{
			for (i = 0; firstname[i] != '\0'; i++)
			{
				if (p->data->name[i] == firstname[i])continue;
				else break;
			}
			if (firstname[i] == '\0')n++;
			p = p->next;
		}
		return n;
}