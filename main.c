#include"header.h"
int main()
{
	stu* head = create_open();
	course *C_head = open_course();
	student_course *SC_head = open_student_course();
	menu(head,C_head,SC_head);
	return 0;
}

