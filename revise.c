#include"header.h"
stu* revise(stu *head,course *C_head,student_course *SC_head)//修改学生信息
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
		case '0':menu(head,C_head,SC_head);
		}
		puts("input wrong!please reenter:");
	}
}