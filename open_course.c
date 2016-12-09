#include"header.h"
course *open_course()
{
	course *C_head;
	FILE *fp;
	if ((fp = fopen("d:\\course.txt", "r+")) == NULL)
	{
		printf("open course erroe!");
		system("pause");
		C_head = NULL;
		return C_head;
	}
	course *p, *q;
	p = q = C_head = (course*)calloc(1, sizeof(course));
	p->data = (course_data*)calloc(1, sizeof(course_data));
	while (( fread(q->data,sizeof(course_data),1,fp)) == 1)
	{
		p = q;
		q = (course*)calloc(1, sizeof(course));
		q->data = (course_data*)calloc(1, sizeof(course_data));
		p->next = q;
	}
	p->next = NULL;
	fclose(fp);
	return C_head;
}