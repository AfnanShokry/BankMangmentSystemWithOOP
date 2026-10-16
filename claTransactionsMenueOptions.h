#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h";
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include  "clsWithdrawScreen.h"
#include  "clsTotalBalancesScreen.h"
#include"clsTransfer.h"
#include "TransferLog.h"
class claTransactionsMenueOptions :protected clsScreen
{
private:
	enum enTransactionsMenue
	{
		enDeposit = 1, enWithdraw = 2,
		enTotalBalances = 3, eTransfer=4,eTransferLog=5,enMinMenue = 6
	};
	static short _ReadTransactionsMenue()
	{
		cout << setw(37) << left << " " << "Choose What do you want to do ?;[1,6]";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6);
		return Choice;
	}
	static void _ShowDeosit()
	{
		
		/*cout << "\t Deposit  Screen  willbe here";
		cout << "\n-------------------------------------------------\n";*/
		clsDepositScreen::ShowDepositScreen();
		

	}
static	void _ShowWithdraw()
	{
	/*	cout << "\n-------------------------------------------------\n";
		cout << "\t Withdraw Screen will be here ";
		cout << "\n-------------------------------------------------\n";*/
	  clsWithdrawScreen::ShoeWithdrawScreen();

		
	}
static void  _ShowTotalBalances()
{
	/*cout << "\n-------------------------------------------------\n";
	cout << "\t Total Balances  Screen will be here";
	cout << "\n-------------------------------------------------\n"*/;//
	clsTotalBalancesScreen::ShowTotalBalances();
	
}
static void  _ShowTransferScreen()
{
	/*cout << "\n-------------------------------------------------\n";
	cout << "\tTransferScreen  Screen will be here";
	cout << "\n-------------------------------------------------\n"*/;//
	clsTransfer::ShowTransferScreen();

}
static void  _ShowTransferlogScreen()
{
	/*cout << "\n-------------------------------------------------\n";
	cout << "\tTransferScreen log Screen will be here";
	cout << "\n-------------------------------------------------\n"*/;//
	TransferLog::ShowLoginRegister();

}

static void _GoBackToTransactionsMenue()
{
	cout << "\n\nPress any key to go back to Transactions Menu....\n\n";
	system("pause>0");
	ShowTransactionsMenue();
 }
static void _PerformTransactionsMenueOptions(enTransactionsMenue Tr)
{

	switch (Tr)
	{
	  case enTransactionsMenue::enDeposit:
		system("cls");
		_ShowDeosit();

		_GoBackToTransactionsMenue();
		break;
	   case enTransactionsMenue::enWithdraw:
		system("cls");
		_ShowWithdraw();

		_GoBackToTransactionsMenue();
		break;
	   case enTransactionsMenue::enTotalBalances:
		system("cls");

		_ShowTotalBalances();

		_GoBackToTransactionsMenue();
		break;
	   case enTransactionsMenue::eTransfer:
		system("cls");

		_ShowTransferScreen();

		_GoBackToTransactionsMenue();
	   case enTransactionsMenue::eTransferLog:
		system("cls");

		_ShowTransferlogScreen();

		_GoBackToTransactionsMenue();

	}
	

}
public :
	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::eTransactions))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t\tTransaction Screen");
		cout << setw(37) << left << "" << "===========================================\n";

		cout << setw(37) << left << "" << "\t\t\tTransaction Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] TotalBalance.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] TransferLog.\n";
		cout << setw(37) << left << "" << "\t[6]Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformTransactionsMenueOptions((enTransactionsMenue)_ReadTransactionsMenue());
	}

};

