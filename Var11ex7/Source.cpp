#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void setTextAttr(WORD attr)
{
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOuput, attr);
}

const int Max = 71;
char Temp[Max];
char Line[Max];

int main()
{
	system("chcp 1251>nul");
	int LineNumber = 0;
	FILE * F = fopen("Source.txt","r");
	while (true)
	{
		fgets(Temp, 70, F);
		if (feof(F)) break;
		if (Temp[0] == '\n') continue;
		memcpy(Line, Temp, sizeof(Line));
		printf("%s",Line);
		LineNumber++;
	}
	fclose(F);

	
	int p = strlen(Line);
	Line[p - 1] = 0;
	p--; 
	int len = 0;
	while (p >= 0)
	{
		p--;
		if (Line[p] == ' ') break;
		len++;
	};
	if (p != 0) p++;
	int count = 0;
	for (int i = 0; i < len; i++)
		if (Line[i + p] == 'a') count++;
	printf("В строке \n%s\n найдено слово \n%s\nв нем %d букв 'a' (lat)\n",Line,&Line[p],count);
	_getch();
	int LastLine = LineNumber - 1;
	gotoxy(p,LastLine);
	setTextAttr(0x5F);
	printf("%s", &Line[p]);
	int p0 = p;
	do
	{
		p = p0;
	for (int i = 0; i < count; i++)
	{
		while (Line[p] != 'a') p++;
		gotoxy(p, LastLine);
		setTextAttr(0x70);
		printf("a");
		Sleep(500);
		gotoxy(p, LastLine);
		setTextAttr(0x5F);
		printf("a");
		Sleep(500);
		p++;
	}
	}
	while (_getch() != 27);


}