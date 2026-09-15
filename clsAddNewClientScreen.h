#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen{

	static void ReadClientInfo(clsBankClient& Client) {

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

	static void PrintClient(clsBankClient& Client) {

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

	static void AddNewClient() {

		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pAddNewClient)) {
			return;
		}

		clsScreen::_DrawScreenHeader("Add New Client Screen");

		string AccountNumber = "";

		cout << "\n\nPlease Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::isClientExist(AccountNumber)) {

			cout << "Account Number is Already Used, Choose another one : ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		cout << "\n\Read New Clinet Info : " << endl;
		cout << "----------------------" << endl;

		ReadClientInfo(NewClient);

		clsBankClient::enSaveResult SaveResult = NewClient.Save();

		switch (SaveResult) {
		case clsBankClient::enSaveResult::svFaildEmptyObject:
			cout << "Error account was not saved because it's empty " << endl;
			break;
		case clsBankClient::enSaveResult::svSucceeded:
			cout << "Account Added Successfully :-) " << endl;
			PrintClient(NewClient);
			break;
		case clsBankClient::enSaveResult::svFaildAccountNumberExist:
			cout << "Error Account Number is Already Used";
			break;
		}


	}
};

