#include"myheader.h"
int return_menu1(STU* head)
{
	int save_choose = MessageBox(hWnd,_T("�Ƿ񱣴��޸ģ�"),_T("��ʾ"),MB_YESNOCANCEL);
	if (save_choose == 6)
	{
		FILE *fp = fopen("student.txt", "w");
		system("cls");
		save_stu_infor(head,fp);
		fclose(fp);
		return YES;
	}
	if (save_choose == 7)
	{
		system("cls");
		MessageBox(hWnd,_T("�ѷ������ģ�"),_T("��ʾ"),MB_OK);
		return NO;
	}
	if (save_choose == 2)
	{
		return CANCEL;
	}
}

int return_menu(STU* head)
{
	int save_choose = MessageBox(hWnd, _T("�Ƿ񱣴��޸ģ�"), _T("��ʾ"), MB_YESNOCANCEL);
	if (save_choose == 6)
	{
		FILE *fp = fopen("student.txt", "a");
		system("cls");
		save_stu_infor(head, fp);
		fclose(fp);
		return YES;
	}
	if (save_choose == 7)
	{
		system("cls");
		MessageBox(hWnd, _T("�ѷ������ģ�"), _T("��ʾ"), MB_OK);
		return NO;
	}
	if (save_choose == 2)
	{
		return CANCEL;
	}
}
void age_waring()
{
	MessageBox(hWnd, _T("��������ȷ���䣡"), _T("����"), MB_OK);
}
void grade_waring()
{
	MessageBox(hWnd, _T("��������ȷ�ɼ���"), _T("����"), MB_OK);
}