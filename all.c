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
		SPACE; puts("1、新建学生链表");
		SPACE; puts("2、插入学生");
		SPACE; puts("3、删除学生");
		SPACE; puts("4、修改学生信息");
		SPACE; puts("5、查询学生信息");
		SPACE; puts("0、退出");
		char choose;
		choose = getch();
		switch (choose)
		{
		case '1':head = create_new(); break;
		case '2': {
			printf("\n\n\n******** add student ********\n\n");
			stu *pnew = (stu *)malloc(sizeof(stu));
			pnew->data = (stu_data*)malloc(sizeof(stu_data));
			printf("Please input the pnew student's information.\nnew stu's：\n no\tage\tname\tsex\tdept\tscore\n");
			scanf("%d%d%s%s%s%d", &pnew->data->no, &pnew->data->age, &pnew->data->name, &pnew->data->sex, &pnew->data->dept, &pnew->data->score); getchar();
			printf("1、add to the first.\t2、add to the last.\t3、other.");
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
			printf("Please input the student's NO that you want delete：");
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
	puts("类别\t人数");
	while (p != NULL)
	{
		printf("%s:\t%d人。\n",p->type, p->count);
		p = p->next;
	}
	system("pause");
}
void output_found_linklist_num(COUNT *head)
{
	COUNT *p = head;
	system("cls");
	puts("类别\t人数");
	while (p != NULL)
	{
		printf("%d:\t%d人。\n", p->type_num, p->count);
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

stu* add(stu *head,stu *pnew,int choose)//添加学生
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
		case 1://插到首节点
		{
			head = pnew;
			pnew->next = p1;
			break;
		}
		case 2://插到末节点
		{
			while (p1->next != NULL)
			{
				p1 = p1->next;
			}
			pnew->next = p1->next;
			p1->next = pnew;
			break;
		}

		case 3://插为中间节点
		{
			printf("add before (input NO)：");
			int pnew_no;
			scanf("%d", &pnew_no); getchar();
			if (p1->data->no != pnew_no)
			{
				while (p1->data->no != pnew_no)//循环用于查找目标学生
				{
					p2 = p1;
					p1 = p1->next;
				}
			}
			else p1 = p1->next;
			p2->next = pnew;//插入的核心代码
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


stu *create_new()//创建链表
{
	int count = 0;
	FILE *fp;
	if ((fp = fopen("d:\\student list.txt", "w+")) == NULL)//新建文件
	{
		puts("create fail!");
		exit(0);
	}
	//开始录入首节点，首节点单独处理
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
	while (1)//循环用于检测错误的输入，并重新录入
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
	while (1)//循环用于检测错误
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
	while (1)//循环用于检测错误的输入，并重新录入
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
	while (p1->data->no != 0)//循环用于录入节点信息，当学号为0时，结束录入
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
		if (p1->data->no == 0 || p1->data->no < 0)//判断是否停止
		{
			break;
		}
		printf("age:");
		while (1)//循环用于检测错误的录入
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
		while (1)//循环用于检测错误的输入，并重新录入
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
	savefile(head);//保存修改的文件
	return head;
}


stu *create_open()//打开现有链表
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
		while (fread(p->data, sizeof(stu_data), 1, fp) == 1)//读取文件数据
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


stu* del(stu *head,int no)//删除学生
{
	if (head == NULL)
	{
		puts("No student!");
		system("pause");
		return head;
	}
	stu *p1, *p2;
	p1 = p2 = head;
	if (p1->data->no == no)//删除首节点时单独处理
	{
		head = p1->next;
	}
	else
	{
		while (p1->data->no != no)//循环用于查找目标
		{
			p2 = p1;
			p1 = p1->next;
		}
		p2->next = p1->next;//删除的核心的代码
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


int found_by_firstname(stu *head, char *firstname)//错误
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


REVISE *found_by_no(stu * head, int no)  //统计学号相同的学生人数
{
	if (head == NULL)
	{
		return head;
	}
	stu *p = head;
	//开创新链表来保存目标学生
	REVISE *new_head, *p1, *p2;
	new_head = p1 = p2 = (REVISE*)calloc(1, sizeof(REVISE));
	while (p != NULL)//循环用于查找目标学生
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
		if (strcmp(p->data->sex, "女") == 0)
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
	while (p != NULL)//循环用于查找目标学生
	{
		if (p->data->age == p_max->p_data->data->age&& (strcmp(p->data->sex, "男")) == 0)
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


void free_linklist(stu *head)  //释放不要的链表
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


void output_linklist(stu *head)//输出学生信息
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


stu* revise(stu *head)//修改学生信息
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
	
	
	while (1)//循环 用于检测错误的输入，并重新输入
	{
		printf("1、revise No.\n2、revise age.\n3、revise name.\n4、revise sex.\n5、revise dept.\n6、revise score.\n0、return upper menu.\n");
		choose = getch();
		switch (choose)
		{
			//五个可以修改的内容
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
stu* revise_no(stu* head)//修改学号
{
	int no;
	printf("Please input the old NO:");
	scanf("%d", &no); getchar();
	int n = 0;
	stu *p = head;
	//创建新的链表保存目标学生
	stu *new_head, *p1, *p2;
	new_head = p1 = p2 = (stu*)calloc(1, sizeof(stu));
	p1->data = (stu_data*)malloc(sizeof(stu_data));
	while (p != NULL)//循环遍历链表
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
	if (n == 0)//没有找到目标学生
	{
		puts("Not found!");
		free(new_head);
	}

	if (n == 1)//只有一个目标学生时
	{
		for (p = head; p != NULL; p = p->next)//循环用于查找源链表中的学生
		{
			if ((p->data->no == new_head->data->no) && (p->data->age == new_head->data->age) && (strcmp(p->data->name, new_head->data->name) == 0) && (strcmp(p->data->sex, new_head->data->sex) == 0) && (strcmp(p->data->dept, new_head->data->dept) == 0))
				break;
		}
		puts("Please input the new NO:");
		scanf("%d", &p1->data->no); getchar();
		free(new_head);
	}
	else//有多个目标学生时
	{
		output_linklist(new_head);
		puts("Please choose(input line number):");
		p1 = new_head;
		while (1)//循环用于选定学生，并检测错误的录入
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
		//循环用于在原链表中查找目标学生
		for (p = head; p != NULL; p = p->next)
		{
			if ((p->data->no == p1->data->no) && (p->data->age == p1->data->age) && (strcmp(p->data->name, p1->data->name) == 0) && (strcmp(p->data->sex, p1->data->sex) == 0) && (strcmp(p->data->dept, p1->data->dept) == 0))
			{
				scanf("%d", &p->data->no);
			}
		}
		free_linklist(new_head);
	}
	savefile(head);//保存修改
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
		puts("1、查询学生人数");
		puts("2、查询男女生各人数");
		puts("3、按学号查询学生全部信息");
		puts("4、按姓氏查询学生人数");
		puts("5、将某学生年龄加一");
		puts("6、查询每个系人数各是多少");
		puts("7、查询每个年龄对应的人数分别是多少");
		puts("8、查询与女生最大年龄相同的男生的信息");
		puts("0、返回上一级菜单");
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
			printf("姓%s的人数为：%d个.",firstname,n);
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