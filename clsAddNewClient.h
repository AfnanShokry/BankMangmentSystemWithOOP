#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h";
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsAddNewClient :protected clsScreen
{
   private : 
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
     static void _ReadClientInfo(clsBankClient& Client)
   {
	   cout << "\n Enter FristName :";
	   Client.SetFirstName(clsInputValidate::ReadString());
	   cout << "\n Enter LasttName :";
	   Client.SetLastName(clsInputValidate::ReadString());
	   cout << "\n Enter Email:";
	   Client.SetEmail(clsInputValidate::ReadString());
	   cout << "\n Enter Phone:";
	   Client.SetPhone(clsInputValidate::ReadString());
	   cout << "\n Enter PinCode :";
	   Client.SetPincode(clsInputValidate::ReadString());
	   cout << "\n Enter AccountBalance :";
	   Client.accountbalance = clsInputValidate::ReadFloatNumber();

   } 
public:
   static void ShowAddNewClientScreen()
   {
	   if (!CheckAccessRights(clsUser::enPermissions::eAddNewClient))
	   {
		   return;
	   }
	   _DrawScreenHeader("AddNewClient");
       string AccountNumber = " ";
       cout << "Please Enter AccountNumber :";
       AccountNumber = clsInputValidate::ReadString();
       while (clsBankClient::IsClientExist(AccountNumber))
       {
           cout << " AccountNumber is already use,choose another one:-)";
           AccountNumber = clsInputValidate::ReadString();





       }
       clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
	   _ReadClientInfo(NewClient);
       clsBankClient::enSaveResults SaveResult;
       SaveResult = NewClient.Save();
       switch (SaveResult)
       {
       case clsBankClient::enSaveResults::svSuccedd:

           cout << " Account Added Successfully :-)\n";
		   _PrintClient(NewClient);
           break;

       case clsBankClient::enSaveResults::svFaildEmptyObject:

           cout << "\n Error account was not saved because it'sempty";
           break;

       case clsBankClient::svFaildAccountNumberExists:

           cout << "Error, account was not saved because accountnumber is used ";
           break;


       }
   }

};

