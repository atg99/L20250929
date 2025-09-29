#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

#define UP 0x48
#define LEFT 0x4B
#define RIGHT 0x4D
#define DOWN 0x50
#define SPACE 0x20
#define MAPWIDTH 30
#define MAPHIGHT 10

struct FCharacter
{
	int X;
	int Y;
	char Shape;

	FCharacter(int x, int y, char shape) : X(x), Y(y), Shape(shape) {}
};

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dist(-1, 1);

int Map[100][100] = { 0, };
char MapShape[4] = { ' ', '*' };

int GetInput()
{
	return _getch();
}

void ProcessMap(FCharacter& Character, int X, int Y)
{
	if (Map[Y][X])
	{
		return;
	}
	Character.X = X;
	Character.Y = Y;
}

void ProcessInput(FCharacter& Player,int KeyInput)
{
	int X = 0;
	int Y = 0;
	switch (KeyInput)
	{
	default: break;
	case UP:
		Y--; break;
	case DOWN: 
		Y++; break;
	case LEFT:
		X--; break;
	case RIGHT:
		X++; break;
	}
	ProcessMap(Player, Player->X+X, Player.Y+Y);
}

void ProcessEnemyMoving(FCharacter& Enemy)
{
	ProcessMap(Enemy, Enemy.X+dist(gen), Enemy.Y+dist(gen));
}

void MoveCusor(int x, int y)
{
	COORD Cur = {(SHORT)x,(SHORT)y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void CreateMap()
{

	int X = clamp(MAPWIDTH, 3, 100);
	int Y = clamp(MAPHIGHT, 3, 100);

	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (i == 0 || j == 0 || i == Y-1 || j == X-1)
			{
				Map[i][j] = 1;
			}
			else
			{
				Map[i][j] = 0;
			}
		}
	}
}

void DrawMap()
{
	for (int i = 0; i < MAPHIGHT; i++)
	{
		for (int j = 0; j < MAPWIDTH; j++)
		{
			cout << MapShape[Map[i][j]];
		}
		cout << "\n";
	}
}

void Render(vector<FCharacter*>& Characters)
{
	DrawMap();
	for (int i = 0; i < Characters.size(); i++)
	{
		MoveCusor(Characters[i]->X, Characters[i]->Y);
		cout << Characters[i]->Shape << endl;
	}
}

vector<FCharacter*>& InitCharacter()
{
	vector<FCharacter*>* Characters = new vector<FCharacter*>();

	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			Characters->push_back(new FCharacter(2, 2, 'P'));
		}
		else
		{
			Characters->push_back(new FCharacter(5 + i, 5 + i, 'M' + i - 1));
		}
	}

	return *Characters;
}

int main()
{
	vector<FCharacter*>& Characters = InitCharacter();
	CreateMap();
	//frame
	while (true)
	{
		ProcessInput(*Characters[0], GetInput());
		for (int i = 1; i < Characters.size(); i++)
		{
			ProcessEnemyMoving(*Characters[i]);
		}
		system("cls");
		Render(Characters);
	}

}