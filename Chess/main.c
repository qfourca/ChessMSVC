#define _CRT_SECURE_NO_WARNINGS
#include "chess.h"
int main()
{
	setting();
	chessSetting();
	grapicDraw();

	FILE* fp = fopen("pon.txt", "r");
	for (int i = 0; i < 14; i++)
		for (int j = 0; j < 14; j++)
			fscanf(fp, "%d", &pon_asset[i][j]);
	fclose(fp);
	fp = fopen("knight.txt", "r");
	for (int i = 0; i < 14; i++)
		for (int j = 0; j < 14; j++)
			fscanf(fp, "%d", &kni_asset[i][j]);
	fclose(fp);
	fp = fopen("bisop.txt", "r");
	for (int i = 0; i < 14; i++)
		for (int j = 0; j < 14; j++)
			fscanf(fp, "%d", &bis_asset[i][j]);
	fclose(fp);
	fp = fopen("rook.txt", "r");
	for (int i = 0; i < 14; i++)
		for (int j = 0; j < 14; j++)
			fscanf(fp, "%d", &roo_asset[i][j]);
	fclose(fp);
	fp = fopen("queen.txt", "r");
	for (int i = 0; i < 14; i++)
		for (int j = 0; j < 14; j++)
			fscanf(fp, "%d", &que_asset[i][j]);
	fclose(fp);
	fp = fopen("king.txt", "r");
	for (int i = 0; i < 14; i++)
		for (int j = 0; j < 14; j++)
			fscanf(fp, "%d", &kin_asset[i][j]);
	fclose(fp);

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (chessGrid[j][i] != VOI && chessGrid[j][i] != END)
				drawCharacter(j, i, CHARCOLOR(chessGrid[j][i]), retCharPtr(chessGrid[j][i]));
	while (true)
	{
		if (GetAsyncKeyState(VK_LEFT) && myCursorX > 1)
		{
			moveMyCursor(MOVLEF);
		}
		if (GetAsyncKeyState(VK_DOWN) && myCursorY > 1)
		{
			moveMyCursor(MOVDOW);
		}
		if (GetAsyncKeyState(VK_UP) && myCursorY < 8)
		{
			moveMyCursor(MOVVUP);
		}
		if (GetAsyncKeyState(VK_RIGHT) && myCursorX < 8)
		{
			moveMyCursor(MOVRIG);
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			clicked();
		}
		Sleep(100);
	}
	return 0;
}