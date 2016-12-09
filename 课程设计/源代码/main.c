#include"myheader.h"
int main()
{
	int n = 1;
	while (n--)
	{
		HWND hWnd = FindWindow(NULL, "hWad");
		system("cls");
		puts("正在载入");
		Sleep(150);
		system("cls");
		puts("正在载入.");
		Sleep(150);
		system("cls");
		puts("正在载入..");
		Sleep(150);
		system("cls");
		puts("正在载入...");
		Sleep(150);
		system("cls");
		puts("正在载入");
		Sleep(150);
		system("cls");
		puts("正在载入.");
		Sleep(150);
		system("cls");
		puts("正在载入..");
		Sleep(500);
	}
	main_menu();
}
void _fflush()
{
	while (1)
	{
		if ((getchar())=='\n')
			break;
	}
}