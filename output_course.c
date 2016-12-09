#include"header.h"
void output_course(course *head)
{
	system("cls");
	SPACE; puts("======== course information ========");
	SPACE; puts("Cno\tCname\tCredit");
	int n = 0;
	if (head == NULL);
	else {
		course *p = head;
		while (p != NULL)
		{
			n++;
			SPACE; printf("%d\t%s\t%d\n",p->data->Cno,p->data->Cname,p->data->Credit);
			p = p->next;
		}
	}
	SPACE; printf("======== altogether %d course(s) ========\n", n);
	system("pause");
}