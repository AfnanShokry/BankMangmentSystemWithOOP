#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iostream>

class clsUpdateUserScreen : protected clsScreen
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
    static void _PrintUserList(clsUser& User)
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
        cout << "\n ShowLogin Register y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::eRegister;
        }

        return Permissions;

    }
    public :
        static  void ShowUpdateUser()
        {
            _DrawScreenHeader("UpDate User  Screen");
            string UserName = " ";
            cout << "Please Enter  User Name ";
           UserName = clsInputValidate::ReadString();
            while (!clsUser::IsUserExist(UserName))
            {
                cout << " User Name isnot found,choose another one";
                UserName = clsInputValidate::ReadString();
            }
            clsUser User1 = clsUser::Find(UserName);
            _PrintUserList(User1);
            cout << "Are you Sure you want to Update this User y/n";
            char Answer = 'n';
            cin >> Answer;
            if (Answer == 'Y' || Answer == 'y')
            {
                cout << " \n\n UpDate Client Info ";
                cout << "\n___________________________\n";
                _ReadUserInfo(User1);
                clsUser::enSaveResults SaveResult;
                SaveResult = User1.Save();
                switch (SaveResult)
                {
                  case clsUser::enSaveResults::svSucceeded:
                  {
                    cout << " User Update Successfully";
                   _PrintUserList(User1);
                    break;
                  }

                  case clsUser::enSaveResults::svFaildEmptyObject:
                  {
                    cout << " \n Error User  was not saved because it's Empty";
                    break;
                  }
                }
            }
        }

};

