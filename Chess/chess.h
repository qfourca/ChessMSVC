#pragma once
#include "grapics.h"

#define CHARCOLOR(x) (x > 15 ? BLACK : L_WHITE)
#define BOOLCOLOR(x) (x > 15)
#define OVERMAP(x, y) (x > 8 || x < 1 || y > 8 || y < 1)

#define MOVLEF 0
#define MOVRIG 1
#define MOVVUP 2
#define MOVDOW 3

#define END -1
#define VOI 0
#define PON 1
#define KNI 2
#define BIS 3
#define ROO 4
#define QUE 5
#define KIN 6

char chessGrid[10][10];
char canGoGrid[10][10];

int pon_asset[14][14];
int kni_asset[14][14];
int bis_asset[14][14];
int roo_asset[14][14];
int que_asset[14][14];
int kin_asset[14][14];

extern int myCursorX;
extern int myCursorY;

bool move_mod;

int** retCharPtr(int input);
void chessSetting();
void moveMyCursor(char);
void clicked();

void initCangoArray();

void isPonCanGo(int, int);
void isKnightCanGo(int, int);
void isBisopCanGo(int, int);
void isRookCanGo(int, int);
void isQueenCanGo(int, int);
void isKingCanGo(int, int);