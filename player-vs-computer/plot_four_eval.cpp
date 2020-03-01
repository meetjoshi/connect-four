#include<bits/stdc++.h>

using namespace std;

void interact(int );
void choice(int, int, int, int);
void victory(int, int, int, int);
void display(int );
int eval(int );
int eval_2(int, int, int);
int eval_a(int, int, int);
int eval_b(int, int, int);
int eval_c(int, int, int);
int eval_d(int, int, int);

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
	if ((r + 3 < 6) && (c + 3 < 7) && (board[r + 3][c + 3] == board[r + 2][c + 2]) && (board[r + 2][c + 2] == board[r + 1][c + 1]) && (board[r + 1][c + 1] == board[r][c]))
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

// we are talking about opponents and self w.r.t. computer, i.e. self = computer = ai, 

// checks 3 contiguous series of opponent, weightage = 20
// player = opponent = 1; self = computer = ai = 2;
// victory() function copied and edited
int eval_a(int board[6][7], int& r, int& c)
{	int v = 0;	

//	cout << "beg v_a = " << v << endl;

	board[r][c] = 1;
	if ((r + 2 < 6) && (board[r][c] == board[r + 1][c]) && (board[r + 1][c] == board[r + 2][c]))
	{	v += 20;
	}
	if ((r - 2 >= 0) && (c - 2 >= 0) && (board[r][c] == board[r - 1][c - 1]) && (board[r - 1][c - 1] == board[r - 2][c - 2]))
	{	v += 20;
	}
	if ((r - 1 >= 0) && (r + 1 < 6) && (c - 1 >= 0) && (c + 1 < 7) && (board[r + 1][c + 1] == board[r][c]) && (board[r][c] == board[r - 1][c - 1]))
	{	v += 20;
	}
	if ((r + 2 < 6) && (c + 2 < 7) && (board[r + 2][c + 2] == board[r + 1][c + 1]) && (board[r + 1][c + 1] == board[r][c]))
	{	v += 20;
	}
	if ((c - 2 >= 0) && (board[r][c] == board[r][c - 1]) && (board[r][c - 1] == board[r][c - 2]))
	{	v += 20;
	}
	if ((c - 1 >= 0) && (c + 1 < 7) && (board[r][c + 1] == board[r][c]) && (board[r][c] == board[r][c - 1]))
	{	v += 20;
	}
	if ((c + 2 < 7) && (board[r][c + 2] == board[r][c + 1]) && (board[r][c + 1] == board[r][c]))
	{	v += 20;
	}
	if ((r + 2 < 6) && (c - 2 >= 0) && (board[r][c] == board[r + 1][c - 1]) && (board[r + 1][c - 1] == board[r + 2][c - 2]))
	{	v += 20;
	}
	if ((r + 1 < 6) && (r - 1 >= 0) && (c - 1 >= 0) && (c + 1 < 7) && (board[r - 1][c + 1] == board[r][c]) && (board[r][c] == board[r + 1][c - 1]))
	{	v += 20;
	}
	if ((r - 2 >= 0) && (c + 2 < 7) && (board[r - 2][c + 2] == board[r - 1][c + 1]) && (board[r - 1][c + 1] == board[r][c]))
	{	v += 20;
	}
	board[r][c] = 0;

//	cout << "end v_a = " << v << endl;

	return v;
}

// checks 4 contiguous series of opponent, weightage = 300
// opponent = 1
int eval_b(int board[6][7], int& r, int& c)
{	int v = 0;

//	cout << "beg v_b = " << v << endl;

	board[r][c] = 1;
	if ((r + 3 < 6) && (board[r][c] == board[r + 1][c]) && (board[r + 1][c] == board[r + 2][c]) && (board[r + 2][c] == board[r + 3][c]))
	{	v += 300;
	}
	if ((r - 3 >= 0) && (c - 3 >= 0) && (board[r][c] == board[r - 1][c - 1]) && (board[r - 1][c - 1] == board[r - 2][c - 2]) && (board[r - 2][c - 2] == board[r - 3][c - 3]))
	{	v += 300;
	}
	if ((r - 2 >= 0) && (r + 1 < 6) && (c - 2 >= 0) && (c + 1 < 7) && (board[r + 1][c + 1] == board[r][c]) && (board[r][c] == board[r - 1][c - 1]) && (board[r - 1][c - 1] == board[r - 2][c - 2]))
	{	v += 300;
	}
	if ((r - 1 >= 0) && (r + 2 < 6) && (c - 1 >= 0) && (c + 2 < 7) && (board[r + 2][c + 2] == board[r + 1][c + 1]) && (board[r + 1][c + 1] == board[r][c]) && (board[r][c] == board[r - 1][c - 1]))
	{	v += 300;
	}
	if ((r + 3 < 6) && (c + 3 < 7) && (board[r + 3][c + 3] == board[r + 2][c + 2]) && (board[r + 2][c + 2] == board[r + 1][c + 1]) && (board[r + 1][c + 1] == board[r][c]))
	{	v += 300;
	}
	if ((c - 3 >= 0) && (board[r][c] == board[r][c - 1]) && (board[r][c - 1] == board[r][c - 2]) && (board[r][c - 2] == board[r][c - 3]))
	{	v += 300;
	}
	if ((c - 2 >= 0) && (c + 1 < 7) && (board[r][c + 1] == board[r][c]) && (board[r][c] == board[r][c - 1]) && (board[r][c - 1] == board[r][c - 2]))
	{	v += 300;
	}
	if ((c - 1 >= 0) && (c + 2 < 7) && (board[r][c + 2] == board[r][c + 1]) && (board[r][c + 1] == board[r][c]) && (board[r][c] == board[r][c - 1]))
	{	v += 300;
	}
	if ((c + 3 < 7) && (board[r][c + 3] == board[r][c + 2]) && (board[r][c + 2] == board[r][c + 1]) && (board[r][c + 1] == board[r][c]))
	{	v += 300;
	}
	if ((r + 3 < 6) && (c - 3 >= 0) && (board[r][c] == board[r + 1][c - 1]) && (board[r + 1][c - 1] == board[r + 2][c - 2]) && (board[r + 2][c - 2] == board[r + 3][c - 3]))
	{	v += 300;
	}
	if ((r + 2 < 6) && (r - 1 >= 0) && (c - 2 >= 0) && (c + 1 < 7) && (board[r - 1][c + 1] == board[r][c]) && (board[r][c] == board[r + 1][c - 1]) && (board[r + 1][c - 1] == board[r + 2][c - 2]))
	{	v += 300;
	}
	if ((r + 1 < 6) && (r - 2 >= 0) && (c - 1 >= 0) && (c + 2 < 7) && (board[r - 2][c + 2] == board[r - 1][c + 1]) && (board[r - 1][c + 1] == board[r][c]) && (board[r][c] == board[r + 1][c - 1]))
	{	v += 300;
	}
	if ((r - 3 >= 0) && (c + 3 < 7) && (board[r - 3][c + 3] == board[r - 2][c + 2]) && (board[r - 2][c + 2] == board[r - 1][c + 1]) && (board[r - 1][c + 1] == board[r][c]))
	{	v += 300;
	}
	board[r][c] = 0;

//	cout << "end v_b = " << v << endl;

	return v;
}

// checks 3 contiguous series of self, weightage = 7
// self = 2
int eval_c(int board[6][7], int& r, int& c)
{	int v = 0;	

//	cout << "beg v_c = " << v << endl;

	board[r][c] = 2;
	if ((r + 2 < 6) && (board[r][c] == board[r + 1][c]) && (board[r + 1][c] == board[r + 2][c]))
	{	v += 7;
	}
	if ((r - 2 >= 0) && (c - 2 >= 0) && (board[r][c] == board[r - 1][c - 1]) && (board[r - 1][c - 1] == board[r - 2][c - 2]))
	{	v += 7;
	}
	if ((r - 1 >= 0) && (r + 1 < 6) && (c - 1 >= 0) && (c + 1 < 7) && (board[r + 1][c + 1] == board[r][c]) && (board[r][c] == board[r - 1][c - 1]))
	{	v += 7;
	}
	if ((r + 2 < 6) && (c + 2 < 7) && (board[r + 2][c + 2] == board[r + 1][c + 1]) && (board[r + 1][c + 1] == board[r][c]))
	{	v += 7;
	}
	if ((c - 2 >= 0) && (board[r][c] == board[r][c - 1]) && (board[r][c - 1] == board[r][c - 2]))
	{	v += 7;
	}
	if ((c - 1 >= 0) && (c + 1 < 7) && (board[r][c + 1] == board[r][c]) && (board[r][c] == board[r][c - 1]))
	{	v += 7;
	}
	if ((c + 2 < 7) && (board[r][c + 2] == board[r][c + 1]) && (board[r][c + 1] == board[r][c]))
	{	v += 7;
	}
	if ((r + 2 < 6) && (c - 2 >= 0) && (board[r][c] == board[r + 1][c - 1]) && (board[r + 1][c - 1] == board[r + 2][c - 2]))
	{	v += 7;
	}
	if ((r + 1 < 6) && (r - 1 >= 0) && (c - 1 >= 0) && (c + 1 < 7) && (board[r - 1][c + 1] == board[r][c]) && (board[r][c] == board[r + 1][c - 1]))
	{	v += 7;
	}
	if ((r - 2 >= 0) && (c + 2 < 7) && (board[r - 2][c + 2] == board[r - 1][c + 1]) && (board[r - 1][c + 1] == board[r][c]))
	{	v += 7;
	}
	board[r][c] = 0;

//	cout << "end v_c = " << v << endl;

	return v;
}

// checks series of 4 contiguous for self, weightage = 5000
// self = 2;
int eval_d(int board[6][7], int& r, int& c)
{	int v = 0;

//	cout << "beg v_d = " << v << endl;

	board[r][c] = 2;
	if ((r + 3 < 6) && (board[r][c] == board[r + 1][c]) && (board[r + 1][c] == board[r + 2][c]) && (board[r + 2][c] == board[r + 3][c]))
	{	v += 5000;
	}
	if ((r - 3 >= 0) && (c - 3 >= 0) && (board[r][c] == board[r - 1][c - 1]) && (board[r - 1][c - 1] == board[r - 2][c - 2]) && (board[r - 2][c - 2] == board[r - 3][c - 3]))
	{	v += 5000;
	}
	if ((r - 2 >= 0) && (r + 1 < 6) && (c - 2 >= 0) && (c + 1 < 7) && (board[r + 1][c + 1] == board[r][c]) && (board[r][c] == board[r - 1][c - 1]) && (board[r - 1][c - 1] == board[r - 2][c - 2]))
	{	v += 5000;
	}
	if ((r - 1 >= 0) && (r + 2 < 6) && (c - 1 >= 0) && (c + 2 < 7) && (board[r + 2][c + 2] == board[r + 1][c + 1]) && (board[r + 1][c + 1] == board[r][c]) && (board[r][c] == board[r - 1][c - 1]))
	{	v += 5000;
	}
	if ((r + 3 < 6) && (c + 3 < 7) && (board[r + 3][c + 3] == board[r + 2][c + 2]) && (board[r + 2][c + 2] == board[r + 1][c + 1]) && (board[r + 1][c + 1] == board[r][c]))
	{	v += 5000;
	}
	if ((c - 3 >= 0) && (board[r][c] == board[r][c - 1]) && (board[r][c - 1] == board[r][c - 2]) && (board[r][c - 2] == board[r][c - 3]))
	{	v += 5000;
	}
	if ((c - 2 >= 0) && (c + 1 < 7) && (board[r][c + 1] == board[r][c]) && (board[r][c] == board[r][c - 1]) && (board[r][c - 1] == board[r][c - 2]))
	{	v += 5000;
	}
	if ((c - 1 >= 0) && (c + 2 < 7) && (board[r][c + 2] == board[r][c + 1]) && (board[r][c + 1] == board[r][c]) && (board[r][c] == board[r][c - 1]))
	{	v += 5000;
	}
	if ((c + 3 < 7) && (board[r][c + 3] == board[r][c + 2]) && (board[r][c + 2] == board[r][c + 1]) && (board[r][c + 1] == board[r][c]))
	{	v += 5000;
	}
	if ((r + 3 < 6) && (c - 3 >= 0) && (board[r][c] == board[r + 1][c - 1]) && (board[r + 1][c - 1] == board[r + 2][c - 2]) && (board[r + 2][c - 2] == board[r + 3][c - 3]))
	{	v += 5000;
	}
	if ((r + 2 < 6) && (r - 1 >= 0) && (c - 2 >= 0) && (c + 1 < 7) && (board[r - 1][c + 1] == board[r][c]) && (board[r][c] == board[r + 1][c - 1]) && (board[r + 1][c - 1] == board[r + 2][c - 2]))
	{	v += 5000;
	}
	if ((r + 1 < 6) && (r - 2 >= 0) && (c - 1 >= 0) && (c + 2 < 7) && (board[r - 2][c + 2] == board[r - 1][c + 1]) && (board[r - 1][c + 1] == board[r][c]) && (board[r][c] == board[r + 1][c - 1]))
	{	v += 5000;
	}
	if ((r - 3 >= 0) && (c + 3 < 7) && (board[r - 3][c + 3] == board[r - 2][c + 2]) && (board[r - 2][c + 2] == board[r - 1][c + 1]) && (board[r - 1][c + 1] == board[r][c]))
	{	v += 5000;
	}
	board[r][c] = 0;

//	cout << "end v_d = " << v << endl;

	return v;
}

// just a helper function of evaluating function - eval()
int eval_2(int board[6][7], int& r, int &c)
{
	int v, aa, bb, cc, dd;
	aa = eval_a(board, r, c);
	bb = eval_b(board, r, c);
	cc = eval_c(board, r, c);
	dd = eval_d(board, r, c);

//	cout << "aa = " << aa << ", bb = " << bb << ", cc = " << cc << ", dd = " << dd << endl;

	v = aa + bb + cc + dd;
	return v;
}

int eval(int board[6][7])
{
	int i, j, mx[11], r, v1, v2, pos[11], maxi;
	i = maxi = 0;
	while (i < 7)
	{	r = 5;
		while (board[r][i] > 0)
		{	r -= 1;
		}
		pos[i] = r;
		if (pos[i] < 0)
		{	i++;
			continue;
		}
		mx[i] = eval_2(board, r, i);

//		cout << "i = " << i << ", r = " << r << ", c = " << i << endl;

		if (mx[i] > maxi)
		{	maxi = mx[i];
			v1 = i;
		}
		i++;
	}
	if (!maxi)
	{	return (rand() % 7) + 1;
	}
	else
	{	return (v1 + 1);
	}
}

void aimove(int board[6][7], int &pl, int &full, int &win)
{
	int move, r;
/*
	cout << "Display Board 1: " << endl;
	display(board);
	cout << endl;
*/
	move = eval(board);
/*
	cout << "Display Board 2: " << endl;
	display(board);
	cout << endl;
*/
//	cout << "Move = " << move << endl;

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
