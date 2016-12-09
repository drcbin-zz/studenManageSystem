#include"header.h"
void save_course(course* head)
{
	FILE *fp;
	if ((fp = fopen("d:\\course.txt", "w+")) == NULL)
	{
		puts("write_open error!");
		system("pause");
		return ;
	}
	course *p = head;
	while (p != NULL)
	{
		if (fwrite(p->data, sizeof(course_data), 1, fp) != 1)
		{
			puts("wtite erroe!");
			fclose(fp);
			system("pause");
			return ;
		}
		p = p->next;
	}
	fclose(fp);
}