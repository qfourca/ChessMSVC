#pragma once
#include "windowconsole.h"
#include "grapics.h"

void grapicDraw();

void drawVer(int, int, int);
void drawHor(int, int, int);
void drawBorder(int, int, char);
void drawCore(int, int);
void drawCharacter(int, int, char, char**);

#define RETX(x) 122 + (x - 1) * 30
#define RETY(y) 107 - (y - 1) * 15
#define RETCOLOR(x, y) x % 2 ^ y % 2 ? 7 : 8