#include<bits/stdc++.h>

using namespace std;

void interact(int );
void choice(int, int, int, int);
void victory(int, int, int, int);
void display(int );

void display(int board[6][7])
{
	int i, j;
	for (i = 0; i < 6; i++)
	{	cout << "|";	
		for (j = 0; j < 7; j++)
		{	if (board[i][j] == 1)
				cout << " O |";
			else if (board[i][j] == 2)
				cout << " X |";
			else
				cout << "   |";
		}
		cout << endl;
		cout << "-----------------------------" << endl;
	}
}

void victory(int board[6][7], int &win, int& r, int& c)
{
	int pl;
	if ((r + 3 < 6) && (board[r][c] == board[r + 1][c]) && (board[r + 1][c] == board[r + 2][c]) && (board[r + 2][c] == board[r + 3][c]))
	{	win = 1;
	}
	if ((r - 3 >= 0) && (c - 3 >= 0) && (board[r][c] == board[r - 1][c - 1]) && (board[r - 1][c - 1] == board[r - 2][c - 2]) && (board[r - 2][c - 2] == board[r - 3][c - 3]))
	{	win = 1;
	}
	if ((r - 2 >= 0) && (r + 1 < 6) && (c - 2 >= 0) && (c + 1 < 7) && (board[r + 1][c + 1] == board[r][c]) && (board[r][c] == board[r - 1][c - 1]) && (board[r - 1][c - 1] == board[r - 2][c - 2]))
	{	win = 1;
	}
	if ((r - 1 >= 0) && (r + 2 < 6) && (c - 1 >= 0) && (c + 2 < 7) && (board[r + 2][c + 2] == board[r + 1][c + 1]) && (board[r + 1][c + 1] == board[r][c]) && (board[r][c] == board[r - 1][c - 1]))
	{	win = 1;
	}
	if ((r + 2 < 6) && (c + 2 < 7) && (board[r + 3][c + 3] == board[r + 2][c + 2]) && (board[r + 2][c + 2] == board[r + 1][c + 1]) && (board[r + 1][c + 1] == board[r][c]))
	{	win = 1;
	}
	if ((c - 3 >= 0) && (board[r][c] == board[r][c - 1]) && (board[r][c - 1] == board[r][c - 2]) && (board[r][c - 2] == board[r][c - 3]))
	{	win = 1;
	}
	if ((c - 2 >= 0) && (c + 1 < 7) && (board[r][c + 1] == board[r][c]) && (board[r][c] == board[r][c - 1]) && (board[r][c - 1] == board[r][c - 2]))
	{	win = 1;
	}
	if ((c - 1 >= 0) && (c + 2 < 7) && (board[r][c + 2] == board[r][c + 1]) && (board[r][c + 1] == board[r][c]) && (board[r][c] == board[r][c - 1]))
	{	win = 1;
	}
	if ((c + 3 < 7) && (board[r][c + 3] == board[r][c + 2]) && (board[r][c + 2] == board[r][c + 1]) && (board[r][c + 1] == board[r][c]))
	{	win = 1;
	}
	if ((r + 3 < 6) && (c - 3 >= 0) && (board[r][c] == board[r + 1][c - 1]) && (board[r + 1][c - 1] == board[r + 2][c - 2]) && (board[r + 2][c - 2] == board[r + 3][c - 3]))
	{	win = 1;
	}
	if ((r + 2 < 6) && (r - 1 >= 0) && (c - 2 >= 0) && (c + 1 < 7) && (board[r - 1][c + 1] == board[r][c]) && (board[r][c] == board[r + 1][c - 1]) && (board[r + 1][c - 1] == board[r + 2][c - 2]))
	{	win = 1;
	}
	if ((r + 1 < 6) && (r - 2 >= 0) && (c - 1 >= 0) && (c + 2 < 7) && (board[r - 2][c + 2] == board[r - 1][c + 1]) && (board[r - 1][c + 1] == board[r][c]) && (board[r][c] == board[r + 1][c - 1]))
	{	win = 1;
	}
	if ((r - 3 >= 0) && (c + 3 < 7) && (board[r - 3][c + 3] == board[r - 2][c + 2]) && (board[r - 2][c + 2] == board[r - 1][c + 1]) && (board[r - 1][c + 1] == board[r][c]))
	{	win = 1;
	}
}

void choice(int board[6][7], int &pl, int &full, int &win)
{
	int move, r;
	cin >> move;
	if ((move > 7) or (move < 1))
	{	cout << "col no. exceeds the scope of the board" << endl;
		cout << "move for Player " << pl << endl;
		choice(board, pl, full, win);
	}
	else if (board[0][move - 1] > 0)
	{	cout << "Column full" << endl;
		cout << "Move for Player " << pl << endl;
		choice(board, pl, full, win);
	}
	else
	{	r = 5;
		while (board[r][move - 1] > 0)
		{	r -= 1;
		}
		board[r][move - 1] = pl;
		move -= 1;
		victory(board, win, r, move);
		full += 1;
		pl ^= 3;
	}
}

void aimove(int board[6][7], int &pl, int &full, int &win)
{
	int move, r;
	move = (rand() % 7) + 1;
	cout << move << endl;
	if (board[0][move - 1] > 0)
	{	cout << "Column full" << endl;
		cout << "Move for Player " << pl << endl;
		aimove(board, pl, full, win);
	}
	else
	{	r = 5;
		while (board[r][move - 1] > 0)
		{	r -= 1;
		}
		board[r][move - 1] = pl;
		move -= 1;
		victory(board, win, r, move);
		full += 1;
		pl ^= 3;
	}
}

void interact(int board[6][7])
{
	int full = 0, pl = 1, win = 0;
	while (full < 42 and win == 0)
	{	cout << "Move for Player " << pl << endl;
		choice(board, pl, full, win);
		display(board);
		if (full < 42 and win == 0)
		{	cout << "Move for Player " << pl << endl;
			aimove(board, pl, full, win);
			display(board);
		}
	}
	if (win == 1)
	{	pl = pl ^ 3;
		cout << "Player " << pl << " wins!" << endl;
	}
}

main()
{
	int board[6][7];
	int i = 0, j = 0;
	while (i < 6)
	{	j = 0;
		while (j < 7)
		{	board[i][j] = 0;
			j += 1;
		}
		i += 1;
	}
	interact(board);
}
