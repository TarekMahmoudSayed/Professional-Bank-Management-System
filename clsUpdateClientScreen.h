#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen{

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

	static void _ReadClientInfo(clsBankClient& Client) {

		cout << "\nEnter FirstName : ";
		Client.setFirstName(clsInputValidate::ReadString());
		cout << "\nEnter LastName : ";
		Client.setLastName(clsInputValidate::ReadString());
		cout << "\nEnter Phone : ";
		Client.setPhone(clsInputValidate::ReadString());
		cout << "\nEnter Email : ";
		Client.setEmail(clsInputValidate::ReadString());
		cout << "\nEnter PinCode : ";
		Client.setPinCode(clsInputValidate::ReadString());
		cout << "\nEnter AccountBalance : ";
		Client.setAccountBalance(clsInputValidate::ReadDblNumber());
		cout << endl;

	}

public :

	static void UpdateClient() {

		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pUpdateClient)) {
			return;
		}

		clsScreen::_DrawScreenHeader("Update Client Screen");

		string AccountNumber = "";

		cout << "Please Enter Client Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::isClientExist(AccountNumber)) {

			cout << "Account Number is not Found, Choose another one : ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		cout << "\n\nUpdate Clinet Info : " << endl;
		cout << "----------------------" << endl;

		_ReadClientInfo(Client);

		clsBankClient::enSaveResult SaveResult = Client.Save();

		switch (SaveResult) {
		case clsBankClient::enSaveResult::svFaildEmptyObject:
			cout << "Error account was not saved because it's empty " << endl;
			break;
		case clsBankClient::enSaveResult::svSucceeded:
			cout << "Account Updated Successfully :-) " << endl;
			_PrintClient(Client);
			break;

		}


	}



};

