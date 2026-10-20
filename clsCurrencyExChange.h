#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesList.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyExChange:protected clsScreen
{
private:
	enum enCurrencyExChange {
		enListCurrency=1,
		enFindCurrency=2,
		enUpdateCurrency=3,
		enCurrencyCalculator=4,
		enMainMenue=5
	};
	static short _ReadCurrencyExChangeMenue()
	{
		cout << setw(37) << left << " " << "Choose What do you want to do ?;[1,5]";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
		return Choice;
	}
	static void _GoBackToCurrencyExChangeMenue()
	{
		cout << "\n\nPress any key to go back to Currencies Menu....\n\n";
		system("pause>0");
		ShowCurrencyExChangMenue();
	}
	static void ShowListCurrencies()
	{
		/*cout << "List Currencies will be here ";*/
		clsCurrenciesList::ShowCurrencyList();
	}
	static void ShowFindCurrency()
	{
		/*cout << "Find Currency will be here ";*/
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void ShowUpdateRate()
	{
		/*cout << "Updat eRatewill be here ";*/
		clsUpdateCurrencyScreen::ShowUpdateCurrencyRateScreen();
	}
	static void ShowCurrencyCalculator()
	{
		/*cout << "UCurrency Calculator will be here ";*/
		clsCurrencyCalculatorScreen::ShowCurrencytCalculationsScreen();
	}
	static void _PerformCurrencyExChangeMeuenOption(enCurrencyExChange Currency)
	{
		switch (Currency)
		{
		case enCurrencyExChange::enListCurrency:
		{
			system("cls");
			ShowListCurrencies();
			_GoBackToCurrencyExChangeMenue();
			break;
		}

		case enCurrencyExChange::enFindCurrency:
		{
			system("cls");
			ShowFindCurrency();
			_GoBackToCurrencyExChangeMenue();
			break;
		}
		case enCurrencyExChange::enUpdateCurrency:
		{
			system("cls");
			ShowUpdateRate();
			_GoBackToCurrencyExChangeMenue();
			break;
		}
		case enCurrencyExChange::enCurrencyCalculator:
		{
			system("cls");
			ShowCurrencyCalculator();
			_GoBackToCurrencyExChangeMenue();
			break;
		}

		case enCurrencyExChange::enMainMenue:
		{

		}

		}
	}
    public:
	static void ShowCurrencyExChangMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::eManageUsers))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t Currency ExChange Screen");

		cout << setw(37) << left << "" << "===========================================\n";

		cout << setw(37) << left << "" << "\t\t\tCurrency ExChange  Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] ListCurrencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4]CurrencyCalculator.\n";
		cout << setw(37) << left << "" << "\t[5]MainMenue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformCurrencyExChangeMeuenOption((enCurrencyExChange)_ReadCurrencyExChangeMenue());
	}

};

