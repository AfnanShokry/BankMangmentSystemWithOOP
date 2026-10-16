#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h";
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsUpdateClient :protected clsScreen
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

    static  void ShowUpdateClient()
    {
        if (!CheckAccessRights(clsUser::enPermissions::eUpDateClient))
        {
            return;
        }
        _DrawScreenHeader("UpDate Screen");
        string AccountNumber = " ";
        cout << "Please Enter  Client AccountNumber ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << " Account Number isnot found,choose another one";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);
        cout << "Are you Sure you want to Update this Client y/n";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            cout << " \n\n UpDate Client Info ";
            cout << "\n___________________________\n";
            _ReadClientInfo(Client1);
            clsBankClient::enSaveResults SaveResult;
            SaveResult = Client1.Save();
            switch (SaveResult)
            {
            case clsBankClient::enSaveResults::svSuccedd:
            {
                cout << " Account Update Successfully";
                _PrintClient(Client1);
                break;
            }

            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << " \n Error account was not saved because it's Empty";
                break;
            }
            }
        }
    }
};

