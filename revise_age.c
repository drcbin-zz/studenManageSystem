#include"header.h"
stu* revise_age(stu *head)
{
	int age;
	printf("Please input the old age:");
	scanf("%d", &age); getchar();
	int n = 0;
	stu *p = head;
	stu *new_head, *p1, *p2;
	new_head = p1 = p2 = (stu*)calloc(1, sizeof(stu));
	p1->data = (stu_data*)malloc(sizeof(stu_data));
	while (p != NULL)
	{
		if (p->data->age == age)
		{
			p1 = p2;
			p1->data = p->data;
			p2 = (stu*)calloc(1, sizeof(stu));
			p2->data = (stu_data*)malloc(sizeof(stu_data));
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
			if ((p->data->no == new_head->data->no) && (p->data->age == new_head->data->age) && (strcmp(p->data->name, new_head->data->name) == 0) && (strcmp(p->data->sex, new_head->data->sex) == 0) && (strcmp(p->data->dept, new_head->data->dept) == 0))
				break;
		}
		puts("Please input the new age:");
		scanf("%d", &p1->data->age); getchar();
		free(new_head);
	}
	else
	{
		output_linklist(new_head);
		puts("Please choose(input line number):");
		p1 = new_head;
		while (1)
		{
			int line_number;
			scanf("%d", &line_number); getchar();
			for (n = 1; p1 != NULL&&n != line_number&&!(n<2); p1 = p1->next)
			{
				n++;
			}
			if (p1 == NULL)puts("wrong!please reenter:");
			else break;
		}
		puts("Please input new age:");
		for (p = head; p != NULL; p = p->next)
		{
			if ((p->data->no == p1->data->no) && (p->data->age == p1->data->age) && (strcmp(p->data->name, p1->data->name) == 0) && (strcmp(p->data->sex, p1->data->sex) == 0) && (strcmp(p->data->dept, p1->data->dept) == 0))
			{
				scanf("%d", &p->data->age);
			}
		}
		free_linklist(new_head);
	}
	savefile(head);
	return head;
}