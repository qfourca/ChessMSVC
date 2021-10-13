#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable : 4047)
#include "chess.h"
int myCursorX = 1;
int myCursorY = 1;

int drawCursor(char color)
{
	return 0;
}

void chessSetting()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			if (i == 0 || i == 9 || j == 0 || j == 9)
				chessGrid[i][j] = END;
	for (int i = 1; i <= 8; i++)
		chessGrid[i][2] = PON;
	for (int i = 1; i <= 8; i++)
		chessGrid[i][7] = PON << 4;

	chessGrid[1][1] = ROO;
	chessGrid[8][1] = ROO;
	chessGrid[1][8] = ROO << 4;
	chessGrid[8][8] = ROO << 4;

	chessGrid[2][1] = KNI;
	chessGrid[7][1] = KNI;
	chessGrid[2][8] = KNI << 4;
	chessGrid[7][8] = KNI << 4;

	chessGrid[3][1] = BIS;
	chessGrid[6][1] = BIS;
	chessGrid[3][8] = BIS << 4;
	chessGrid[6][8] = BIS << 4;

	chessGrid[4][1] = QUE;
	chessGrid[4][8] = QUE << 4;

	chessGrid[5][1] = KIN;
	chessGrid[5][8] = KIN << 4;

}

int** retCharPtr(int input)
{
	switch (input)
	{
	case PON:
	case PON << 4:
		return pon_asset;
	case KNI:
	case KNI << 4:
		return kni_asset;
	case BIS:
	case BIS << 4:
		return bis_asset;
	case ROO:
	case ROO << 4:
		return roo_asset;
	case QUE:
	case QUE << 4:
		return que_asset;
	case KIN:
	case KIN << 4:
		return kin_asset;
	default:
		return - 1;
	}	
}

void moveMyCursor(char dir)
{
	drawBorder(myCursorX, myCursorY, RETCOLOR(myCursorX, myCursorY));
	if (dir == MOVLEF)
		myCursorX--;
	else if (dir == MOVRIG)
		myCursorX++;
	else if (dir == MOVVUP)
		myCursorY++;
	else if (dir == MOVDOW)
		myCursorY--;
	drawBorder(myCursorX, myCursorY, PURPLE);
}

void clicked()
{
	if (!move_mod)
	{
		initCangoArray();
		switch (chessGrid[myCursorX][myCursorY])
		{
		case PON:
		case PON << 4: isPonCanGo(myCursorX, myCursorY); break;
		case KNI:
		case KNI << 4: isKnightCanGo(myCursorX, myCursorY); break;
		case BIS:
		case BIS << 4:isBisopCanGo(myCursorX, myCursorY); break;
		case ROO:
		case ROO << 4:isRookCanGo(myCursorX, myCursorY); break;
		case QUE:
		case QUE << 4:isQueenCanGo(myCursorX, myCursorY); break;
		case KIN:
		case KIN << 4: isKingCanGo(myCursorX, myCursorY); break;
		case VOI: return;
		}
		canGoGrid[myCursorX][myCursorY] = 2;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				if (canGoGrid[i][j] == 1)
					drawBorder(i, j, BLUE);
		move_mod = true;
	}
	else
	{
		if (canGoGrid[myCursorX][myCursorY] == 1)
		{
			int i;
			int j;
			for (i = 0; i < 10; i++)
				for (j = 0; j < 10; j++)
					if (canGoGrid[i][j] == 2)
						break;
			char temp = chessGrid[i][j];
			chessGrid[i][j] = VOI;
			chessGrid[myCursorX][myCursorY] = temp;

			drawCore(i, j);
			drawCharacter(myCursorX, myCursorY, CHARCOLOR(temp), retCharPtr(temp));

			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
					if (canGoGrid[i][j] == 1)
						drawBorder(i, j, RETCOLOR(i ,j));
		}
		move_mod = false;
	}
}



void initCangoArray()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		canGoGrid[i][j] = 0;
}
void isPonCanGo(int x, int y)
{
	bool colorBlack = BOOLCOLOR(chessGrid[x][y]);

	if (colorBlack)
	{
		if (!(BOOLCOLOR(chessGrid[x - 1][y - 1])) && chessGrid[x - 1][y - 1] != VOI && !OVERMAP(x - 1, y - 1))
			canGoGrid[x - 1][y - 1] = 1;
		if (!(BOOLCOLOR(chessGrid[x + 1][y - 1])) && chessGrid[x + 1][y - 1] != VOI && !OVERMAP(x + 1, y - 1))
			canGoGrid[x + 1][y - 1] = 1;
		if (chessGrid[x][y - 1] == VOI)
		{
			canGoGrid[x][y - 1] = 1;
			if (y == 7 && chessGrid[x][y - 2] == VOI)
				canGoGrid[x][y - 2] = 1;
		}
	}
	else
	{
		if (BOOLCOLOR(chessGrid[x - 1][y + 1]) && chessGrid[x - 1][y + 1] != VOI && !OVERMAP(x - 1, y + 1))
			canGoGrid[x - 1][y + 1] = 1;
		if (BOOLCOLOR(chessGrid[x + 1][y + 1]) && chessGrid[x + 1][y + 1] != VOI && !OVERMAP(x + 1, y + 1))
			canGoGrid[x + 1][y + 1] = 1;
		if (chessGrid[x][y + 1] == VOI)
		{
			canGoGrid[x][y + 1] = 1;
			if (y == 2 && chessGrid[x][y + 2] == VOI)
				canGoGrid[x][y + 2] = 1;
		}
	}


};
inline nightCheck(int x, int y, char herColor)
{
	if (OVERMAP(x, y))
		return;
	if (chessGrid[x][y] == VOI || (herColor ^ BOOLCOLOR(chessGrid[x][y])));
	canGoGrid[x][y] = 1;
}
void isKnightCanGo(int x, int y)
{
	bool color = BOOLCOLOR(chessGrid[x][y]);
	
	nightCheck(x + 2, y + 1, color);
	nightCheck(x + 2, y - 1, color);
	nightCheck(x + 1, y + 2, color);
	nightCheck(x + 1, y - 2, color);
	nightCheck(x - 1, y + 2, color);
	nightCheck(x - 1, y - 2, color);
	nightCheck(x - 2, y + 1, color);
	nightCheck(x - 2, y - 1, color);
}
inline BisopCheck(int x, int y, bool color, char plusFlag)
{
	while (1)
	{
		switch (plusFlag)
		{
		case 1: x++; y++; break;
		case 1 << 1: x++; y--; break;
		case 1 << 2: x--; y++; break;
		case 1 << 3: x--; y--; break;
		}
		if (chessGrid[x][y] == VOI)
			canGoGrid[x][y] = 1;
		else
		{
			if (chessGrid[x][y] != END && color != BOOLCOLOR(chessGrid[x][y]))
				canGoGrid[x][y] = 1;
			break;
		}
	}
}
void isBisopCanGo(int x, int y)
{
	bool color = BOOLCOLOR(chessGrid[x][y]);
	for (int i = 0; i < 4; i++)
		BisopCheck(x, y, color, 1 << i);
}
inline rookCheck(int x, int y, bool color, char plusFlag)
{
	while (1)
	{
		switch (plusFlag)
		{
		case 1: x++; break;
		case 1 << 1: y++; break;
		case 1 << 2: x--; break;
		case 1 << 3: y--; break;
		}
		if (chessGrid[x][y] == VOI)
			canGoGrid[x][y] = 1;
		else
		{
			if (chessGrid[x][y] != END && color != BOOLCOLOR(chessGrid[x][y]))
				canGoGrid[x][y] = 1;
			break;
		}
	}
}
void isRookCanGo(int x, int y)
{
	bool color = BOOLCOLOR(chessGrid[x][y]);
	for (int i = 0; i < 4; i++)
		rookCheck(x, y, color, 1 << i);
}
void isQueenCanGo(int x, int y)
{
	isRookCanGo(x, y);
	isBisopCanGo(x, y);
}
inline kingCheck(int x, int y, bool color, char plusFlag)
{
	switch (plusFlag)
	{
	case 1: x++; break;
	case 1 << 1: y++; break;
	case 1 << 2: x--; break;
	case 1 << 3: y--; break;
	case 1 << 4: x++; y++; break;
	case 1 << 5: x++; y--; break;
	case 1 << 6: x--; y++; break;
	case 1 << 7: x--; y--; break;
	}
	if (chessGrid[x][y] == VOI || (chessGrid[x][y] != END && color != BOOLCOLOR(chessGrid[x][y])))
		canGoGrid[x][y] = 1;
}
void isKingCanGo(int x, int y)
{
	bool color = BOOLCOLOR(chessGrid[x][y]);
	for (int i = 0; i < 8; i++)
		kingCheck(x, y, color, 1 << i);
}