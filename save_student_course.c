#include"header.h"
void save_student_course(student_course* head)
{
	FILE *fp;
	if ((fp = fopen("d:\\student course.txt", "w")) == NULL)
	{
		puts("student course write open error!");
		system("pause");
		return;
	}
	student_course *p = head;
	while (p != NULL)
	{
		if (fwrite(p->data, sizeof *p->data, 1, fp) != 1)
		{
			puts("student course write error!");
		}
		p = p->next;
	}
}