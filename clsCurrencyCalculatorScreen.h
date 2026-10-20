#pragma once
#include<iostream>
#include "clsCurrency.h"
#include"clsScreen.h"
#include "clsInputValidate.h"
class clsCurrencyCalculatorScreen :protected clsScreen
{
private:
	static float _ReadAmount()
	{
		cout << "Enter Amount to Exchange:";
		float Amount = 0;
		
		Amount=clsInputValidate::ReadFloatNumber();
		return Amount;
	}
	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode;
		cout << Message << endl;
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "Currency is not found ,choss another one";
			CurrencyCode = clsInputValidate::ReadString();

		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}
	static void _PrintCurrencyCard(clsCurrency Currency,string Title="Currency Card")
	{
		cout << "\n Currency Card :\n";
		cout << "___________________________________\n";
		cout << "\nCountry              :" << Currency.Country();
		cout << "\nCode                 :" << Currency.CurrencyCode();
		cout << "\nName                 :" << Currency.CurrencyName();
		cout << "\nRate(1$)=            :" << Currency.Rate();
		cout << "\n___________________________________\n";

	 }

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1, "ConvertForm");
		float AmountInUSD = Currency1.ConvertTOUSD(Amount);
		cout << Amount <<" " << Currency1.CurrencyCode() << " = " << AmountInUSD << "USD\n";
		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}
		cout << "\n Converting from USD to";
		_PrintCurrencyCard(Currency2, "To");
		float AmountInCurrency2 = Currency1.ConverttoOtherCurrency(Amount, Currency2);
		cout << Amount << Currency1.CurrencyCode() << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();
	}
public :
	static void ShowCurrencytCalculationsScreen()
	{
		char Continue = 'y';
		while (Continue == 'Y' || Continue =='y')
		{
			system("cls ");
			_DrawScreenHeader("Update Currency Screen");
			clsCurrency CurrencyForm = _GetCurrency("Please Enter Currency 1 code");
			clsCurrency CurrencyTo = _GetCurrency("Please Enter Currency   2 code");
			float Amount = _ReadAmount();
			_PrintCalculationsResults(Amount, CurrencyForm, CurrencyTo);
			cout << "\nDone you want to perform another calculation? y\n ?";
			cin >> Continue;

		}
	}
};

