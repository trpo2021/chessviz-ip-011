#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "libChess/ChessHelper.h"

char Desk[9][9];

using namespace std;

int main()
{
	int i, j;
	Desk[8][0] = '8';
	Desk[1][1] = 'r';
	Desk[1][2] = 'n';
	Desk[1][3] = 'b';
	Desk[1][4] = 'q';
	Desk[1][5] = 'k';
	Desk[1][6] = 'b';
	Desk[1][7] = 'n';
	Desk[1][8] = 'r';
	Desk[7][0] = '7';

	for (i = 1; i < 9; i++)
	{
		Desk[2][i] = 'p';
	}

	for (i = 3; i < 7; i++)
	{
		for (j = 1; j < 9; j++)
		{
			Desk[i][j] = ' ';
		}

	}
	Desk[6][0] = '6';
	Desk[5][0] = '5';
	Desk[4][0] = '4';
	Desk[3][0] = '3';
	Desk[2][0] = '2';

	for (i = 1; i < 9; i++)
	{
		Desk[7][i] = 'P';
	}

	Desk[1][0] = '1';
	Desk[0][0] = ' ';
	Desk[8][1] = 'R';
	Desk[8][2] = 'N';
	Desk[8][3] = 'B';
	Desk[8][4] = 'Q';
	Desk[8][5] = 'K';
	Desk[8][6] = 'B';
	Desk[8][7] = 'N';
	Desk[8][8] = 'R';
	Desk[0][1] = 'a';
	Desk[0][2] = 'b';
	Desk[0][3] = 'c';
	Desk[0][4] = 'd';
	Desk[0][5] = 'e';
	Desk[0][6] = 'f';
	Desk[0][7] = 'g';
	Desk[0][8] = 'h';


	while (true)
	{
		int o = 0, p = 0, d = 0, f = 0;
		string t, y, k, l;
		char pus, pus1, pus2;
		system("cls");
		Sborka_Tabl(Desk);
		cin >> t >> y;
		if (t==y)
        {
            break;
        }
		pus1 = t[1];
		pus2 = y[1];
		o = pus1 - '0';
		p = pus2 - '0';
		k = t[0];
		if (k == "a")
		{
			d = 1;
		}
		if (k == "b")
		{
			d = 2;
		}
		if (k == "c")
		{
			d = 3;
		}
		if (k == "d")
		{
			d = 4;
		}
		if (k == "e")
		{
			d = 5;
		}
		if (k == "f")
		{
			d = 6;
		}
		if (k == "g")
		{
			d = 7;
		}
		if (k == "h")
		{
			d = 8;
		}

		l = y[0];

		if (l == "a")
		{
			f = 1;
		}
		if (l == "b")
		{
			f = 2;
		}
		if (l == "c")
		{
			f = 3;
		}
		if (l == "d")
		{
			f = 4;
		}
		if (l == "e")
		{
			f = 5;
		}
		if (l == "f")
		{
			f = 6;
		}
		if (l == "g")
		{
			f = 7;
		}
		if (l == "h")
		{
			f = 8;
		}
		pus = Desk[o][d];
		Desk[o][d] = Desk[p][f];
		Desk[p][f] = pus;
	}
	return 0;
}
