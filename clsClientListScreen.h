#pragma once
#include<iostream>
#include <iomanip>
#include "clsBankClient.h";
#include "clsScreen.h"
class clsClientListScreen :protected clsScreen
{

private :
  static  void  _PrintClientRecord(clsBankClient  stClients)//æÙíİÊåÇ ØÈÇÚÉ ÈíÇäÇÊ Úãíá æÇÍÏ İŞØ İí ÓØÑ æÇÍÏ
    {
      
        //áÊÍÏíÏ ÚÑÖ ËÇÈÊ áßá ÚãæÏsetw(10)
        cout << setw(8) << left << " " << " |" << left << setw(15) << stClients.AccountNumber();
      //  cout << " | " << setw(12) << left << stClients.AccountNumber();
        cout << " | " << setw(12) << left << stClients.FullName();
        cout << " | " << setw(20) << left << stClients.Phone;
        cout << " | " << setw(20) << left << stClients.Email;
        cout << " | " << setw(10) << left << stClients.Pincode();
        cout << " | " << setw(12) << left << stClients.AccountBalance();
    }

public:
  static  void ShowClientsList()

  {
      if (!CheckAccessRights(clsUser::enPermissions::eListClient))
      {
          return;
      }
        vector<clsBankClient>VClient = clsBankClient::GetClientsList();
        string Title = "\t Client List Screen";
        string SubTitle = "  \t (" + to_string(VClient.size()) + " )Client(s).";
       
        _DrawScreenHeader(Title,SubTitle);
         cout <<setw(8) <<left<<" " << "\n_____________________________________________________________";
         cout << "_____________________________________________________________\n" << endl;;
        cout << setw(8) << left << " " << " |" << left << setw(15) << "AccountNumber";
        
        cout << " | " << setw(20) << left << "ClientName   ";
        cout << " | " << setw(12) << left << "Phone";
        cout << " | " << setw(20) << left << "Email";
        cout << " | " << setw(10) << left << "PinCode";
        cout << " | " << setw(13) << left << "AccountBalance";
       
        cout << setw(8) << left << " " << "\n_____________________________________________________________";
        cout << "_____________________________________________________________\n" << endl;;
        if (VClient.size() == 0)
            cout << "\t\t\t\t No Clients Available In the System!";
        else
        {
            for (clsBankClient& s : VClient)
            {
                _PrintClientRecord(s);
                cout << endl;
            }
        }

    }

};

