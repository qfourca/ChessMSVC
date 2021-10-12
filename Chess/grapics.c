#include "grapics.h"
void grapicDraw()
{
	system("color f0");
	for (int i = 0; i < 270; i++)
		for (int j = 0; j < 250; j++)
			printf(DOT);
	for (int i = 0; i < 9; i++)
		drawHor(120, 1 + 15 * i, 121);
	for (int i = 0; i < 9; i++)
		drawVer(120 + 30 * i, 1, 121);
}
void drawVer(int x, int y, int length)
{
	gotoxy(x, y);
	setcolor(BLACK);
	for (int i = 0; i < length; i++)
	{
		printf(DOT);
		gotoxy(x, ++y);
	}
}
void drawHor(int x, int y, int length)
{
	gotoxy(x, y);
	setcolor(BLACK);
	for (int i = 0; i < length; i++)
		printf(DOT);
}
void drawCore(int x, int y)
{
	setcolor(RETCOLOR(x, y));
	x = RETX(x);
	y = RETY(y);
	for (int i = 0; i < 14; i++)
	{
		gotoxy(x, y + i);
		printf("                            ");
	}
}
void drawBorder(int x, int y, char color)
{
	x = RETX(x);
	y = RETY(y);
	setcolor(color);
	gotoxy(x, y);
	printf("                            ");
	for (int i = 1; i < 13; i++)
	{
		gotoxy(x, y + i);
		printf(DOT);
		gotoxy(x + 26, y + i);
		printf(DOT);
	}
	gotoxy(x, y + 13);
	printf("                            ");
}
void drawCharacter(int x, int y, char color, char** input)
{
	x = RETX(x);
	y =	RETY(y);
	setcolor(color);
	for (int i = 0; i < 14; i++)
		for (int j = 0; j < 14; j++)
			if (input[i][j])
			{
				printf(DOT);
				gotoxy(x + i, x + j * 2);
			}
}