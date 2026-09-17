#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogsScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen{

private :

	enum enTransactionMenueOptions {eDeposit = 1, eWithdraw = 2, eTotalBalances = 3,eTransfer = 4, eTransferLogs = 5,  eMainMenue = 6};

	static short _ReadTransactionMenueOption() {

		short Choise;
		cout << setw(37) << " " << "Choode what do you want to do ? [1 to 6] ? ";
		Choise = clsInputValidate::ReadShortNumberBetween(1, 6);

		return Choise;

	}

	static void _ShowDepositScreen() {
		//cout << "Deposit Screen Will Be Here " << endl;
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen() {
		//cout << "Withdraw Screen Will Be Here " << endl;
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen() {
		//cout << "Total Balances Screen Will Be Here "( << endl;
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen() {
		//cout << "Transfer Screen will be here " << endl;
		clsTransferScreen::ShowTransferScreen();

	}

	static void _ShowTransferLogsScreen() {
		cout << "Transfer Logs Screen will be here " << endl;
		clsTransferLogsScreen::ShowTransferLogs();
			 
	}

	static void _GoBackToTransactionMenueScreen() {
		cin.ignore();
		cout << "\n\t\t\t\tPress any key to go back to Transactions menue ";
		cin.get();
		system("cls");
		clsUtil::_Loading("Going Back To Transactions Menue Screen");
		system("cls");
		ShowTransactionMenueScreen();
	}


	static void _PerformTransactionMenueOption(short Choise) {

		switch ((enTransactionMenueOptions)Choise) {

		case enTransactionMenueOptions::eDeposit :

			system("cls");

			clsUtil::_Loading("Deposit Screen Loading");

			system("cls");

			_ShowDepositScreen();

			_GoBackToTransactionMenueScreen();
			
			break;

		case enTransactionMenueOptions::eWithdraw :

			system("cls");

			clsUtil::_Loading("Withdraw Screen Loading");

			system("cls");

			_ShowWithdrawScreen();

			_GoBackToTransactionMenueScreen();
			
			break;
		case enTransactionMenueOptions::eTotalBalances :

			system("cls");

			clsUtil::_Loading("Total Balances Screen Loading");

			system("cls");

			_ShowTotalBalancesScreen();

			_GoBackToTransactionMenueScreen();
			
			break;
		case enTransactionMenueOptions::eTransfer :

			system("cls");

			clsUtil::_Loading("Transfer Screen Loading");

			system("cls");

			_ShowTransferScreen();

			_GoBackToTransactionMenueScreen();
			
			break;
		case enTransactionMenueOptions::eTransferLogs :

			system("cls");

			clsUtil::_Loading("Transfer Logs Screen Loading");

			system("cls");

			_ShowTransferLogsScreen();

			_GoBackToTransactionMenueScreen();
			
			break;

		case enTransactionMenueOptions::eMainMenue:

			break;

		}

	}
	

public :

	static void ShowTransactionMenueScreen() {

		if (!clsScreen::_CheckAccessRights(clsUser::enPermissions::pTransaction)) {
			return;
		}

		clsScreen::_DrawScreenHeader("Transactions Screen");

		cout << setw(37) << " " << "=========================================== " << endl;
		cout << setw(37) << " " << "\t\t   Transactions Menue " << endl;
		cout << setw(37) << " " << "=========================================== " << endl;
		cout << setw(37) << " " << "\t[1] Deposit. " << endl;
		cout << setw(37) << " " << "\t[2] Withdraw. " << endl;
		cout << setw(37) << " " << "\t[3] Total Balances. " << endl;
		cout << setw(37) << " " << "\t[4] Transfer. " << endl;
		cout << setw(37) << " " << "\t[5] Transfer Logs. " << endl;
		cout << setw(37) << " " << "\t[6] Main Menue. " << endl;
		cout << setw(37) << " " << "=========================================== " << endl;


		_PerformTransactionMenueOption(_ReadTransactionMenueOption());

	}


};

