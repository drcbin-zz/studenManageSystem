#include"header.h"
stu *create_new()//��������
{
	int count = 0;
	FILE *fp;
	if ((fp = fopen("d:\\student list.txt", "w+")) == NULL)//�½��ļ�
	{
		puts("create fail!");
		exit(0);
	}
	//��ʼ¼���׽ڵ㣬�׽ڵ㵥������
	puts("create successed.d:\\student list.txt.");
	system("pause");
	fclose(fp);
	stu  *head, *p1, *p2;
	head = p1 = p2 = (stu *)malloc(sizeof(stu));
	p1->data = (stu_data*)malloc(sizeof(stu_data));
	system("cls");
	printf("=== have entered %d student ===\n", count);
	printf("Please input:\n");
	printf("no:");
	while (1)//ѭ�����ڼ���������룬������¼��
	{
		scanf("%d", &p1->data->no); getchar();
		if (p1->data->no == 0)
		{
			printf("At least enter one student!\n");
			continue;
		}
		else break;
	}

	printf("age:");
	while (1)//ѭ�����ڼ�����
	{
		scanf("%d", &p1->data->age); getchar();
		if (p1->data->age < 0)
		{
			printf("wrong! age can not be negative.please reenter:");
			continue;
		}
		else break;
	}
	printf("name:");
	gets(p1->data->name);
	printf("sex:");
	gets(p1->data->sex);
	printf("dept:");
	gets(p1->data->dept);
	printf("score:");
	while (1)//ѭ�����ڼ���������룬������¼��
	{
		scanf("%d", &p1->data->score); getchar();
		if (p1->data->no < 0)
		{
			printf("Wrong!score can not be negative.please reenter:\n");
			continue;
		}
		else break;
	}
	//
	while (p1->data->no != 0)//ѭ������¼��ڵ���Ϣ����ѧ��Ϊ0ʱ������¼��
	{
		p2 = p1;
		p1 = (stu *)malloc(sizeof(stu));
		p1->data = (stu_data*)malloc(sizeof(stu_data));
		p2->next = p1;
		system("cls");
		count++;
		printf("===have entered %d student===\n", count);
		printf("Please input:\n");
		printf("no:");
		scanf("%d", &p1->data->no); getchar();
		if (p1->data->no == 0 || p1->data->no < 0)//�ж��Ƿ�ֹͣ
		{
			break;
		}
		printf("age:");
		while (1)//ѭ�����ڼ������¼��
		{
			scanf("%d", &p1->data->age); getchar();
			if (p1->data->age < 0)
			{
				printf("wrong! age can not be negative.please reenter:");
				continue;
			}
			else break;
		}
		printf("name:");
		gets(p1->data->name);
		printf("sex:");
		gets(p1->data->sex);
		printf("dept:");
		gets(p1->data->dept);
		printf("score:");
		while (1)//ѭ�����ڼ���������룬������¼��
		{
			scanf("%d", &p1->data->score); getchar();
			if (p1->data->no < 0)
			{
				printf("Wrong!score can not be negative.please reenter:\n");
				continue;
			}
			else break;
		}
	}
	p2->next = NULL;
	savefile(head);//�����޸ĵ��ļ�
	return head;
}