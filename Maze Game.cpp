#include <iostream>
#include <conio.h>

using namespace std;
constexpr char kPlayerSymbol = '@';

int GetIndexFromCoordunates(int x, int y, int width);
void DrawLevel(char level[], int width, int height, int playerX, int playerY);
bool UpdatePlayerPosition(char level[], int& playerX, int& playerY, int width, bool& playerHasKey);

int main()
{
	constexpr int kWidth = 25;
	constexpr int kHeight = 15;

	char levelArray[]{	'+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','*','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','+','-',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','+','-','-','-','-','-','-','-','-','-','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',
						'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','D',' ',' ',' ',' ',' ',' ',' ',' ','X','|',
						'+','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','+', };

	int playerX = 1;
	int playerY = 1;
	bool playerHasKey = false;
	bool gameOver = false;

	while (!gameOver)
	{
		system("cls");
		DrawLevel(levelArray, kWidth, kHeight, playerX, playerY);
		gameOver = UpdatePlayerPosition(levelArray, playerX, playerY, kWidth, playerHasKey);
	}
	system("cls");
	DrawLevel(levelArray, kWidth, kHeight, playerX, playerY);
	cout << " YOU WON!!" << endl;
	

}	

int GetIndexFromCoordunates(int x, int y, int width)
{
	return x + y * width;
}

void DrawLevel(char level[], int width, int height, int playerX, int playerY)
{
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (playerX == x && playerY == y)
			{
				cout << kPlayerSymbol;
			}
			else
			{
				int index = GetIndexFromCoordunates(x, y, width);
				cout << level[index];
			}
			
		}
		cout << endl;
	}
}

bool UpdatePlayerPosition(char level[], int& playerX, int& playerY, int width, bool& playerHasKey)
{
	char input = _getch();

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

	int index = GetIndexFromCoordunates(newPlayerX, newPlayerY, width);
	if (level[index] == ' ')
	{
		playerX = newPlayerX;
		playerY = newPlayerY;
	}
	else if (level[index] == '*')
	{
		playerHasKey = true;
		level[index] = ' ';
		playerX = newPlayerX;
		playerY = newPlayerY;
	}
	else if (level[index] == 'D' && playerHasKey )
	{
		level[index] = ' ';
		playerHasKey = false;
		playerY = newPlayerY;
		playerX = newPlayerX;
	}
	else if (level[index] == 'X')
	{
		level[index] = ' ';
		playerY = newPlayerY;
		playerX = newPlayerX;
		return true;
	}
	return false;

}