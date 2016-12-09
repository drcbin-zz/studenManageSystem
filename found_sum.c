#include"header.h"
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
