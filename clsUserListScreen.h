#pragma once
#include<iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"

class clsUserListScreen :protected  clsScreen
{
private:
    static void _PrintUserRecordLine(clsUser User)
    {
        cout << setw(8) << left << " " << "|" << setw(12) << "" << User.UserName;
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(15) << left << User.Phone;
        cout << "| " << setw(15) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(10) << left << User.Permissions;
    }
public:
    static void ShowUsersList()
    {
        vector<clsUser>VUser = clsUser::GetUsersList();
        string Title = "\t \t  User List Screen";
        string SubTitle = "  \t (" + to_string(VUser.size()) + " )User(s).";

        _DrawScreenHeader(Title, SubTitle);
        cout << setw(10) << left << " " << "\n_____________________________________________________________";
        cout << "_____________________________________________________________\n" << endl;;
        cout << setw(10) << left << " " << " |" << left << setw(15) << "UserName";

        cout << " | " << setw(20) << left << "FullName   ";
        cout << " | " << setw(12) << left << "Phone";
        cout << " | " << setw(20) << left << "Email";
        cout << " | " << setw(10) << left << "Password";
        cout << " | " << setw(13) << left << "permissions";

        cout << setw(8) << left << " " << "\n_____________________________________________________________";
        cout << "_____________________________________________________________\n" << endl;;
        if (VUser.size() == 0)
            cout << "\t\t\t\t No User Available In the System!";
        else
        {
            for (clsUser& U : VUser)
            {
                _PrintUserRecordLine(U);
                cout << endl;
            }
        }
    }
};





