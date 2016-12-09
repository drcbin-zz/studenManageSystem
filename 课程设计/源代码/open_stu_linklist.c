#include"myheader.h"
STU* open_stu_linklist()
{
	STU* head;
	FILE *fp;
	if ((fp = fopen("student.txt", "r")) == NULL)
	{
		MessageBox(hWnd, _T("��ȷ���ļ�����'student.txt'�����ĵ���"), _T("���ļ�ʧ��"), MB_OK);
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
			MessageBox(hWnd, _T("δ��ȡ���ݣ���ȷ�ϡ�student.txt��������ȷ�����ݣ�"), _T("����"), NULL);
			return NULL;
		}
		break;
	}
	p->last->next = NULL;
	free(p);
	return head;
}