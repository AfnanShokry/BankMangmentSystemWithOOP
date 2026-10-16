#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include"Global.h"
#include <string>
#include "clsString.h"
#include "clsDate.h"
#include"clsScreen.h"
using namespace std;
class clsLoginRegister :protected clsScreen
{
  private:
      static void _PrintUserRecordLine(clsUser ::stLoginRegisterRecord LoginRegisterReord)
      {
          cout << setw(8) << left << " " << "|" << setw(35) << LoginRegisterReord.DateTime;
          cout << "| " << setw(25) << left << LoginRegisterReord.UserName;
          cout << "| " << setw(10) << left << LoginRegisterReord.Password;
          cout << "| " << setw(10) << left << LoginRegisterReord.Permissions;
      }
  public:
      static void ShowLoginRegister()
      {
          if (!CheckAccessRights(clsUser::enPermissions::eRegister))
          {
              return;
          }
          vector<clsUser::stLoginRegisterRecord>VUser = clsUser::GetLoginRegisterList();
          string Title = "\t \t  Login Register List Screen";
          string SubTitle = "  \t (" + to_string(VUser.size()) + " )Record(s).";

          _DrawScreenHeader(Title, SubTitle);
          cout << setw(30) << left << " " << "\n_____________________________________________________________";
          cout << "_____________________________________________________________\n" << endl;;
          cout << setw(30) << left << " " << " |" << left << setw(15) << "Date/Timee";

          cout << " | " << setw(30) << left << "UserName   ";
          cout << " | " << setw(30) << left << "Password";
          cout << " | " << setw(30) << left << "permissions";

          cout << setw(8) << left << " " << "\n_____________________________________________________________";
          cout << "_____________________________________________________________\n" << endl;;
          if (VUser.size() == 0)
              cout << "\t\t\t\t No User Available In the System!";
          else
          {
              for (clsUser::stLoginRegisterRecord Record:VUser)
              {
                  _PrintUserRecordLine(Record);
                  cout << endl;
              }
          }
      }
};

