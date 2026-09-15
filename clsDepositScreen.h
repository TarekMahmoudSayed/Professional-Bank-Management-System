#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsDepositScreen : protected clsScreen{

private :

	static void _PrintClient(clsBankClient& Client) {

		cout << "\n\nClient Card :" << endl;
		cout << "----------------------------------" << endl;
		cout << "FirstName      : " << Client.getFirstName() << endl;
		cout << "LastName       : " << Client.getLastName() << endl;
		cout << "FullName       : " << Client.getFullName() << endl;
		cout << "Phone          : " << Client.getPhone() << endl;
		cout << "Email          : " << Client.getEmail() << endl;
		cout << "AccountNumber  : " << Client.getAccountNumber() << endl;
		cout << "Password       : " << Client.getPinCode() << endl;
		cout << "AccountBalance : " << Client.getAccountBalance() << endl;
		cout << "----------------------------------" << endl;

	}

	static string _ReadAccountNumber() {

		string AccountNumber;
		cout << "\nPlease enter AccountNumber ? " ;
		cin >> AccountNumber;

		return AccountNumber;

	}


public :

	static void ShowDepositScreen() {

		clsScreen::_DrawScreenHeader("Deposit Screen ");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::isClientExist(AccountNumber)) {

			cout << "\nClient With [" << AccountNumber << "] does not exist. " << endl;

			AccountNumber = _ReadAccountNumber();

		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		double Amount;
		cout << "\nPlease Enter Deposit Amount? ";
		Amount = clsInputValidate::ReadDblNumber();

		if (Amount <= 0) {
			cout << "\nInvlaid Amount, Please Try Again!" << endl;
			return;
		}

		char Ans = 'n';

		cout << "\nAre you sure you want to perform this tranaction [y/n]? ";
		cin >> Ans;

		if (tolower(Ans) == 'y') {
			Client.Deposit(Amount);
			cout << "\nAmount Deposited Successfully. " << endl;
			cout << "\nNew Balance Is: " << Client.getAccountBalance() << endl;
		}
		else {
			cout << "\nOperation Was Cancelled. " << endl;
		}



	}


};

