#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen{

	static clsBankClient _GetSourceClientTransferFrom() {

		string AccountNumber;


		cout << "\nPlease Enter Account Number To Transfer From : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::isClientExist(AccountNumber)) {

			cout << "\nAccount Not Found , Please Enter Another One To Transfer From : ";
			AccountNumber = clsInputValidate::ReadString();

		}

		return clsBankClient::Find(AccountNumber);


	}

	static clsBankClient _GetDestinationClientTransferTo() {

		string AccountNumber;


		cout << "\nPlease Enter Account Number To Transfer To : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::isClientExist(AccountNumber)) {

			cout << "\nAccount Not Found , Please Enter Another One To Transfer To : ";
			AccountNumber = clsInputValidate::ReadString();

		}

		return clsBankClient::Find(AccountNumber);


	}

	static void PrintCard(clsBankClient Client) {

		cout << "\nClient Card :" << endl;
		cout << "----------------------------------" << endl;
		cout << "FullName       : " << Client.getFullName() << endl;
		cout << "AccountNumber  : " << Client.getAccountNumber() << endl;
		cout << "AccountBalance : " << Client.getAccountBalance() << endl;
		cout << "----------------------------------" << endl;

	}

	static double _ReadAmount(clsBankClient SourceClient) {

		double Amount = 0;

		cout << "\nPlease Enter Amount? ";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > SourceClient.getAccountBalance()) {
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ?";
			Amount = clsInputValidate::ReadDblNumber();

		}

		while (Amount <= 0) {

			cout << "\nError Invalid Amount, PLease Enter Another One :" << endl;
			Amount = clsInputValidate::ReadDblNumber();

		}

		return Amount;


	}


public :

	static void ShowTransferScreen() {

		clsScreen::_DrawScreenHeader("Transfer Screen");

		clsBankClient SourceClient = _GetSourceClientTransferFrom();

		PrintCard(SourceClient);

		clsBankClient DestinationClient = _GetDestinationClientTransferTo();

		PrintCard(DestinationClient);

		double Amount = _ReadAmount(SourceClient);

		char ans = 'n';

		cout << "\nAre you sure you want to perform this operation [y/n]? ";
		cin >> ans;

		if (tolower(ans) == 'y') {

			if (SourceClient.Transfer(Amount, DestinationClient)) {

				cout << "\nTransfer done successfully " << endl;
			
			}

		}

		PrintCard(SourceClient);

		PrintCard(DestinationClient);
		

	}

};

