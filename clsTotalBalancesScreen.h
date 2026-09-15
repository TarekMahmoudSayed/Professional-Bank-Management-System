#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"
#include <vector>

#include <iomanip>

using namespace std;

class clsTotalBalancesScreen : protected clsScreen {

	static void _PrintClientRecordBalanceLine(clsBankClient Client) {

		cout << setw(25) << left << "" << "| " << left << setw(15) << Client.getAccountNumber();
		cout << "| " << left << setw(40) << Client.getFullName();
		cout << "| " << left << setw(12) << Client.getAccountBalance();

	}


public :

	static void ShowTotalBalancesScreen() {

		vector <clsBankClient> _vBankClients= clsBankClient::GetClientsList();

		string Title = "Total Balances Screen";
		string subTitle = "(" + to_string(_vBankClients.size()) + ") Client(s).";

		clsScreen::_DrawScreenHeader(Title, subTitle);

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		if (!_vBankClients.size()) {
			cout << "\t\t\tNo Clients Available In the System! " << endl;
		}
		else {

			for (auto& c : _vBankClients) {
				_PrintClientRecordBalanceLine(c);
				cout << endl;
			}

		}

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		double TotalBalances = clsBankClient::GetTotalBalances();
		cout << "\t\t\tTotal Balances = " << TotalBalances << " ( " << clsUtil::NumberToText(TotalBalances) << ")" << endl;


	}



};



