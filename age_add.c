#include"header.h"
stu *age_add(stu *head,char *name)
{
	if (head == NULL)
	{
		printf("NO student!");
		system("pause");
		return 0;
	}
	stu *p = head;
	while (p != NULL)
	{
		if (strcmp(p->data->name, name) == 0)
		{
			p->data->age++;
		}
		p = p->next;
	}
	savefile(head);
	return head;
}