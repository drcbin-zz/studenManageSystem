#include"header.h"
course *create_course()
{
	FILE *fp;
	if ((fp = fopen("d:\\course.txt", "w")) == NULL)
	{
		puts("course create fail!");
		system("pause");
		exit();
	}
	puts("create successed!d:\\course.txt");
	fclose(fp);
	system("pause");
	system("cls");
	int n = 0;
	printf("======== have entered %d course(s)========\n",n++);
	course *C_head = (course*)calloc(1, sizeof(course));
	C_head->data = (course_data*)calloc(1, sizeof(course_data));
	course *p = C_head, *q = C_head;
	printf("Cno:");
	scanf("%d", &p->data->Cno); getchar();
	if (C_head->data->Cno == 0)
	{
		C_head = NULL;
		return C_head;
	}
	printf("Cname:");
	gets(p->data->Cname);
	printf("Credit:");
	scanf("%d", &p->data->Credit); getchar();
	while (1)
	{
		system("cls");
		printf("======== have entered %d course(s)========\n", n++);
		q= (course*)calloc(1, sizeof(course));
		q->data= (course_data*)calloc(1, sizeof(course_data));
		p->next = q;
		printf("Cno:");
		scanf("%d", &q->data->Cno); getchar();
		if (q->data->Cno == 0)
		{
			break;
		}
		printf("Cname:");
		gets(q->data->Cname);
		printf("Credit:");
		scanf("%d", &q->data->Credit); getchar();
		p = q;
	}
	p->next = NULL;
	save_course(C_head);
	fclose(fp);
	return C_head;
}