#include"header.h"
void output_found_linklist(COUNT *head)
{
	COUNT *p = head;
	system("cls");
	puts("���\t����");
	while (p != NULL)
	{
		printf("%s:\t%d�ˡ�\n",p->type, p->count);
		p = p->next;
	}
	system("pause");
}
void output_found_linklist_num(COUNT *head)
{
	COUNT *p = head;
	system("cls");
	puts("���\t����");
	while (p != NULL)
	{
		printf("%d:\t%d�ˡ�\n", p->type_num, p->count);
		p = p->next;
	}
	system("pause");
}

void output_count_score(COUNT *head)
{
	system("cls");
	puts("���\t����");
	COUNT *p = head;
	while (p != NULL)
	{
		printf("%s\t%.2f\n",p->type,p->type_float);
		p = p->next;
	}
	system("pause");
}
void free_found_linklist(COUNT *head)
{
	COUNT *p = head;
	while (p != NULL)
	{
		head = p->next;
		free(p);
		p = head;
	}
	free(head);
}

void output_found_num(int n)
{
	system("cls");
	printf("\nAltogether %d people!\n", n);
	system("pause");
}