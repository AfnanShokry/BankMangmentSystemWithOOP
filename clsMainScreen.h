#pragma once
#include <iostream>
#include  "clsScreen.h";
#include  <iomanip>
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include  "clsAddNewClient.h"
#include  "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "claTransactionsMenueOptions.h"
#include  "Global.h"
#include "clsManageUsersScreen.h"
#include "clsLoginScreen.h"
#include "clsLoginRegister.h"
#include "clsCurrencyExChange.h"
using namespace std;
class clsMainScreen :protected clsScreen  
{
 private:
	 enum enMainOptaion {
       eListClient=1,eAddClient=2,eDeleteClient=3,eUpdateClient=4,
       eFindClient=5, eShowTransactionsMenue = 6, eManageUsers = 7, eLoginRegister=8,CurrencyExchange=9,eExit = 10
    	};
	 static short _ReadMainMenueOption()
	 {
		 cout << setw(37) << left << "  " << "Choose What do you want to do [1,10] :";
		 short Choise = clsInputValidate::ReadShortNumberBetween(1, 10, " Enter Number between [1,10]");
		 return  Choise;
     }
	 static void _GoBackToMainMenue()
	 {
		 cout << setw(37) << left << "  " << "\n Press any key to go MainMenue\n";
		 system("pause>0");
		 ShowMainMenue();
	 }
	 static void _AllClientList()
	 {
		 clsClientListScreen::ShowClientsList();
	 }
	 static void _ShowAddClient()
	 {
		// cout << " Add Client Scrren it will be here ";
		 clsAddNewClient::ShowAddNewClientScreen();
	 }
	 static void _ShowDeleteClient()
	 {
		 //cout << " Delete Client Scrren it will be here ";
		 clsDeleteClient::ShowDeleteClient();
	 }
	 static void _ShowUpdateClient()
	 {
		// cout << " Update Client Scrren it will be here ";
		 clsUpdateClient::ShowUpdateClient();
	 }
	 static void _ShowFindClient()
	 {
		// cout << " Find Client Scrren it will be here ";
		 clsFindClientScreen::ShowFindClientScreen();
	 }
	 static void _ShowTransactionsMenue()
	 {
		// cout << " TransactionsMenue Scrren it will be here ";
		 claTransactionsMenueOptions::ShowTransactionsMenue();
	 }
	 static void _ShoManageUser()
	 {
		 //cout << " ManageUser Scrren it will be here ";
		 clsManageUsersScreen::ShowManageUserMenue();
		 
	 }
	 
	 static void _ShowManageMenue()
	 {
		// cout << " Manage Menue Scrren it will be here ";
		 clsManageUsersScreen::ShowManageUserMenue();
	 }
	 /*static void _ShowEndScreen()
	 {
		 cout << "LogoutMenue Scrren it will be here ";
	 }

	*/
	 static void _LogOut()
	 {
		 CurrentUser = clsUser::Find(" ", " ");
		 
		
	 }
	 static void _ShowLoginRegister()
	 {
		 clsLoginRegister::ShowLoginRegister();
	 }
	 static void _ShowCuerrencyExChange()
	 {
		 clsCurrencyExChange::ShowCurrencyExChangMenue();
	 }

	 static void _PerfromMainMenueOption(enMainOptaion MainOptaion)
	 {
		 switch (MainOptaion)
		 {
		   case enMainOptaion::eListClient:
		   {
			   system("cls");
			   _AllClientList();
			   _GoBackToMainMenue();
			   break;
		   }
		   case enMainOptaion::eAddClient:
		   {
			   system("cls");
			   _ShowAddClient();
			   _GoBackToMainMenue();
		   }
		   case enMainOptaion::eDeleteClient:
		   {
			   system("cls");
			   _ShowDeleteClient();
			   _GoBackToMainMenue();
			   break;
		   }
		   case enMainOptaion::eUpdateClient:
		   {
			   system("cls");
			   _ShowUpdateClient();
			   _GoBackToMainMenue();
			   break;
		   }
		   case enMainOptaion::eFindClient:
		   {
			   system("cls");
			   _ShowFindClient();
			   _GoBackToMainMenue();
			   break;
		   }
		   case enMainOptaion::eShowTransactionsMenue:
		   {
			   system("cls");
			   _ShowTransactionsMenue();
			   _GoBackToMainMenue();
			   break;
		   }
		   case enMainOptaion::eManageUsers:
		   {
			   system("cls");
			   _ShowManageMenue();
			   _GoBackToMainMenue();
			 
			   break;
		   }
		   case enMainOptaion::eLoginRegister:
		   {
			   system("cls");
			   _ShowLoginRegister();
			   _GoBackToMainMenue();
		   }
		   case enMainOptaion::CurrencyExchange:
		   {
			   system("cls");
			   _ShowCuerrencyExChange();
			   _GoBackToMainMenue();
		   }
		   case enMainOptaion::eExit:
		   {
			   system("cls");
			   _LogOut();
			   break;
		   }
		 }
		
	 }
public :
		 
  static void ShowMainMenue()
	 {
	  system("cls");
	  _DrawScreenHeader("\t\tMain Screen");
	  cout << setw(37) << left << "" << "===========================================\n";

	  cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
	  cout << setw(37) << left << "" << "===========================================\n";
	  cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
	  cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
	  cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
	  cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
	  cout << setw(37) << left << "" << "\t[5] Find Client.\n";
	  cout << setw(37) << left << "" << "\t[6] Transactions.\n";
	  cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
	  cout << setw(37) << left << "" << "\t[8] LoginRegister.\n";
	  cout << setw(37) << left << "" << "\t[9] CurrencyExchange.\n";
	  cout << setw(37) << left << "" << "\t[10] Logout.\n";
	  cout << setw(37) << left << "" << "===========================================\n";
	  _PerfromMainMenueOption(enMainOptaion(_ReadMainMenueOption()));






	 }
};

