#include"header.h"
stu *revise_dept(stu *head)
{
	char dept[25];
	printf("Please input the old dept:");
	gets(dept);
	int n = 0;
	stu *p = head;
	REVISE *new_head, *p1, *p2;
	new_head = p1 = p2 = (REVISE*)calloc(1, sizeof(REVISE));
	while (p != NULL)
	{
		if (strcmp(p->data->dept, dept) == 0)
		{
			p1 = p2;
			p1->p_data = p;
			p2 = (REVISE*)calloc(1, sizeof(REVISE));
			p1->next = p2;
			n++;
		}
		p = p->next;
	}
	p1->next = p2 = NULL;
	if (n == 0)
	{
		puts("Not found!");
		free(new_head);
	}

	if (n == 1)
	{
		for (p = head; p != NULL; p = p->next)
		{
			if ((p->data->no == new_head->p_data->data->no) && (p->data->age == new_head->p_data->data->age) && (strcmp(p->data->name, new_head->p_data->data->name) == 0) && (strcmp(p->data->sex, new_head->p_data->data->sex) == 0) && (strcmp(p->data->dept, new_head->p_data->data->dept) == 0))
				break;
		}
		puts("Please input the new dept:");
		gets(p->data->dept);
		free(new_head);
	}
	else
	{
		output_revise_linklist(new_head);
		puts("Please choose(input line number):");
		p1 = new_head;
		while (1)
		{
			int line_number;
			scanf("%d", &line_number); getchar();
			for (n = 1; p1 != NULL&&n != line_number; p1 = p1->next)
			{
				n++;
			}
			if (p1 == NULL)puts("wrong!please reenter:");
			else break;
		}
		puts("Please input new dept:");
		for (p = head; p != NULL; p = p->next)
		{
			if ((p->data->no == p1->p_data->data->no) && (p->data->age == p1->p_data->data->age) && (strcmp(p->data->name, p1->p_data->data->name) == 0) && (strcmp(p->data->sex, p1->p_data->data->sex) == 0) && (strcmp(p->data->dept, p1->p_data->data->dept) == 0))
			{
				gets(p->data->dept);
			}
		}
		free_revise_linklist(new_head);
	}
	savefile(head);
	return head;
}