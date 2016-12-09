#include"header.h"
void output_student_course(student_course *head)
{
	student_course *p = head;
	int n = 0;
	system("cls");
	SPACE; puts("Sno\tCno\tgrade");
	while (p!= NULL)
	{
		n++;
		SPACE; printf("%d\t%d\t%d\n",p->data->Sno,p->data->Cno,p->data->gread);
		p = p->next;
	}
	SPACE; printf("======== altogether %d student course ========\n",n);
	system("pause");
}