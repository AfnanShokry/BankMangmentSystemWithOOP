#pragma once
#include <iostream>

#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>
using namespace std;
class clsAddNewUserScreen: protected clsScreen
{
  private:
      static void _ReadUserInfo(clsUser& User)
      {
          cout << "\n Enter FirstName :";
          User.SetFirstName(clsInputValidate::ReadString());
          cout << "\n Enter LastName :";
          User.SetLastName(clsInputValidate::ReadString());
          cout << "\n Enter Email:";
          User.SetEmail(clsInputValidate::ReadString());
          cout << "\n Enter Phone:";
          User.SetPhone(clsInputValidate::ReadString());
          cout << "\n Enter Password :";
          User.SetPassword(clsInputValidate::ReadString());
          cout << "\n Enter Permission :";
          User.SetPermissions(_ReadPermissionsToSet());

      }
      static void _PrintUserList(clsUser &User)
      {

          cout << "Info \n";
          cout << "____________________________________\n";
          cout << " \n  FristName  :     " << User.FirstName;
          cout << " \n  LastName   :     " << User.LastName;
          cout << " \n  FullName   :     " << User.FullName();
          cout << " \n  Email      :     " << User.Email;
          cout << " \n  Phone      :     " << User.Phone;
          cout << " \n Password    :     " << User.Password;
          cout << " \n Permission :      " << User.Permissions;

          cout << "\n_____________________________________\n";
      }
      static int _ReadPermissionsToSet()
      {
          


          int Permissions = 0;
          char Answer = 'n';


          cout << "\nDo you want to give full access? y/n? ";
          cin >> Answer;
          if (Answer == 'y' || Answer == 'Y')
          {
              return -1;
          }

          cout << "\nDo you want to give access to : \n ";

          cout << "\nShow Client List? y/n? ";
          cin >> Answer;
          if (Answer == 'y' || Answer == 'Y')
          {


              Permissions += clsUser::enPermissions::eListClient;
          }

          cout << "\nAdd New Client? y/n? ";
          cin >> Answer;
          if (Answer == 'y' || Answer == 'Y')
          {
              Permissions += clsUser::enPermissions::eAddNewClient;
          }

          cout << "\nDelete Client? y/n? ";
          cin >> Answer;
          if (Answer == 'y' || Answer == 'Y')
          {
              Permissions += clsUser::enPermissions::eDeleteClient;
          }

          cout << "\nUpdate Client? y/n? ";
          cin >> Answer;
          if (Answer == 'y' || Answer == 'Y')
          {
              Permissions += clsUser::enPermissions::eUpDateClient;
          }

          cout << "\nFind Client? y/n? ";
          cin >> Answer;
          if (Answer == 'y' || Answer == 'Y')
          {
              Permissions += clsUser::enPermissions::eFindClient;
          }

          cout << "\nTransactions? y/n? ";
          cin >> Answer;
          if (Answer == 'y' || Answer == 'Y')
          {
              Permissions += clsUser::enPermissions::eTransactions;
          }

          cout << "\nManage Users? y/n? ";
          cin >> Answer;
          if (Answer == 'y' || Answer == 'Y')
          {
              Permissions += clsUser::enPermissions::eManageUsers;
          }
          cout << "\n Show Login Register y/n? ";
          cin >> Answer;
          if (Answer == 'y' || Answer == 'Y')
          {
              Permissions += clsUser::enPermissions::eRegister;
          }
          return Permissions;

      }
      public:
          static void ShowAddNewClientScreen()
          {
              _DrawScreenHeader("AddNewUser");
              string UserName = " ";
              cout << "Please Enter UserName :";
              UserName = clsInputValidate::ReadString();
              while (clsUser::IsUserExist(UserName))
              {
                  cout << " UserName is already use,choose another one:-)";
                 UserName= clsInputValidate::ReadString();





              }
              clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
                  _ReadUserInfo(NewUser);
                  clsUser::enSaveResults SaveResult;
              SaveResult = NewUser.Save();
              switch (SaveResult)
              {
              case clsUser::enSaveResults::svSucceeded:

                  cout << " User Added Successfully :-)\n";
                  _PrintUserList(NewUser);
                  break;

              case clsUser::enSaveResults::svFaildEmptyObject:

                  cout << "\n Error User was not saved because it'sempty";
                  break;

                case clsUser::svFaildUserExists:
                  cout << "Error, User was not saved because  username is used ";
                  break;


              }
          }


};

