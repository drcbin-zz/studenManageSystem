#include"header.h"
void free_revise_linklist(REVISE *head)
{
	REVISE *p = head;
	while (p != NULL)
	{
		p = p->next;
		free(head);
		head = p;
	}
	free(head);
}

void output_revise_linklist(REVISE *head)
{
	int n = 0;
	system("cls");
	REVISE *p;
	p = head;
	SPACE; printf("******** student's information ********\n");
	SPACE; puts("No\tName\tAge\tsex\tdept\tscore");
	while (p != NULL)
	{
		SPACE; printf("%d\t%s\t%d\t%s\t%s\t%d\n", p->p_data->data->no, p->p_data->data->name, p->p_data->data->age, p->p_data->data->sex, p->p_data->data->dept, p->p_data->data->score);
		n++;
		p = p->next;
	}
	SPACE; printf("=== altogether %d people ===\n\n", n);
	system("pause");
}