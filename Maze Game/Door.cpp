#include <iostream>
#include <Windows.h>
#include "Door.h"

Door::Door(int x, int y, int color, int ClosedColor)
	:PlaceableActor(x, y, color)
	, m_IsOpen(false)
	, m_ClosedColor(ClosedColor)
{

}

void Door::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (m_IsOpen)
	{
		SetConsoleTextAttribute(console, m_color);
	}
	else
	{
		SetConsoleTextAttribute(console, m_ClosedColor);
	}
	std::cout << "|";
	SetConsoleTextAttribute(console, kRegularColor);
}