#pragma once
#include<iostream>
#include "clsCurrency.h"
#include"clsScreen.h"
#include "clsInputValidate.h"
class clsUpdateCurrencyScreen :protected clsScreen
{
   private:
	   static float _ReadRate()
	   {
		   cout << "Enter New Rate :";
		   float NewRate = 0;
		   NewRate = clsInputValidate::ReadFloatNumber();
		   return NewRate;
	   }
	   static void _PrintCurrency(clsCurrency Currency)
	   {
		   cout << "\n Currency Card :\n";
		   cout << "___________________________________\n";
		   cout << "\nCountry              :" << Currency.Country();
		   cout << "\nCode                 :" << Currency.CurrencyCode();
		   cout << "\nName                 :" << Currency.CurrencyName();
		   cout << "\nRate(1$)=            :" << Currency.Rate();
		   cout << "\n___________________________________\n";

	   }
public :
	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\t Update Currency Screen");
		string CurrencyCode = " ";
		cout << "Please Enter Currency Code :";
		cin >> CurrencyCode;
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << " Currency is not found ,choose another one :";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);
		cout << "\n Are you sure you want to update the rate of this Currency y/n";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			cout << " \n\n UpDate Currency Rate  ";
			cout << "\n___________________________\n";
			Currency.UpdateRate(_ReadRate());
			cout << "\n Currency Rate Update Successfully :-)\n";
			_PrintCurrency(Currency);
		}
	}
	


};

