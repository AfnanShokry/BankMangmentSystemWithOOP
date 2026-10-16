#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h";
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsFindClientScreen : protected clsScreen
{
  private:
	  static  void _PrintClient(clsBankClient  Client)
	  {

		  cout << "Info \n";
		  cout << "____________________________________\n";
		  cout << " \n  AccountNumber :  " << Client.AccountNumber();
		  cout << " \n  FristName  :     " << Client.FirstName;
		  cout << " \n  LastName   :     " << Client.LastName;
		  cout << " \n  FullName   :     " << Client.FullName();
		  cout << " \n  Email      :     " << Client.Email;
		  cout << " \n  Phone      :     " << Client.Phone;
		  cout << " \n Password    :     " << Client.Pincode();
		  cout << " \n Acc.Balance :     " << Client.AccountBalance();

		  cout << "\n_____________________________________\n";

	  }
public :
	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::eFindClient))
		{
			return;
		}
		_DrawScreenHeader(" Find Client Screen");
		string AccountNumber = " ";
		cout << "Please Enter AccountNumber :";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << " AccountNumber is not found,choose another one:-)";
			AccountNumber = clsInputValidate::ReadString();





		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		if (!Client1.IsEmpty())
		{
			cout << "\n Client Found:-)";
		}
		else
		{
			cout << "\n Client  was not Found:-(";
		}
		_PrintClient(Client1);
	}

};

