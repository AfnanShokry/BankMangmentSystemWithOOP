#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h";
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsDeleteClient : protected clsScreen
{
private:
    static  void _PrintClient(clsBankClient& Client)
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
     public:
 static   void ShowDeleteClient()
    {
     if (!CheckAccessRights(clsUser::enPermissions::eDeleteClient))
     {
         return;
     }
        string AcccountNumber = " ";
        cout << "Please Enter AccountNumber :";
        clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AcccountNumber))
        {
            cout << "AccountNumber is not found ,chosse another one";
            AcccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient NewClient = clsBankClient::Find(AcccountNumber);
        _PrintClient(NewClient);
        cout << "Are you Sure you want to delete this Client y/n";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (NewClient.Delete())
            {
                cout << "\n Client Deleted Successfully :-)";
                _PrintClient(NewClient);
            }
            else
            {
                cout << "\n Error ,Client wasnot Deleted:-( \n";
            }
        }
    }
};

