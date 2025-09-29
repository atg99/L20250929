//#include <iostream>
//#include <Windows.h>
//#include <vector>
//
//using namespace std;
//
////C style
//struct FCharacter
//{
//	int X;
//	int Y;
//	char Shape;
//
//	FCharacter(int x, int y, char shape) : X(x), Y(y), Shape(shape) {}
//};
//
//void Render(vector<FCharacter*>& Characters);
//
//int main()
//{
//
//	vector<FCharacter*> Characters;
//	
//	for (int i = 0; i < 3; i++)
//	{
//		if (i == 0)
//		{
//			Characters.push_back(new FCharacter(5, 5, 'p'));
//		}
//		else
//		{
//			Characters.push_back(new FCharacter(5+i, 5+i, 'M'+i-1));
//		}
//	}
//
//	while (true)
//	{
//		Render(Characters);
//	}
//	
//}
//
//void Render(vector<FCharacter*>& Characters)
//{
//	for (FCharacter* Character : Characters)
//	{
//		RenderCharacter(*Character);
//	}
//}
//
//void RenderCharacter(FCharacter& Character)
//{
//	COORD Pos = { (SHORT)Character.X, (SHORT)Character.Y };
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
//	cout << Character.Shape << endl;
//}