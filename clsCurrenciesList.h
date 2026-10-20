#pragma once
#include<iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"
class clsCurrenciesList :public clsScreen
{
private:
    static void _PrintCurrencyRecordLine(clsCurrency User)
    {
         cout << setw(8) << left <<  left << setw(15) << User.Country();
        //  cout << " | " << setw(12) << left << stClients.AccountNumber();
         cout << " | " << setw(12) << left << User.CurrencyCode();
         cout << " | " << setw(20) << left << User.CurrencyName();
         cout << " | " << setw(20) << left << User.Rate();
       
    }
public:
    static void ShowCurrencyList()
    {
        vector<clsCurrency>VCurrency = clsCurrency::GetCurrenciesList();
        string Title = "\t \t Currencies List Screen";
        string SubTitle = "  \t (" + to_string(VCurrency.size()) + " )Currency.";

        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << " " << "\n_____________________________________________________________";
        cout << "_____________________________________________________________\n" << endl;;
        cout << setw(8) << left  << " |" << left << setw(15) << "Country";

        cout << " | " << setw(20) << left << "Code   ";
        cout << " | " << setw(12) << left << "Name";
        cout << " | " << setw(10) << left << "Rate/(1$)";
       

        cout << setw(8) << left << " " << "\n_____________________________________________________________";
        cout << "_____________________________________________________________\n" << endl;;
        if (VCurrency.size() == 0)
            cout << "\t\t\t\t No User Available In the System!";
        else
        {
            for (clsCurrency& U : VCurrency)
            {
                _PrintCurrencyRecordLine(U);
                cout << endl;
            }
        }
    }
};


