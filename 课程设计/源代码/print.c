#include"myheader.h"
void print_stu_infor(STU* head)
{
	char ch;
	int VoidLine, count, page = 1,sumPage,sumPerson=countPersonNum(head);
	sumPage = sumPerson % 10 == 0 ? sumPerson / 10 : sumPerson / 10 + 1;
	STU *PageHead, *p;
	if (head == NULL)
	{
		return;
	}
	PageHead = head;
	while (1)
	{
		p = PageHead;
		count = 10;
		system("cls");
		printf("%-7s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "序号├", "学号", "姓名", "性别", "年龄", "语文", "数学", "英语");
		while (p && count)
		{
			count--;
			printf("%-7d%-10d%-10s%-10s%-10d%-10d%-10d%-10d\n", 10 - count, p->stu_data.num, p->stu_data.name, p->stu_data.sex, p->stu_data.age, p->stu_data.grade.chinese, p->stu_data.grade.math, p->stu_data.grade.english);
			p = p->next;
		}
		VoidLine = count;
		while (VoidLine)//当人数不足10个 时，用空格来保证界面整洁
		{
			VoidLine--;
			printf("\n");
		}
		printf("\nESC:退出   \"↑↓\"键翻页     第%d页/共%d页    F1查看人数统计", page,sumPage);
		while (1)
		{
			ch = input();
			if (ch == ESC)
			{
				return;
			}
			if (ch == UP)
			{
				if ((judge_FirstPage(PageHead)) == YES)
				{
					continue;
				}
				PageHead = FindLastPageHead(PageHead, count);
				page--;
				break;
			}
			if (ch == DOWN)
			{
				if ((judge_FinalPage(PageHead)) == YES)
				{
					continue;
				}
				PageHead = FindNextPageHead(PageHead);
				page++;
				break;
			}
			if (ch == F1)
			{
				system("cls");
				{
					printf("共%d人。\n其中男生：%d人。\n　  女生：%d人。",countPersonNum(head),countManNum(head),countWomanNum(head));
					getch();
					break;
				}
			}
		}
	}
}


int input()
{
	char ch;
	while (1)
	{
		ch = getch();
		if (ch == 27)
		{
			return ESC;
		}
		if (ch == -32||ch==0)
		{
			ch = getch();
			if (ch == 72)//up
			{
				return UP;
			}
			if (ch == 80)//down
			{
				return DOWN;
			}
			if (ch == 75)//left
			{
				return LEFT;
			}
			if (ch == 77)//right
			{
				return RIGHT;
			}
			if (ch == 27)
			{
				return ESC;
			}
			if (ch == 59)
			{
				return F1;
			}
		}

	}
}

int countManNum(STU *head)
{
	int count = 0;
	STU *p = head;
	while (p)
	{
		if (((strcmp(p->stu_data.sex, "男")) == 0)||((strcmp(p->stu_data.sex, "M")) == 0)|| ((strcmp(p->stu_data.sex, "m")) == 0))
		{
			count++;
		}
		p = p->next;
	}
	return count;
}
int countWomanNum(STU *head)
{
	int count = 0;
	STU *p = head;
	while (p)
	{
		if (((strcmp(p->stu_data.sex, "女")) == 0)|| ((strcmp(p->stu_data.sex, "F")) == 0)|| ((strcmp(p->stu_data.sex, "f")) == 0))
		{
			count++;
		}
		p = p->next;
	}
	return count;
}
int countPersonNum(STU *head)
{
	STU *p = head;
	int count = 0;
	while (p)
	{
		p = p->next;
		count++;
	}
	return count;
}

int judge_FirstPage(STU *PageHead)
{
	if (PageHead->last == NULL)
	{
		return YES;
	}
	return NO;
}

int judge_FinalPage(STU *PageHead)
{
	STU *p = PageHead;
	int count = 10;
	while (p&&count)
	{
		p = p->next;
		count--;
	}
	if (!p)
	{
		return YES;
	}
	if (p)
	{
		return NO;
	}
}
STU* FindNextPageHead(STU* PageHead)
{
	STU *p=PageHead;
	int count = 10;
	while (count--)
	{
		p = p->next;
	}
	return p;
}

STU *FindLastPageHead(STU* PageHead)
{
	STU *p = PageHead;
	int count = 10;
	while (count--)
	{
		p = p->last;
	}
	return p;
}


