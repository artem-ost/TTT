#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

vector<vector<char>> Board(vector<vector<char>>& coords, int move);
bool IsAble(vector<vector<char>>& coords, int move, const int x, const int y);
int IsWon(vector<vector<char>>& coords, int move);

bool IsAble(vector<vector<char>>& coords, int move, const int x, const int y)
{
	if (coords[x][y] != ' ')
	{
		return false;
	}
	else
	{
		return true;
	}
}

int IsWon(vector<vector<char>>& coords, int move)
{
	for (int i = 0; i < 3; i++)
	{
		if (coords[i][0] == coords[i][1] && coords[i][1] == coords[i][2] && coords[i][0] != ' ')
		{
			if (move % 2)
			{
				return 1;
				break;
			}
			else
			{
				return 2;
				break;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (coords[0][i] == coords[1][i] && coords[1][i] == coords[2][i] && coords[0][i] != ' ')
		{
			if (move % 2)
			{
				return 1;
				break;
			}
			else
			{
				return 2;
				break;
			}
		}
	}

	if (coords[0][0] == coords[1][1] && coords[1][1] == coords[2][2] && coords[0][0] != ' ')
	{
		if (move % 2)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if (coords[2][0] == coords[1][1] && coords[1][1] == coords[0][2] && coords[2][0] != ' ')
	{
		if (move % 2)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if (move == 10)
	{
		return 0;
	}
	else {
		return -1;
	}

}

void Move(vector<vector<char>>& coords, int move)
{
	string m;
	cout << "Õîä " << (move - 1) << "( Ôîðìàò ââîäà êîîðäèíàòû êëåòêè(x-y) ). ";
	if (move % 2 == 0)
	{
		cout << "Õîäÿò íîëèêè: " << endl;
		cin >> m;

		int x = m[0];
		if (m[0] == 48)
		{
			x = 0;
		}
		else if (m[0] == 49)
		{
			x = 1;
		}
		else if (m[0] == 50)
		{
			x = 2;
		}

		int y = m[m.size() - 1];
		if (m[m.size() - 1] == 48)
		{
			y = 0;
		}
		else if (m[m.size() - 1] == 49)
		{
			y = 1;
		}
		else if (m[m.size() - 1] == 50)
		{
			y = 2;
		}

		if (x > 2 || y > 2 || x < 0 || y < 0)
		{
			Move(coords, move);
		}
		else
		{
			if (IsAble(coords, move, x, y))
			{
				coords[x][y] = '0';
				system("cls");
				Board(coords, move);
			}
			else
			{
				Move(coords, move);
			}

		}
	}
	else
	{
		cout << "Õîäÿò êðåñòèêè: " << endl;
		cin >> m;

		int x = m[0];
		if (m[0] == 48)
		{
			x = 0;
		}
		else if (m[0] == 49)
		{
			x = 1;
		}
		else if (m[0] == 50)
		{
			x = 2;
		}

		int y = m[m.size() - 1];
		if (m[m.size() - 1] == 48)
		{
			y = 0;
		}
		else if (m[m.size() - 1] == 49)
		{
			y = 1;
		}
		else if (m[m.size() - 1] == 50)
		{
			y = 2;
		}

		if (x > 2 || y > 2 || x < 0 || y < 0)
		{
			Move(coords, move);
		}
		else
		{
			if (IsAble(coords, move, x, y))
			{
				coords[x][y] = 'X';
				system("cls");
				Board(coords, move);
			}
			else
			{
				Move(coords, move);
			}
		}
	}
}

vector<vector<char>> Board(vector<vector<char>>& coords, int move = 1)
{
	cout << "   0    1    2     Y";
	{
		for (int i = 1; i < 15; i++)
		{
			if (i % 4 == 0)
			{
				cout << (i / 4) - 1 << " # " << coords[int((i / 4)) - 1][0] << " # " << coords[int((i / 4)) - 1][1] << " # " << coords[int((i / 4)) - 1][2] << " # ";
				cout << endl;

			}
			else if (i > 1 && i % 4 == 2)
			{
				cout << "  #############" << endl;

			}
			else if (i > 2)
			{
				cout << "  #   #   #   #" << endl;

			}
			else
			{
				cout << endl;

			}
		}
		cout << "X" << endl;
	}
	if (move > 5)
	{
		if (IsWon(coords, move) == 0)
		{
			cout << "ÍÈ×Üß!";
			return coords;
		}
		else if (IsWon(coords, move) == 1)
		{
			cout << "ÊÐÅÑÒÈÊÈ ÏÎÁÅÄÈËÈ!";
			return coords;
		}
		else if (IsWon(coords, move) == 2)
		{
			cout << "ÍÎËÈÊÈ ÏÎÁÅÄÈËÈ!";
			return coords;
		}
	}

	Move(coords, ++move);

	return coords;
}

int main()
{
	setlocale(LC_ALL, "ru");

	vector<vector<char>> coords = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };

	Board(coords, 1);
}