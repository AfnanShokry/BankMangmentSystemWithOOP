#pragma once
#include<iostream>
#include <iomanip>
#include "clsBankClient.h";
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsTotalBalancesScreen : protected clsScreen
{
private :
	static void PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << setw(10) << left << " " << " | " << setw(15) << left << Client.AccountNumber();
		cout << "|" << setw(30) << left << Client.FullName();
		cout << "|" << setw(12) << left << Client.AccountBalance();

	}
public:
	static void ShowTotalBalances()
	{
		vector<clsBankClient>Vclient = clsBankClient::GetClientsList();
		string Title = "\t Balance List Screen ";
		string SubTitle = "\t   (" + to_string(Vclient.size()) + ") Client(s) ";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << " " << "\n_____________________________________________________________";
		cout << "_____________________________________________________________\n" << endl;;
		cout << setw(10) << left << " " << " |" << left << setw(15) << "AccountNumber";

		cout << " | " << setw(30) << left << "ClientName   ";
		cout << " | " << setw(30) << left << "Balance" << endl;
		double TotalBalance = clsBankClient::GetTotalBalance();
		if (Vclient.size() == 0)
			cout << "\t\t\t\t No Clients Available In the System!" << endl;
		else
			for (clsBankClient Client : Vclient)
			{
				PrintClientRecordBalanceLine(Client);
				cout << endl;
		}
		cout << "\n_____________________________________________________________";
		cout << "_____________________________________________________________\n" << endl;;
		cout << "\t Total Balances:" << TotalBalance << endl;
		cout << "\t(" << clsUtility::NumberToText(TotalBalance) << ")";
	}

};

