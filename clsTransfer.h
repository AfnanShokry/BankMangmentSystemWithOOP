#pragma once
#include<iostream>
#include <iomanip>
#include "clsBankClient.h";
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsTransfer :protected clsScreen
{
private:
	static  void _PrintClient(clsBankClient  Client)
	{

		cout << "Info \n";
		cout << "____________________________________\n";

		cout << " \n  FullName   :     " << Client.FullName();
		cout << " \n  AccountNumber :  " << Client.AccountNumber();
		cout << " \n Acc.Balance :     " << Client.AccountBalance();

		cout << "\n_____________________________________\n";

	}
	static string _ReadAccountNumber()
	{

		string AccountNumber ;
		cout << "Please Enter AccountNumber to Transfer From  :";
		
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "AccountNumber is not found ,Choose another one:";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}
	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;
		cout << "Enter Tranfer Amount ?";
		Amount = clsInputValidate::ReadFloatNumber();
		while (Amount > SourceClient.accountbalance)
		{
			cout << "\n Amount Exceeds the available Balance ,Enter another Amount?";
			Amount = clsInputValidate::ReadFloatNumber();
		}
		return Amount;
	}
   public:
	   static void ShowTransferScreen()
	   {
		   _DrawScreenHeader("\t Transfer Screen");
		   clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		   _PrintClient(SourceClient);
		   clsBankClient DestinationClient= clsBankClient::Find(_ReadAccountNumber());
		   _PrintClient(DestinationClient);
		   float Amount = ReadAmount(SourceClient);
		   cout << "\n Are you Sure you want to performthis Operation?y/n";
		   char Answer = 'n';
		   cin >> Answer;

		   if (Answer == 'Y' || Answer == 'y')
		   {
			   if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			   {
				   cout << "Transfer done successfully \n";
			   }
			   else
			   {
				   cout << "\N Transfer Faild";
			   }

		   }
		   _PrintClient(SourceClient);
		   _PrintClient(DestinationClient);

     	 }
	   
};

