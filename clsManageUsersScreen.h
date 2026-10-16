#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include"clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;
class clsManageUsersScreen :protected clsScreen
{
  private:

	  enum enManageMenueOptions 
	  {

		  eListUsers=1,eAddNewUser=2,eDeleteUser=3,eUpdateUser=4,eFindUser=5,eMainMenue=6
       };
	  static short _ReadManageUserMenue()
	  {
		  cout << setw(37) << left << " " << "Choose What do you want to do ?;[1,6]";
		  short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
		  return Choice;
	  }

	  static void _GoBackToManageUserMenue()
	  {
		  cout << "\n\nPress any key to go back to Transactions Menu....\n\n";
		  system("pause>0");
		  ShowManageUserMenue();
	  }
	  static void _ShowListUserScreen()
	  {
		  //cout << "\n List User Screen will be here";
		  clsUserListScreen::ShowUsersList();
		  
	  }
	  static void _ShowAddNewUser()
	  {
		 // cout << "\n Add New User will be here ";
		  clsAddNewUserScreen::ShowAddNewClientScreen();

	  }
	  static void _ShowDeleteUserScreen()
	  {
		  //cout << "\n Delete User will be here";
		  clsDeleteUserScreen::ShowDeleteUserScreen();

	  }
	  static void _ShowUpdateUserScreen()
	  {
		  //cout << "\n Update User Will be here";
		  clsUpdateUserScreen::ShowUpdateUser();
	  }
	  static void _ShowFindUserScreen()
	  {
		  //cout << " \n Find User Screen wuill be here";
		  clsFindUserScreen::ShowFindUserScreen();
	  }
	  static void _PerformManagUserMeuenOption(enManageMenueOptions ManageMenue)
	  {
		  switch (ManageMenue)
		  {
		  case enManageMenueOptions::eListUsers:
		  {
			  system("cls");
			  _ShowListUserScreen();
			  _GoBackToManageUserMenue();
			  break;
		  }

		  case enManageMenueOptions::eAddNewUser:
		  {
			  system("cls");
			  _ShowAddNewUser();
			  _GoBackToManageUserMenue();
			  break;
		  }
		  case enManageMenueOptions::eDeleteUser:
		  {
			  system("cls");
			  _ShowDeleteUserScreen();
			  _GoBackToManageUserMenue();
			  break;
		  }
		  case enManageMenueOptions::eUpdateUser:
		  {
			  system("cls");
			  _ShowUpdateUserScreen();
			  _GoBackToManageUserMenue();
		  }
		  case enManageMenueOptions::eFindUser:
		  {

			  system("cls");
			  _ShowFindUserScreen();
			  _GoBackToManageUserMenue();
		  }
		  case enManageMenueOptions::eMainMenue:
		  {

		  }
		  }
	  }
public:
	static void ShowManageUserMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::eManageUsers))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t Manage User Screen");

		cout << setw(37) << left << "" << "===========================================\n";

		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] ListUser.\n";
		cout << setw(37) << left << "" << "\t[2] Add NewUser.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6]MainMenue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformManagUserMeuenOption((enManageMenueOptions)_ReadManageUserMenue());
	}

};

