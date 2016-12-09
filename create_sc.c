#include"header.h"
student_course *create_sc()
{
	student_course *SC_head, *p, *q;
	FILE *fp;
	if ((fp = fopen("d:\\student course.txt", "w")) == NULL)
	{
		puts("student course create error!");
		system("pause");
		SC_head = NULL;
	}
	else {
		fclose(fp);
		int n = 0;
		p = q = SC_head = (student_course*)calloc(1, sizeof *q);
		p->data = (SC_data *)calloc(1, sizeof *p->data);
		system("cls");
		printf("===== have entered %d student course =====\n", n++);
		printf("Sno:");
		scanf("%d", &p->data->Sno); getchar();
		if (p->data->Sno== 0)
		{
			SC_head = NULL;
			return SC_head;
		}
		printf("Cno:");
		scanf("%d", &p->data->Cno); getchar();
		printf("grade:");
		scanf("%d", &p->data->gread); getchar();
		while (1)
		{
			q = (student_course*)calloc(1, sizeof *q);
			q->data = (SC_data*)calloc(1,sizeof *p->data);
			p->next = q;
			system("cls");
			printf("===== have entered %d student course =====\n", n++);
			printf("Sno:");
			scanf("%d", &q->data->Sno); getchar();
			if (q->data->Sno == 0)
			{
				break;
			}
			printf("Cno:");
			scanf("%d", &q->data->Cno); getchar();
			printf("grade:");
			scanf("%d", &q->data->gread); getchar();
			p = p->next;
		}
		p->next = q = NULL;
		save_student_course(SC_head);
	}
	return SC_head;
}