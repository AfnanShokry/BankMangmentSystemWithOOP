#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iostream>
#include "Person.h"
class clsFindUserScreen :protected clsScreen
{
private:
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
  public :
	  static void ShowFindUserScreen()
	  {
		  _DrawScreenHeader("Find  User  Screen");
		  string User ;
		  cout << "Please Enter User :";
		 User = clsInputValidate::ReadString();
		  while (!clsUser::IsUserExist(User))
		  {
			  cout << " User is not found,choose another one:-)";
			 User = clsInputValidate::ReadString();





		  }
		  clsUser User1 = clsUser::Find(User);
		  if (!User1.IsEmpty())
		  {
			  cout << "\n User Found:-)";
		  }
		  else
		  {
			  cout << "\n User  was not Found:-(";
		  }
		  _PrintUserList(User1);
	  }


};

