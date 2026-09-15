#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUtil.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen {

private:

	enum enMainMenueOptions {eShowClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4,
							eFindClient = 5, eTransactions = 6, eManageUsers = 7, eLogout = 8};

	static short _ReadMainMenueOption() {

		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 8]? ";

		short choise = clsInputValidate::ReadShortNumberBetween(1, 8);

		return choise;

	}

	static void _ShowAllClientsScreen() {
		//cout << "All Clients Screen Will Be Here " << endl;
		clsClientListScreen::ShowClientList();
	}

	static void _ShowAddNewClientScreen() {
		//cout << "Add New Client Screen Will Be Here " << endl;
		clsAddNewClientScreen::AddNewClient();
	}

	static void _ShowDeleteClientScreen() {
		//cout << "Delete Client Screen Will Be Here " << endl;
		clsDeleteClientScreen::DeleteClient();
	}

	static void _ShowUpdateClientScreen() {
		//cout << "Update Client Screen Will Be Here " << endl;
		clsUpdateClientScreen::UpdateClient();
	}

	static void _ShowFindClientScreen() {
		//cout << "Find Client Screen Will Be Here " << endl;

		clsFindClientScreen::ShowFindClientScreen();

	}

	static void _ShowTransactionsScreen() {
		//cout << "Transactions Screen Will Be Here " << endl;

		clsTransactionsScreen::ShowTransactionMenueScreen();

	}

	static void _ShowManageUsersScreen() {
		//cout << "Manage Users Screen Will Be Here " << endl;

		clsManageUsersScreen::ShowManageUsersMenueScreen();
	}

	static void _ShowLogoutScreen() {
		//cout << "Logout Screen Will Be Here " << endl;

		CurrentUser = clsUser::Find("", "");

	}

	static void _GoBackToMainMenueScreen() {
		cin.ignore();
		cout << "\n\t\t\t\t\tPress any key to go back to main menue ";
		cin.get();
		system("cls");
		clsUtil::_Loading("Going Back To Main Menue Screen");
		system("cls");
		ShowMainMenue();
	}

	static void _PerformMainMenueOptions(short Choice) {

		switch ((enMainMenueOptions)Choice) {

		case enMainMenueOptions::eAddNewClient :

			system("cls");
			
			clsUtil::_Loading("Add New Client Screen Loading");

			system("cls");

			_ShowAddNewClientScreen();

			_GoBackToMainMenueScreen();

			break;
		case enMainMenueOptions::eDeleteClient :

			system("cls");
			
			clsUtil::_Loading("Delete Client Screen Loading");

			system("cls");

			_ShowDeleteClientScreen();

			_GoBackToMainMenueScreen();
			break;
		case enMainMenueOptions::eUpdateClient :

			system("cls");
			
			clsUtil::_Loading("Update Client Screen Loading");

			system("cls");

			_ShowUpdateClientScreen();

			_GoBackToMainMenueScreen();
			break;
		case enMainMenueOptions::eShowClients :

			system("cls");
			
			clsUtil::_Loading("Show Clients Screen Loading");

			system("cls");

			_ShowAllClientsScreen();

			_GoBackToMainMenueScreen();
			break;
		case enMainMenueOptions::eFindClient :

			system("cls");
			
			clsUtil::_Loading("Find Client Screen Loading");

			system("cls");

			_ShowFindClientScreen();

			_GoBackToMainMenueScreen();
			break;
		case enMainMenueOptions::eTransactions :

			system("cls");
			
			clsUtil::_Loading("Transactions Screen Loading");

			system("cls");

			_ShowTransactionsScreen();

			_GoBackToMainMenueScreen();
			break;
		case enMainMenueOptions::eManageUsers :

			system("cls");
			
			clsUtil::_Loading("Manage Users Screen Loading");

			system("cls");

			_ShowManageUsersScreen();

			_GoBackToMainMenueScreen();
			break;
		case enMainMenueOptions::eLogout :

			system("cls");
			
			clsUtil::_Loading("Logout Loading");

			system("cls");

			_ShowLogoutScreen();

			break;

		}

	}


public :

	static void ShowMainMenue() {

		clsScreen::_DrawScreenHeader("Main Screen");

		cout << setw(37) << " " <<  "=========================================== " << endl;
		cout << setw(37) << " " << "\t\t   Main Menue " << endl;
		cout << setw(37) << " " << "=========================================== " << endl;
		cout << setw(37) << " " << "\t[1] Show Client List. " << endl;
		cout << setw(37) << " " << "\t[2] Add New Client. " << endl;
		cout << setw(37) << " " << "\t[3] Delete Client. " << endl;
		cout << setw(37) << " " << "\t[4] Update Client. " << endl;
		cout << setw(37) << " " << "\t[5] Find Client. " << endl;
		cout << setw(37) << " " << "\t[6] Transactions. " << endl;
		cout << setw(37) << " " << "\t[7] Manage Users. " << endl;
		cout << setw(37) << " " << "\t[8] Logout. " << endl;
		cout << setw(37) << " " << "=========================================== " << endl;

		_PerformMainMenueOptions(_ReadMainMenueOption());

	}

};

