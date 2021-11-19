#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

constexpr char WAL = (char)219;
constexpr char BAL = (char)233;

int GetIndexFromCoordinates(int x, int y, int width)
{
	return x + y * width;
}

void main()
{
	int height = 10;
	int width = 15;
	int playerX = 1;
	int playerY = 1;

	char levelArray[]{  '+','-','-','-','-','-','-','-','-','-','-','-','-','-','+',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'+',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','@','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'+',' ',' ',' ',' ',' ',' ',' ',' ',' ',BAL,' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'+','-','-','-','-','-','-','-','-','-','-','-','-','-'-'+',
						
						

	while (1)
	{
		//Handle player input
		char input = ' ';
		if (_kbhit())
		{
			input = _getch();
		}

		int newPlayerX = playerX;
		int newPlayerY = playerY;
		switch (input)
		{
		case 'W':
		case 'w':
		{
			newPlayerY--;
			break;
		}
		case 'S':
		case 's':
		{
			newPlayerY++;
			break;
		}
		case 'A':
		case 'a':
		{
			newPlayerX--;
			break;
		}
		case 'D':
		case 'd':
		{
			newPlayerX++;
			break;
		}
		default:
			break;
		}
		playerX = newPlayerX;
		playerY = newPlayerY;

		//Reset screen
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		system("cls");

		//Render level
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				int n = GetIndexFromCoordinates(x, y, width);
				char c = levelArray[n];
				cout << c;
			}
			cout << endl;
		}

		//Render player
		COORD actorCursorPosition;
		actorCursorPosition.X = playerX;
		actorCursorPosition.Y = playerY;
		SetConsoleCursorPosition(console, actorCursorPosition);
		cout << "@";
	}

}