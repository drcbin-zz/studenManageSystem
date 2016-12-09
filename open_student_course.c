#include"header.h"
student_course *open_student_course()
{
	FILE *fp;
	student_course *SC_head,*p,*q;
	if ((fp = fopen("d:\\student course.txt", "r")) == NULL)
	{
		printf("open student course error!");
		SC_head = NULL;
		system("pause");
		return SC_head;
	}
	p = q = SC_head = (student_course*)calloc(1, sizeof *p);
	p->data = (SC_data*)calloc(1, sizeof*p->data);
	while (fread(q->data, sizeof*q->data, 1, fp) == 1)
	{
		p = q;
		q = (student_course*)calloc(1, sizeof *p);
		q->data = (SC_data*)calloc(1, sizeof*p->data);
		p->next = q;
	}
	p->next = NULL;
	fclose(fp);
	return SC_head;
}