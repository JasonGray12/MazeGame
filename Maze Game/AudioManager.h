#pragma once
#include <Windows.h>


class AudioManager
{
	static AudioManager* s_pInstance;

	AudioManager()
	{

	}

public:
	static AudioManager* GetInstance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new AudioManager();
		}
		return s_pInstance;
	}

	static void DestroyInstance()
	{
		delete s_pInstance;
		s_pInstance = nullptr;
	}

	void PlayClosedDoorSound()
	{
		Beep(500, 75);
		Beep(500, 75);
	}

	void PlayOpenDoorSound()
	{
		Beep(1397, 200);
	}

	void PlayKeyPickUpSound()
	{
		Beep(1568, 50);
		Beep(1568, 200);
	}

	void PlayKeyDropSound()
	{
		Beep(1568, 200);
		Beep(1568, 50);
	}

	void PlayMoneySound()
	{
		Beep(1568, 50);
	}

	void PlayLoseLivesSound()
	{
		Beep(200, 100);
	}

	void PlayLoseSound()
	{
		Beep(500, 75);
		Beep(500, 75);
		Beep(500, 75);
		Beep(500, 75);
	}

	void PlayWinSound()
	{
		Beep(1568, 200);
		Beep(1568, 200);
		Beep(1568, 200);
		Beep(1245, 1000);
		Beep(1397, 200);
		Beep(1397, 200);
		Beep(1397, 200);
		Beep(1175, 1000);

	}

};