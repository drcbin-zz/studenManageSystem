#include"header.h"
stu *create_open()//����������
{
	int n = 0;
	stu * head=NULL, *p, *q;
	//stu_data *q;
	p = head = (stu*)malloc(sizeof(stu));
	p->data = (stu_data*)malloc(sizeof(stu_data));
	FILE *fp;
	if ((fp = fopen("d:\\student list.txt", "r")) == NULL)
	{
		puts("open wrong!not found.");
		head = NULL;
	}
	else {
		while (fread(p->data, sizeof(stu_data), 1, fp) == 1)//��ȡ�ļ�����
		{
			n++;
			p->next = (stu*)malloc(sizeof(stu));
			q = p;
			p = p->next;
			p->data = (stu_data*)malloc(sizeof(stu_data));
		}
		if (n == 0)
		{
			head = NULL;
			return head;
		}
		p = q->next = NULL;
	}
	return head;
}