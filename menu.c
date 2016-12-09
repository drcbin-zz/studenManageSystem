#include"header.h"
void menu(stu *head,course *C_head,student_course *SC_head)
{
	while (1)
	{
		output_linklist(head);
		SPACE; puts("1、新建学生链表");
		SPACE; puts("2、插入学生");
		SPACE; puts("3、删除学生");
		SPACE; puts("4、修改学生信息");
		SPACE; puts("5、查询学生信息");
		SPACE; puts("6、新建课程信息");
		SPACE; puts("7、查看课程信息");
		SPACE; puts("8、新建学生选课信息");
		SPACE; puts("9、查看学生选课程信息");
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
		case '4':head = revise(head,C_head,SC_head); break;
		case '5':search(head,C_head,SC_head); break;
		case '6': {system("cls");
			C_head = create_course();
			break;
		}
		case '7': {
			output_course(C_head);
			break;
		}
		case '8': {
			SC_head = create_sc();
			break;
		}
		case '9': {
			output_student_course(SC_head);
			break;
		}
		case '0':exit();
		}
	}
}