#include"header.h"
void savefile(stu *head)
{
	FILE *fp;
	if ((fp = fopen("d:\\student list.txt", "w")) == NULL)
	{
		puts("write_open error!");
		fclose(fp);
		exit(4);
	}
	stu *p = head;
	while (p != NULL)
	{
		if (fwrite(p->data, sizeof(stu_data), 1, fp) != 1)
		{
			puts("write error!");
			fclose(fp);
			exit(5);
		}
		p = p->next;
	}
	fclose(fp);
}
