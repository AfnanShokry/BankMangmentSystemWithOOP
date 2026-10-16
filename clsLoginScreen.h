#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include <iostream>
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
	
  private :
	  
	static  bool  _Login()
	{
		bool LoginFaild = false;
		short FaildLoginCount = 0;
		string UserName, Password;
		do
		{
			if (LoginFaild)
			{
				FaildLoginCount++;
				cout << "\n Invlaid UserName,Password!\n\n";
				cout << "You have" <<( 3-FaildLoginCount) << " Trial(s) to login.\n\n";
			}
			if (FaildLoginCount == 3)
			{
				cout << "you are locked after 3 failed trails\n";
				return false;
			}
			cout << "Enter User Name?";
			cin >> UserName;
			cout << "Enter Password?";
				cin >> Password;
				CurrentUser = clsUser::Find(UserName, Password);
				LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);
		CurrentUser.RegisterLogIn();
	    clsMainScreen::ShowMainMenue();
		return true;
	}
  public :

	  static bool ShowLoginScreen()
	  {
		  system("cls");
		  _DrawScreenHeader("\t Login Screen");
		 return  _Login();
	  }
};

