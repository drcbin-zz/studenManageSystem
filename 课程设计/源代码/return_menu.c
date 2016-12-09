#include"myheader.h"
int return_menu1(STU* head)
{
	int save_choose = MessageBox(hWnd,_T("是否保存修改？"),_T("提示"),MB_YESNOCANCEL);
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
		MessageBox(hWnd,_T("已放弃更改！"),_T("提示"),MB_OK);
		return NO;
	}
	if (save_choose == 2)
	{
		return CANCEL;
	}
}

int return_menu(STU* head)
{
	int save_choose = MessageBox(hWnd, _T("是否保存修改？"), _T("提示"), MB_YESNOCANCEL);
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
		MessageBox(hWnd, _T("已放弃更改！"), _T("提示"), MB_OK);
		return NO;
	}
	if (save_choose == 2)
	{
		return CANCEL;
	}
}
void age_waring()
{
	MessageBox(hWnd, _T("请输入正确年龄！"), _T("警告"), MB_OK);
}
void grade_waring()
{
	MessageBox(hWnd, _T("请输入正确成绩！"), _T("警告"), MB_OK);
}