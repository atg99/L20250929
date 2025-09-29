#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <random>

using namespace std;

#define UP 0x48
#define LEFT 0x4B
#define RIGHT 0x4D
#define DOWN 0x50
#define SPACE 0x20

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dist(-1, 1);

int GetInput();
void ProcessInput(int KeyInput);
void ProcessEnemyMoving();
void Render();

int PlayerX = 0;
int PlayerY = 0;

int EnemyX = 6;
int EnemyY = 6;

char Shapes[2] = { 'P','M' };
int main()
{
	while (true)
	{
		ProcessInput(GetInput());
		ProcessEnemyMoving();
		system("cls");
		Render();
	}

}

int GetInput()
{
	return _getch();
}

void ProcessInput(int KeyInput)
{
	
	switch (KeyInput)
	{
	default: 	break;
	case UP:
		PlayerY--; break;
	case DOWN: 
		PlayerY++; break;
	case LEFT:
		PlayerX--; break;
	case RIGHT:
		PlayerX++; break;
	}
}

void ProcessEnemyMoving()
{
	EnemyX += dist(gen);
	EnemyY += dist(gen);
}

void MoveCusor(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void Render()
{
	MoveCusor(PlayerX, PlayerY);
	cout << Shapes[0] << endl;

	MoveCusor(EnemyX, EnemyY);
	cout << Shapes[1] << endl;
}