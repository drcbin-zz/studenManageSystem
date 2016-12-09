#include<stdio.h>
#include<string.h>
#define  SPACE printf("                           ");
typedef struct student_data
{
	int no;
	char name[20];
	char sex[6];
	char dept[50];
	int age;
	int score;
}stu_data;
typedef struct student
{
	stu_data *data;
	struct student *next;
}stu;


typedef struct {
	char type[50];
	int type_num;
	int count;
	struct student *next;
}COUNT;

typedef struct Revise
{
	stu *p_data;
	struct Revise *next;
}REVISE;

void menu(head);


stu *create_new();
stu *create_open();
stu* add(stu *head, stu *pnew, int choose);
stu *del(stu *head,int no);


stu *revise(stu *head);
stu *revise_no(stu *head);
stu *revise_name(stu *head);
stu *revise_age(stu *head);
stu *revise_dept(stu *head);
stu *revise_score(stu *head);
stu *revise_sex(stu *head);

void search(stu *head);
int found_sum(stu *head);
void output_found_num(int n);
void output_found_linklist(COUNT *head);
COUNT *found_sex(stu*head);
REVISE *found_by_no(stu* head,int no);
int found_by_firstname(stu *head, char *name);
stu *age_add(stu *head,char *name);
COUNT *found_dept(stu *head);
COUNT *found_age(stu *head);
REVISE *found_max_age(stu* head);


void free_linklist(stu *head);
void free_revise_linklist(REVISE *head);
void savefile(head);
void output_linklist(stu* head);
void output_revise_linklist(REVISE *head);
void output_found_linklist_num(COUNT *head);


int main()
{
	stu* head = create_open();
	menu(head);
	return 0;
}


void menu(stu *head)
{
	while (1)
	{
		output_linklist(head);
		SPACE; puts("1���½�ѧ������");
		SPACE; puts("2������ѧ��");
		SPACE; puts("3��ɾ��ѧ��");
		SPACE; puts("4���޸�ѧ����Ϣ");
		SPACE; puts("5����ѯѧ����Ϣ");
		SPACE; puts("0���˳�");
		char choose;
		choose = getch();
		switch (choose)
		{
		case '1':head = create_new(); break;
		case '2': {
			printf("\n\n\n******** add student ********\n\n");
			stu *pnew = (stu *)malloc(sizeof(stu));
			pnew->data = (stu_data*)malloc(sizeof(stu_data));
			printf("Please input the pnew student's information.\nnew stu's��\n no\tage\tname\tsex\tdept\tscore\n");
			scanf("%d%d%s%s%s%d", &pnew->data->no, &pnew->data->age, &pnew->data->name, &pnew->data->sex, &pnew->data->dept, &pnew->data->score); getchar();
			printf("1��add to the first.\t2��add to the last.\t3��other.");
			int choose;
			while (1)
			{
				scanf("%d", &choose); getchar();
				if (choose == 1 || choose == 2 || choose == 3)break;
				printf("Input wrong!please reenter:");
			}
			head = add(head,pnew,choose);
			break;
		}
		case '3':{
			printf("\n\n\n******** delete student ********\n\n");
			printf("Please input the student's NO that you want delete��");
			int no;
			scanf("%d", &no); getchar();
			head = del(head, no);
			break;
		}
		case '4':head = revise(head); break;
		case '5':search(head); break;
		case '0':exit();
		}
	}
}


void output_found_linklist(COUNT *head)
{
	COUNT *p = head;
	system("cls");
	puts("���\t����");
	while (p != NULL)
	{
		printf("%s:\t%d�ˡ�\n",p->type, p->count);
		p = p->next;
	}
	system("pause");
}
void output_found_linklist_num(COUNT *head)
{
	COUNT *p = head;
	system("cls");
	puts("���\t����");
	while (p != NULL)
	{
		printf("%d:\t%d�ˡ�\n", p->type_num, p->count);
		p = p->next;
	}
	system("pause");
}
void free_found_linklist(COUNT *head)
{
	COUNT *p = head;
	while (p != NULL)
	{
		head = p->next;
		free(p);
		p = head;
	}
	free(head);
}

void output_found_num(int n)
{
	system("cls");
	printf("\nAltogether %d people!\n", n);
	system("pause");
}


void free_revise_linklist(REVISE *head)
{
	REVISE *p = head;
	while (p != NULL)
	{
		p = p->next;
		free(head);
		head = p;
	}
	free(head);
}

void output_revise_linklist(REVISE *head)
{
	int n = 0;
	system("cls");
	REVISE *p;
	p = head;
	SPACE; printf("******** student's information ********\n");
	SPACE; puts("No\tName\tAge\tsex\tdept\tscore");
	while (p != NULL)
	{
		SPACE; printf("%d\t%s\t%d\t%s\t%s\t%d\n", p->p_data->data->no, p->p_data->data->name, p->p_data->data->age, p->p_data->data->sex, p->p_data->data->dept, p->p_data->data->score);
		n++;
		p = p->next;
	}
	SPACE; printf("=== altogether %d people ===\n\n", n);
	system("pause");
}

stu* add(stu *head,stu *pnew,int choose)//���ѧ��
{

	stu *p1, *p2;
	p1 = p2 = head;
	if (head == NULL)
	{
		head = pnew;
		pnew->next = p1;
		savefile(head);
		return head;
	}
		switch (choose)
		{
		case 1://�嵽�׽ڵ�
		{
			head = pnew;
			pnew->next = p1;
			break;
		}
		case 2://�嵽ĩ�ڵ�
		{
			while (p1->next != NULL)
			{
				p1 = p1->next;
			}
			pnew->next = p1->next;
			p1->next = pnew;
			break;
		}

		case 3://��Ϊ�м�ڵ�
		{
			printf("add before (input NO)��");
			int pnew_no;
			scanf("%d", &pnew_no); getchar();
			if (p1->data->no != pnew_no)
			{
				while (p1->data->no != pnew_no)//ѭ�����ڲ���Ŀ��ѧ��
				{
					p2 = p1;
					p1 = p1->next;
				}
			}
			else p1 = p1->next;
			p2->next = pnew;//����ĺ��Ĵ���
			pnew->next = p1;
			break;
		}
		}
	savefile(head);
	return head;
}



stu *age_add(stu *head,char *name)
{
	if (head == NULL)
	{
		printf("NO student!");
		system("pause");
		return 0;
	}
	stu *p = head;
	while (p != NULL)
	{
		if (strcmp(p->data->name, name) == 0)
		{
			p->data->age++;
		}
		p = p->next;
	}
	savefile(head);
	return head;
}


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


stu* del(stu *head,int no)//ɾ��ѧ��
{
	if (head == NULL)
	{
		puts("No student!");
		system("pause");
		return head;
	}
	stu *p1, *p2;
	p1 = p2 = head;
	if (p1->data->no == no)//ɾ���׽ڵ�ʱ��������
	{
		head = p1->next;
	}
	else
	{
		while (p1->data->no != no)//ѭ�����ڲ���Ŀ��
		{
			p2 = p1;
			p1 = p1->next;
		}
		p2->next = p1->next;//ɾ���ĺ��ĵĴ���
	}
	free(p1);
	savefile(head);
	return head;
}


COUNT *found_age(stu *head)
{
	if (head == NULL)
	{
		return head;
	}
	stu *p = head;
	COUNT *head_found_age = (COUNT *)calloc(1, sizeof(COUNT));
	COUNT *fdp = head_found_age, *fdq = head_found_age;
	while (p != NULL)
	{
		if (p == head)
		{
			fdp->type_num = p->data->age;
			fdp->count = 1;
			fdp->next = NULL;
		}
		else {
			for (fdp = head_found_age;; fdp = fdp->next)
			{
				if (p->data->age == fdp->type_num)
				{
					fdp->count++;
					break;
				}
				if (fdp->next == NULL)
				{
					fdq = (COUNT*)calloc(1, sizeof(COUNT));
					fdp->next = fdq;
					fdp = fdq;
					fdp->type_num = p->data->age;
					fdp->count = 1;
					fdp->next = NULL;
					break;
				}
			}
		}
		p = p->next;
	}
	return head_found_age;
}


int found_by_firstname(stu *head, char *firstname)//����
{
	if (head == NULL)
	{
		return head;
	}
	int n = 0;
		int i;
		stu *p = head;
		while (p != NULL)
		{
			for (i = 0; firstname[i] != '\0'; i++)
			{
				if (p->data->name[i] == firstname[i])continue;
				else break;
			}
			if (firstname[i] == '\0')n++;
			p = p->next;
		}
		return n;
}


REVISE *found_by_no(stu * head, int no)  //ͳ��ѧ����ͬ��ѧ������
{
	if (head == NULL)
	{
		return head;
	}
	stu *p = head;
	//����������������Ŀ��ѧ��
	REVISE *new_head, *p1, *p2;
	new_head = p1 = p2 = (REVISE*)calloc(1, sizeof(REVISE));
	while (p != NULL)//ѭ�����ڲ���Ŀ��ѧ��
	{
		if (p->data->no == no)
		{
			p1 = p2;
			p1->p_data = p;
			p2 = (REVISE*)calloc(1, sizeof(REVISE));
			p1->next = p2;
		}
		p = p->next;
	}
	p1->next = p2 = NULL;
	return new_head;
}


COUNT *found_dept(stu *head)
{
	if (head == NULL)
	{
		return head;
	}
	stu *p = head;
	COUNT *head_found_dept = (COUNT *)calloc(1, sizeof(COUNT));
	COUNT *fdp = head_found_dept, *fdq = head_found_dept;
	while (p != NULL)
	{
		if (p == head)
		{
			strcpy(fdp->type, p->data->dept);
			fdp->count = 1;
			fdp->next = NULL;
		}
		else 
		{
			for (fdp = head_found_dept;; fdp = fdp->next)
			{
				if ((strcmp(p->data->dept, fdp->type)) == 0)
				{
					fdp->count++;
					break;
				}
				if (fdp->next == NULL)
				{
					fdq = (COUNT*)calloc(1, sizeof(COUNT));
					fdp->next = fdq;
					fdp = fdq;
					strcpy(fdp->type, p->data->dept);
					fdp->count = 1;
					fdp->next = NULL;
					break;
				}
			}
		}
		p = p->next;
	}
	return head_found_dept;
}


REVISE *found_max_age(stu *head)
{
	if (head == NULL)
	{
		return head;
	}
	stu *p = head;
	REVISE *p_max=(REVISE *)calloc(sizeof(REVISE)),*head_max=(REVISE *)calloc(1,sizeof(REVISE));
	REVISE *p1 = head_max, *p2;
	p_max->p_data = p;
	while(p != NULL)
	{
		if (strcmp(p->data->sex, "Ů") == 0)
		{
			if (p_max->p_data->data->age < p->data->age)
			{
                p_max->p_data = p;
			}
		}	
		p = p->next;
	}
	p = head;
	p2=p1 = head_max;
	while (p != NULL)//ѭ�����ڲ���Ŀ��ѧ��
	{
		if (p->data->age == p_max->p_data->data->age&& (strcmp(p->data->sex, "��")) == 0)
		{
			p1 = p2;
			p1->p_data = p;
			p2 = (REVISE*)calloc(1, sizeof(REVISE));
			p1->next = p2;
		}
		p = p->next;
	}
	p1->next = p2 = NULL;
	if (head_max->p_data == NULL)head_max=NULL;
	return head_max;
}


COUNT *found_sex(stu *head)
{
	if (head == NULL)
	{
		return head;
	}
	stu *p = head;
	COUNT *head_found_sex = (COUNT *)calloc(1, sizeof(COUNT));
	COUNT *fdp = head_found_sex, *fdq = head_found_sex;
	while (p != NULL)
	{
		if (p == head)
		{
			strcpy(fdp->type, p->data->sex);
			fdp->count = 1;
			fdp->next = NULL;
		}
		else {
			for (fdp = head_found_sex;; fdp = fdp->next)
			{
				if ((strcmp(p->data->sex, fdp->type)) == 0)
				{
					fdp->count++;
					break;
				}
				if (fdp->next == NULL)
				{
					fdq = (COUNT*)calloc(1, sizeof(COUNT));
					fdp->next = fdq;
					fdp = fdq;
					strcpy(fdp->type, p->data->sex);
					fdp->count = 1;
					fdp->next = NULL;
					break;
				}
			}
		}
		p = p -> next;
	}
	return head_found_sex;
}



int found_sum(head)
{
	int sum = 0;
	stu* p = head;
	while (p != NULL)
	{
		sum++;
		p = p -> next;
	}
	return sum;
}


void free_linklist(stu *head)  //�ͷŲ�Ҫ������
{
	stu *p;
	p = head;
	while (head->next != NULL)
	{
		head = head->next;
		free(p->data);
		free(p);
		p = head;
	}
	free(p->data);
	free(head);
}


void output_linklist(stu *head)//���ѧ����Ϣ
{
	int n = 0;
	system("cls");
	stu *p;
	p = head;
	SPACE; printf("******** student's information ********\n");
	SPACE; puts("No\tName\tAge\tsex\tdept\tscore");
	while (p != NULL)
	{
		SPACE; printf("%d\t%s\t%d\t%s\t%s\t%d\n", p->data->no, p->data->name, p->data->age, p->data->sex, p->data->dept, p->data->score);
		n++;
		p = p->next;
	}
	SPACE; printf("=== altogether %d people ===\n\n", n);
}


stu* revise(stu *head)//�޸�ѧ����Ϣ
{
	printf("\n\n******** revise student's information ********\n");
	if (head == NULL)
	{
		puts("No student!");
		system("pause");
		return head;
	}
	//char content[10];
	char choose;
	
	
	while (1)//ѭ�� ���ڼ���������룬����������
	{
		printf("1��revise No.\n2��revise age.\n3��revise name.\n4��revise sex.\n5��revise dept.\n6��revise score.\n0��return upper menu.\n");
		choose = getch();
		switch (choose)
		{
			//��������޸ĵ�����
		case '1':head = revise_no(head);  return head;
		case '2':head=revise_age(head);  return head;
		case '3':head=revise_name(head);  return head;
		case '4':head=revise_sex(head);  return head;
		case '5':head=revise_dept(head);  return head;
		case '6':head=revise_score(head);  return head;
		case '0':menu(head);
		}
		puts("input wrong!please reenter:");
	}
}

stu* revise_age(stu *head)
{
	int age;
	printf("Please input the old age:");
	scanf("%d", &age); getchar();
	int n = 0;
	stu *p = head;
	stu *new_head, *p1, *p2;
	new_head = p1 = p2 = (stu*)calloc(1, sizeof(stu));
	p1->data = (stu_data*)malloc(sizeof(stu_data));
	while (p != NULL)
	{
		if (p->data->age == age)
		{
			p1 = p2;
			p1->data = p->data;
			p2 = (stu*)calloc(1, sizeof(stu));
			p2->data = (stu_data*)malloc(sizeof(stu_data));
			p1->next = p2;
			n++;
		}
		p = p->next;
	}
	p1->next = p2 = NULL;
	if (n == 0)
	{
		puts("Not found!");
		free(new_head);
	}

	if (n == 1)
	{
		for (p = head; p != NULL; p = p->next)
		{
			if ((p->data->no == new_head->data->no) && (p->data->age == new_head->data->age) && (strcmp(p->data->name, new_head->data->name) == 0) && (strcmp(p->data->sex, new_head->data->sex) == 0) && (strcmp(p->data->dept, new_head->data->dept) == 0))
				break;
		}
		puts("Please input the new age:");
		scanf("%d", &p1->data->age); getchar();
		free(new_head);
	}
	else
	{
		output_linklist(new_head);
		puts("Please choose(input line number):");
		p1 = new_head;
		while (1)
		{
			int line_number;
			scanf("%d", &line_number); getchar();
			for (n = 1; p1 != NULL&&n != line_number&&!(n<2); p1 = p1->next)
			{
				n++;
			}
			if (p1 == NULL)puts("wrong!please reenter:");
			else break;
		}
		puts("Please input new age:");
		for (p = head; p != NULL; p = p->next)
		{
			if ((p->data->no == p1->data->no) && (p->data->age == p1->data->age) && (strcmp(p->data->name, p1->data->name) == 0) && (strcmp(p->data->sex, p1->data->sex) == 0) && (strcmp(p->data->dept, p1->data->dept) == 0))
			{
				scanf("%d", &p->data->age);
			}
		}
		free_linklist(new_head);
	}
	savefile(head);
	return head;
}

stu *revise_dept(stu *head)
{
	char dept[25];
	printf("Please input the old dept:");
	gets(dept);
	int n = 0;
	stu *p = head;
	REVISE *new_head, *p1, *p2;
	new_head = p1 = p2 = (REVISE*)calloc(1, sizeof(REVISE));
	while (p != NULL)
	{
		if (strcmp(p->data->dept, dept) == 0)
		{
			p1 = p2;
			p1->p_data = p;
			p2 = (REVISE*)calloc(1, sizeof(REVISE));
			p1->next = p2;
			n++;
		}
		p = p->next;
	}
	p1->next = p2 = NULL;
	if (n == 0)
	{
		puts("Not found!");
		free(new_head);
	}

	if (n == 1)
	{
		for (p = head; p != NULL; p = p->next)
		{
			if ((p->data->no == new_head->p_data->data->no) && (p->data->age == new_head->p_data->data->age) && (strcmp(p->data->name, new_head->p_data->data->name) == 0) && (strcmp(p->data->sex, new_head->p_data->data->sex) == 0) && (strcmp(p->data->dept, new_head->p_data->data->dept) == 0))
				break;
		}
		puts("Please input the new dept:");
		gets(p->data->dept);
		free(new_head);
	}
	else
	{
		output_revise_linklist(new_head);
		puts("Please choose(input line number):");
		p1 = new_head;
		while (1)
		{
			int line_number;
			scanf("%d", &line_number); getchar();
			for (n = 1; p1 != NULL&&n != line_number; p1 = p1->next)
			{
				n++;
			}
			if (p1 == NULL)puts("wrong!please reenter:");
			else break;
		}
		puts("Please input new dept:");
		for (p = head; p != NULL; p = p->next)
		{
			if ((p->data->no == p1->p_data->data->no) && (p->data->age == p1->p_data->data->age) && (strcmp(p->data->name, p1->p_data->data->name) == 0) && (strcmp(p->data->sex, p1->p_data->data->sex) == 0) && (strcmp(p->data->dept, p1->p_data->data->dept) == 0))
			{
				gets(p->data->dept);
			}
		}
		free_revise_linklist(new_head);
	}
	savefile(head);
	return head;
}

stu* revise_name(stu *head)
{
	char name[20];
	printf("Please input the old name:");
	gets(name);
	int n = 0;
	stu *p = head;
	stu *new_head, *p1, *p2;
	new_head = p1 = p2 = (stu*)calloc(1, sizeof(stu));
	p1->data = (stu_data*)malloc(sizeof(stu_data));
	while (p != NULL)
	{
		if (strcmp(p->data->name, name) == 0)
		{
			p1 = p2;
			p1->data = p->data;
			p2 = (stu*)calloc(1, sizeof(stu));
			p2->data = (stu_data*)malloc(sizeof(stu_data));
			p1->next = p2;
			n++;
		}
		p = p->next;
	}
	p1->next = p2 = NULL;
	if (n == 0)
	{
		puts("Not found!");
		free(new_head);
	}

	if (n == 1)
	{
		for (p = head; p != NULL; p = p->next)
		{
			if ((p->data->no == new_head->data->no) && (p->data->age == new_head->data->age) && (strcmp(p->data->name, new_head->data->name) == 0) && (strcmp(p->data->sex, new_head->data->sex) == 0) && (strcmp(p->data->dept, new_head->data->dept) == 0))
				break;
		}
		puts("Please input the new name:");
		gets(p->data->name);
		free(new_head);
	}
	else
	{
		output_linklist(new_head);
		puts("Please choose(input line number):");
		p1 = new_head;
		while (1)
		{
			int line_number;
			scanf("%d", &line_number); getchar();
			for (n = 1; p1 != NULL&&n != line_number&&!(n<2); p1 = p1->next)
			{
				n++;
			}
			if (p1 == NULL)puts("wrong!please reenter:");
			else break;
		}
		puts("Please input new name:");
		for (p = head; p != NULL; p = p->next)
		{
			if ((p->data->no == p1->data->no) && (p->data->age == p1->data->age) && (strcmp(p->data->name, p1->data->name) == 0) && (strcmp(p->data->sex, p1->data->sex) == 0) && (strcmp(p->data->dept, p1->data->dept) == 0))
			{
				gets(p->data->name);
			}
		}
		free_linklist(new_head);
	}
	savefile(head);
	return head;
}
stu* revise_no(stu* head)//�޸�ѧ��
{
	int no;
	printf("Please input the old NO:");
	scanf("%d", &no); getchar();
	int n = 0;
	stu *p = head;
	//�����µ�������Ŀ��ѧ��
	stu *new_head, *p1, *p2;
	new_head = p1 = p2 = (stu*)calloc(1, sizeof(stu));
	p1->data = (stu_data*)malloc(sizeof(stu_data));
	while (p != NULL)//ѭ����������
	{
		if (p->data->no == no)
		{
			p1 = p2;
			p1->data = p->data;
			p2 = (stu*)calloc(1, sizeof(stu));
			p2->data = (stu_data*)malloc(sizeof(stu_data));
			p1->next = p2;
			n++;
		}
		p = p->next;
	}
	p1->next = p2 = NULL;
	if (n == 0)//û���ҵ�Ŀ��ѧ��
	{
		puts("Not found!");
		free(new_head);
	}

	if (n == 1)//ֻ��һ��Ŀ��ѧ��ʱ
	{
		for (p = head; p != NULL; p = p->next)//ѭ�����ڲ���Դ�����е�ѧ��
		{
			if ((p->data->no == new_head->data->no) && (p->data->age == new_head->data->age) && (strcmp(p->data->name, new_head->data->name) == 0) && (strcmp(p->data->sex, new_head->data->sex) == 0) && (strcmp(p->data->dept, new_head->data->dept) == 0))
				break;
		}
		puts("Please input the new NO:");
		scanf("%d", &p1->data->no); getchar();
		free(new_head);
	}
	else//�ж��Ŀ��ѧ��ʱ
	{
		output_linklist(new_head);
		puts("Please choose(input line number):");
		p1 = new_head;
		while (1)//ѭ������ѡ��ѧ�������������¼��
		{
			int line_number;
			scanf("%d", &line_number); getchar();
			for (n = 1; p1 != NULL&&n != line_number&&!(n<2); p1 = p1->next)
			{
				n++;
			}
			if (p1 == NULL)puts("wrong!please reenter:");
			else break;
		}
		puts("Please input new NO:");
		//ѭ��������ԭ�����в���Ŀ��ѧ��
		for (p = head; p != NULL; p = p->next)
		{
			if ((p->data->no == p1->data->no) && (p->data->age == p1->data->age) && (strcmp(p->data->name, p1->data->name) == 0) && (strcmp(p->data->sex, p1->data->sex) == 0) && (strcmp(p->data->dept, p1->data->dept) == 0))
			{
				scanf("%d", &p->data->no);
			}
		}
		free_linklist(new_head);
	}
	savefile(head);//�����޸�
	return head;
}


stu* revise_score(stu *head)
{
	int score;
	printf("Please input the old dept:");
	scanf("%d", &score); getchar();
	int n = 0;
	stu *p = head;
	stu *new_head, *p1, *p2;
	new_head = p1 = p2 = (stu*)calloc(1, sizeof(stu));
	p1->data = (stu_data*)malloc(sizeof(stu_data));
	while (p != NULL)
	{
		if (strcmp(p->data->score, score) == 0)
		{
			p1 = p2;
			p1->data = p->data;
			p2 = (stu*)calloc(1, sizeof(stu));
			p2->data = (stu_data*)malloc(sizeof(stu_data));
			p1->next = p2;
			n++;
		}
		p = p->next;
	}
	p1->next = p2 = NULL;
	if (n == 0)
	{
		puts("Not found!");
		free(new_head);
	}

	if (n == 1)
	{
		for (p = head; p != NULL; p = p->next)
		{
			if ((p->data->no == new_head->data->no) && (p->data->age == new_head->data->age) && (strcmp(p->data->name, new_head->data->name) == 0) && (strcmp(p->data->sex, new_head->data->sex) == 0) && (strcmp(p->data->dept, new_head->data->dept) == 0))
				break;
		}
		puts("Please input the new score:");
		scanf("%d", &p->data->score);
		free(new_head);
	}
	else
	{
		output_linklist(new_head);
		puts("Please choose(input line number):");
		p1 = new_head;
		while (1)
		{
			int line_number;
			scanf("%d", &line_number); getchar();
			for (n = 1; p1 != NULL&&n != line_number&&!(n<2); p1 = p1->next)
			{
				n++;
			}
			if (p1 == NULL)puts("wrong!please reenter:");
			else break;
		}
		puts("Please input new score:");
		for (p = head; p != NULL; p = p->next)
		{
			if ((p->data->no == p1->data->no) && (p->data->age == p1->data->age) && (strcmp(p->data->name, p1->data->name) == 0) && (strcmp(p->data->sex, p1->data->sex) == 0) && (strcmp(p->data->dept, p1->data->dept) == 0))
			{
				scanf("%d", &p->data->score);
			}
		}
		free_linklist(new_head);
	}
	savefile(head);
	return head;
}



stu* revise_sex(stu *head)
{
	char sex[6];
	printf("Please input the old sex:");
	gets(sex);
	int n = 0;
	stu *p = head;
	stu *new_head, *p1, *p2;
	new_head = p1 = p2 = (stu*)calloc(1, sizeof(stu));
	p1->data = (stu_data*)malloc(sizeof(stu_data));
	while (p != NULL)
	{
		if (strcmp(p->data->sex, sex) == 0)
		{
			p1 = p2;
			p1->data = p->data;
			p2 = (stu*)calloc(1, sizeof(stu));
			p2->data = (stu_data*)malloc(sizeof(stu_data));
			p1->next = p2;
			n++;
		}
		p = p->next;
	}
	p1->next = p2 = NULL;
	if (n == 0)
	{
		puts("Not found!");
		free(new_head);
	}

	if (n == 1)
	{
		for (p = head; p != NULL; p = p->next)
		{
			if ((p->data->no == new_head->data->no) && (p->data->age == new_head->data->age) && (strcmp(p->data->name, new_head->data->name) == 0) && (strcmp(p->data->sex, new_head->data->sex) == 0) && (strcmp(p->data->dept, new_head->data->dept) == 0))
				break;
		}
		puts("Please input the new sex:");
		gets(p->data->sex);
		free(new_head);
	}
	else
	{
		output_linklist(new_head);
		puts("Please choose(input line number):");
		p1 = new_head;
		while (1)
		{
			int line_number;
			scanf("%d", &line_number); getchar();
			for (n = 1; p1 != NULL&&n != line_number; p1 = p1->next)
			{
				n++;
			}
			if (p1 == NULL)puts("wrong!please reenter:");
			else break;
		}
		puts("Please input new sex:");
		for (p = head; p != NULL; p = p->next)
		{
			if ((p->data->no == p1->data->no) && (p->data->age == p1->data->age) && (strcmp(p->data->name, p1->data->name) == 0) && (strcmp(p->data->sex, p1->data->sex) == 0) && (strcmp(p->data->dept, p1->data->dept) == 0))
			{
				gets(p->data->sex);
			}
		}
		free_linklist(new_head);
	}
	savefile(head);
	return head;
}


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


void search(stu *head)
{
	if (head == NULL)
	{
		puts("No student!");
		system("pause");
		return head;
	}
	char choose;
	while (1)
	{
		output_linklist(head);
		puts("1����ѯѧ������");
		puts("2����ѯ��Ů��������");
		puts("3����ѧ�Ų�ѯѧ��ȫ����Ϣ");
		puts("4�������ϲ�ѯѧ������");
		puts("5����ĳѧ�������һ");
		puts("6����ѯÿ��ϵ�������Ƕ���");
		puts("7����ѯÿ�������Ӧ�������ֱ��Ƕ���");
		puts("8����ѯ��Ů�����������ͬ����������Ϣ");
		puts("0��������һ���˵�");
		int n = 0;
		choose = getch();
		switch (choose)
		{
		case '1': {
			n = found_sum(head);
			output_found_num(n); 
			break;
		}
		case '2':
		{
			REVISE *head_found_sex=found_sex(head);
			output_found_linklist(head_found_sex);
			break;
		}
		case '3': {
			int no;
			printf("please input no:");
			scanf("%d", &no); getchar();
			REVISE *student_linklist = found_by_no(head,no);
			output_revise_linklist(student_linklist);
			break;
		}
		case '4': {
			char firstname[20];
			printf("please input fristname:");
			gets(firstname);
			int n = found_by_firstname(head,firstname);
			system("cls");
			printf("��%s������Ϊ��%d��.",firstname,n);
			system("pause");
			break;
		}
		case '5': {
			char name[20];
			printf("please input the name:");
			gets(name);
			head = age_add(head,name);
			output_linklist(head);
			break;
		}
		case '6': {
			COUNT *head_dept = found_dept(head);
			output_found_linklist(head_dept);
			break;
		}
		case '7': {
			COUNT *head_age = found_age(head);
			output_found_linklist_num(head_age);
			break;
		}
		case '8': {
			REVISE *head_max_age = found_max_age(head);
			output_revise_linklist(head_max_age);
			break;
		}
		case '0':menu(head);
		}
	}
}