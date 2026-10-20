#pragma once
#include<iostream>
#include "clsCurrency.h"
#include"clsScreen.h"
#include "clsInputValidate.h"
class clsFindCurrencyScreen :protected clsScreen
{
private :
	enum enFindCurrencyOptions {
		ecode=1,eCountry=2
	};
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
	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\n Currency  Found:-)!\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency was not Found:-(";
		}
	}
public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen ");
		cout << "Find By: [1] Code or [2] Country ?";
		short Answer = 1;
		cin >> Answer;
		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "Please Enter CurrencyCode :";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			string Country;
			cout << "Please Enter Country Name :";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}
	}
};

