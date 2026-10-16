#pragma once
#include<iostream>
#include <iomanip>
#include "clsBankClient.h";
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsDepositScreen :protected clsScreen
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
	  static string _ReadAccountNumber()
	  {

		  string AccountNumber = " ";
		  cout << "Please Enter AccountNumber :";
		  cin >> AccountNumber;
		  return AccountNumber;
	  }
public :
	  static void ShowDepositScreen()
	  {
		  _DrawScreenHeader("DepositScreen");
		  string AccountNumber = _ReadAccountNumber();
		  while (!clsBankClient::IsClientExist(AccountNumber))
		  {
			  cout << " Client With["<<AccountNumber<<" ] dose not exsit";
			  AccountNumber = _ReadAccountNumber();





		  }
		  clsBankClient  Client1 = clsBankClient::Find(AccountNumber);
		  _PrintClient(Client1);
		  double Amount = 0;
		  cout << "Please enter deposit amount ?";
		  Amount = clsInputValidate::ReadDblNumber();
		  cout << "\n Are you Sure you want to performthis trasaction?";
		  char Answer = 'n';
		  cin >> Answer;
		
		  if (Answer == 'Y' || Answer == 'y')
		  {
			  



			  Client1.Deposit(Amount);
			  cout << "Amount Deposit Successfully .\n";
			  cout << " New Balance Is" << Client1.AccountBalance();
		  }
		  else
		  {
			  cout << "Operation was cancelled";
		  }
	  }

};

