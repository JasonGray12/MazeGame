#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

constexpr char WAL = (char)219;
constexpr char BAL = (char)233;
constexpr char kPlayerSymbol = '@';

void DrawLevel(char level[], int width, int height, int playerX, int playerY, int ballX, int ballY);

int GetIndexFromCoordinates(int x, int y, int width);
bool UpdatePlayerPosition(char level[], int& playerX, int& playerY, int width, int ballX, int ballY, int& ballMoveX, int& ballMoveY);
void UpdateBall(int& ballX, int&ballY, int ballMoveX, int ballMoveY);

int main()
{
	int height = 10;
	int width = 15;
	

	char levelArray[]{  '+','-','-','-','-','-','-','-','-','-','-','-','-','-','+',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'+','-',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'+','-',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'+','-','-','-','-','-','-','-','-','-','-','-','-','-' - '+', };

	int playerX = 1;
	int playerY = 1;
	int ballX = 10;
	int ballY = 5;
	int ballMoveX = 0;
	int ballMoveY = 0;
	bool gameOver = false;

	while (!gameOver)
	{
		system("cls");
		DrawLevel(levelArray, width, height, playerX, playerY, ballX, ballY);
		UpdateBall(ballX, ballY, ballMoveX, ballMoveY);
		gameOver = UpdatePlayerPosition(levelArray, playerX, playerY, width, ballX, ballY, ballMoveX, ballMoveY);
	}
	system("cls");
	DrawLevel(levelArray, width, height, playerX, playerY, ballX, ballY);
	cout << " YOU WON!!" << endl;

	

}

int GetIndexFromCoordinates(int x, int y, int width)
{
	return x + y * width;
}

void UpdateBall(int& ballX, int& ballY, int ballMoveX, int ballMoveY)
{
	ballX += ballMoveX;
	ballY += ballMoveY;
}

void DrawLevel(char level[], int width, int height, int playerX, int playerY, int ballX, int ballY)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (playerX == x && playerY == y)
			{
				cout << kPlayerSymbol;
			}
			else if (ballX == x && ballY == y)
			{
				cout << BAL;
			}
			else
			{
				int index = GetIndexFromCoordinates(x, y, width);
				cout << level[index];
			}

		}
		cout << endl;
	}
}

bool UpdatePlayerPosition(char level[], int& playerX, int& playerY, int width, int ballX, int ballY, int& ballMoveX, int& ballMoveY)
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

	if (newPlayerX == ballX && newPlayerY == ballY)
	{
		//todo: decide the ball movement direction here
		ballMoveX = 1;
		ballMoveY = 0;
	}

	playerX = newPlayerX;
	playerY = newPlayerY;

	cout << '@';
	return 0;

}