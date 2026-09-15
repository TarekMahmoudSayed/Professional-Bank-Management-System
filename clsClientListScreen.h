#pragma once

#include <iostream>

#include "clsBankClient.h"
#include "clsScreen.h"

#include <iomanip>

using namespace std;

class clsClientListScreen : protected clsScreen{

private:

	static void _PrintClientRecordLine(clsBankClient Client) {

		cout << "| " << left << setw(15) << Client.getAccountNumber();
		cout << "| " << left << setw(20) << Client.getFullName();
		cout << "| " << left << setw(12) << Client.getPhone();
		cout << "| " << left << setw(20) << Client.getEmail();
		cout << "| " << left << setw(10) << Client.getPinCode();
		cout << "| " << left << setw(12) << Client.getAccountBalance();

	}

public :

	static void ShowClientList() {

		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pListClients)) {
			return;
		}

		const vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "Client List Screen ";
		string subTitle = "(" + to_string(vClients.size()) + ") Client(s). ";

		clsScreen::_DrawScreenHeader(Title, subTitle);
		
		cout << "\n\n--------------------------------------------------------------------------------------------------------------" << endl;

		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "PinCode";
		cout << "| " << left << setw(12) << "Balance" << endl;

		cout << "--------------------------------------------------------------------------------------------------------------" << endl;

		if (vClients.empty()) {
			cout << "\t\t\tNo Clients Available In the System! " << endl;
		}
		else {

			for (auto& c : vClients) {
				_PrintClientRecordLine(c);
				cout << endl;
			}

		}


	}

};

