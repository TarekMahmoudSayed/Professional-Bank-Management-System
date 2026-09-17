#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"

class clsFindClientScreen : protected clsScreen{

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

public :

	static void ShowFindClientScreen() {

		if (!clsScreen::_CheckAccessRights(clsUser::enPermissions::pFindClient)) {
			return;
		}

		clsScreen::_DrawScreenHeader("Find Client Screen ");

		string AccountNumber = "";

		cout << "Please enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::isClientExist(AccountNumber)) {

			cout << "Account Number is not found , choose another one : ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.isEmpty()) {
			cout << "\n\nClient Found :-) " << endl;
		}
		else {
			cout << "\n\nClient Was not Found !" << endl;
		}

		_PrintClient(Client);
	}


};

