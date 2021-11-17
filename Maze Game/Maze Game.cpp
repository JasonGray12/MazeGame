#include <iostream>
#include "Game.h"
#include "AudioManager.h"

using namespace std;


int main()
{
	Game myGame;
	
	if (myGame.Load())
	{
		while (!myGame.IsGameOver())
		{
			myGame.Run();
		}

		if (myGame.DidUserQuit())
		{
			cout << "Thanks for playing!" << endl;
		}
		else if (myGame.GetPlayerLives() < 0)
		{
			cout << "Sorry, you lose!!" << endl;
			AudioManager::GetInstance()->PlayLoseSound();
		}
		else
		{
			cout << "YOU WON!!!!" << endl;
			AudioManager::GetInstance()->PlayWinSound();
		}

	}
	else
	{
		cout << "Game did not load. Terminating now!" << endl;
	}

	AudioManager::DestroyInstance();

	return 0;
}	



