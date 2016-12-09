#include"header.h"
void output_linklist(stu *head)//输出学生信息
{
	int n = 0;
	system("cls");
	stu *p;
	p = head;
	SPACE; printf("******** student's information ********\n");
	SPACE; puts("No\tName\tAge\tsex\tdept\tscore");
	while (p != NULL)
	{
		SPACE; printf("%d\t%s\t%d\t%s\t%s\t%d\n", p->data->no, p->data->name, p->data->age, p->data->sex, p->data->dept, p->data->score);
		n++;
		p = p->next;
	}
	SPACE; printf("=== altogether %d people ===\n\n", n);
}