// MainScreen.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include "clsLoginScreen.h"

int main()
{
	//clsMainScreen::ShowMainMenue();
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
	     }
	}
	return 0;


}