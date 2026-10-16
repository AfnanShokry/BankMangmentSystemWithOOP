#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include"Global.h"
#include <string>
#include "clsString.h"
#include "clsDate.h"
#include"clsScreen.h"
#include "clsBankClient.h"
using namespace std;

class TransferLog: protected clsScreen
{
 private:
private:
    static void _PrintTransferRecordLine(clsBankClient::TransferlogRecord TransferRecord)
    {
        cout << setw(8) << left << " " << "|" << setw(23) << TransferRecord.Date;
        cout << "| " << setw(8) << left << TransferRecord.Acc1;
        cout << "| " << setw(8) << left << TransferRecord.Acc2;
        cout << "| " << setw(8) << left << TransferRecord.Amount;
        cout << "| " << setw(10) << left << TransferRecord.s_Balance;
        cout << "| " << setw(10) << left << TransferRecord.d_Balance;
        cout << "| " << setw(8) << left << TransferRecord.User;

    }
public:
    static void ShowLoginRegister()
    {
       
        vector<clsBankClient::TransferlogRecord>VTransfer = clsBankClient::GetLoginTransferList();
        string Title = "\t \t  Login Transfer List Screen";
        string SubTitle = "  \t (" + to_string(VTransfer.size()) + " )Record(s).";

        _DrawScreenHeader(Title, SubTitle);
        cout << setw(30) << left << " " << "\n_____________________________________________________________";
        cout << "_____________________________________________________________\n" << endl;;
        cout << setw(30) << left << " " << " |" << left << setw(15) << "Date/Timee";

        cout << " | " << setw(8) << left << "S.Acc   ";
        cout << " | " << setw(8) << left << "D.Acc";
        cout << " | " << setw(8) << left << "Amount";
        cout << " | " << setw(10) << left << "s.Balance";
        cout << " | " << setw(10) << left << "d.Balance";
        cout << " | " << setw(8) << left << "User";




        cout << setw(8) << left << " " << "\n_____________________________________________________________";
        cout << "_____________________________________________________________\n" << endl;;
        if (VTransfer.size() == 0)
            cout << "\t\t\t\t No User Available In the System!";
        else
        {
            for (clsBankClient::TransferlogRecord Record : VTransfer)
            {
                _PrintTransferRecordLine(Record);
                cout << endl;
            }
        }
    }
};

