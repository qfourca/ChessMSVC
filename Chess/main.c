#define _CRT_SECURE_NO_WARNINGS
#include "grapics.h"
int main()
{
	setting();
	grapicDraw();
	for (int i = 1; i < 9; i++)
		for (int j = 1; j < 9; j++)
			drawCore(i, j);
	
	while (true) {}
	return 0;
}