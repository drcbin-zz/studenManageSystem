#include"myheader.h"
void look_over_stu_infor_menu(STU *head)
{
	char look_over_choose;
	while (1)
	{
		system("cls");
		puts(
			"1����ѧ������\n"
			"2������������\n"
			"3������������\n"
			"4�����Ա�����\n"
			"5�����ɼ�����\n"
			"6����¼��˳��\n"
			"0������\n"
			);
		puts("��ѡ������ʽ��");
		look_over_choose = getch();
		switch (look_over_choose)
		{
		case '1':head = number_sort(head);
			    print_stu_infor(head); break;
		case '2':head=age_sort(head); print_stu_infor(head); break;
		case '3':head=name_sort(head); print_stu_infor(head); break;
		case '4':head=sex_sort(head); print_stu_infor(head); break;
		case '5':head=grade_sort(head); print_stu_infor(head); break;
		case '6':print_stu_infor(head); break;
		case '0':return head;
		}
	}
}