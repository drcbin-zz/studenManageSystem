#include"header.h"
void search(stu *head,course* C_head,student_course *SC_head)
{
	if (head == NULL)
	{
		puts("No student!");
		system("pause");
		return head;
	}
	int choose;
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
		puts("9����ѯ��Ů��ƽ���ɼ����Ƕ���");
		puts("10��ͳ��ÿ���γ̵�ѡ������");
		puts("0��������һ���˵�");
		int n = 0;
		scanf("%d", &choose); getchar();
		switch (choose)
		{
		case 1: {
			n = found_sum(head);
			output_found_num(n); 
			break;
		}
		case 2:
		{
			REVISE *head_found_sex=found_sex(head);
			output_found_linklist(head_found_sex);
			break;
		}
		case 3: {
			int no;
			printf("please input no:");
			scanf("%d", &no); getchar();
			REVISE *student_linklist = found_by_no(head,no);
			output_revise_linklist(student_linklist);
			break;
		}
		case 4: {
			char firstname[20];
			printf("please input fristname:");
			gets(firstname);
			int n = found_by_firstname(head,firstname);
			system("cls");
			printf("��%s������Ϊ��%d��.",firstname,n);
			system("pause");
			break;
		}
		case 5: {
			char name[20];
			printf("please input the name:");
			gets(name);
			head = age_add(head,name);
			output_linklist(head);
			break;
		}
		case 6: {
			COUNT *head_dept = found_dept(head);
			output_found_linklist(head_dept);
			break;
		}
		case 7: {
			COUNT *head_age = found_age(head);
			output_found_linklist_num(head_age);
			break;
		}
		case 8: {
			REVISE *head_max_age = found_max_age(head);
			output_revise_linklist(head_max_age);
			break;
		}
		case 9: {
			COUNT *head_average = count_average(head);
			output_count_score(head_average);
			break;
		}
		case 10: {
			COUNT *ccn_head = count_course_num(C_head, SC_head);
			output_ccn(ccn_head);
			break;
		}
		case 0:menu(head,C_head,SC_head);
		}
	}
}