#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsDeleteClientScreen : protected clsScreen {

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

public :

	static void DeleteClient() {

		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {
			return;
		}

		clsScreen::_DrawScreenHeader("Delete Client Screen");

		string AccountNumber = "";

		cout << "\n\nPlease Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::isClientExist(AccountNumber)) {

			cout << "Account Number is not found, enter another one : ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		char c = 'n';

		cout << "Are you sure you want to delete this client (y/n) ? ";
		cin >> c;

		if (tolower(c) == 'y') {
			if (Client.Delete()) {
				cout << "\n\nClient Deleted Successfully " << endl;
				_PrintClient(Client);
			}
			else {
				cout << "\n\nError , Client was not delete " << endl;
			}
		}


	}



};

