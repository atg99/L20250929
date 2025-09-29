#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

#define UP 0x48
#define LEFT 0x4B
#define RIGHT 0x4D
#define DOWN 0x50
#define SPACE 0x20

void GetInput();

int PlayerX = 0;
int PlayerY = 0;
char PlayerShape = 'p';
int main()
{
	while (true)
	{
		GetInput();
		COORD Cur;
		Cur.X = PlayerX;
		Cur.Y = PlayerY;
		system("cls");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		cout << PlayerShape << endl;
	}

}

void GetInput()
{
	int KeyInput = _getch();

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