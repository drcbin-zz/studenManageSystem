#include"myheader.h"
STU* open_stu_linklist()
{
	STU* head;
	FILE *fp;
	if ((fp = fopen("student.txt", "r")) == NULL)
	{
		MessageBox(hWnd, _T("请确定文件夹中'student.txt'存在文档。"), _T("打开文件失败"), MB_OK);
		return NULL;
	}
	STU* p = head = (STU*)calloc(1, sizeof(STU));

	int count = 0;
	while (1)
	{
		if ((fread(&p->stu_data, sizeof(p->stu_data), 1, fp)) == 1)
		{
			count++;
			p->next = (STU*)calloc(1, sizeof(STU));
			p->next->last = p;
			p = p->next;
			continue;
		}
		if (count == 0)
		{
			free(p);
			MessageBox(hWnd, _T("未读取数据，请确认‘student.txt’中有正确的数据！"), _T("错误"), NULL);
			return NULL;
		}
		break;
	}
	p->last->next = NULL;
	free(p);
	return head;
}