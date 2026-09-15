#pragma once

#include <iostream>

#include "clsUser.h"
#include "clsScreen.h"

#include <iomanip>

using namespace std;

class clsListUsersScreen : protected clsScreen {

private:

	static void _PrintUserRecordLine(clsUser User) {

		cout << "\t" << "| " << left << setw(9) << User.getUserName();
		cout  << "| " << left << setw(25) << User.getFullName();
		cout  << "| " << left << setw(14) << User.getPhone();
		cout  << "| " << left << setw(20) << User.getEmail();
		cout  << "| " << left << setw(10) << User.getPassword();
		cout  << "| " << left << setw(6) << User.getPermissions();

	}

public:

	static void ShowUsersList() {

		const vector <clsUser> vUsers = clsUser::GetUsersList();

		string Title = "Users List Screen ";
		string subTitle = "(" + to_string(vUsers.size()) + ") User(s). ";

		clsScreen::_DrawScreenHeader(Title, subTitle);

		cout << "\n\n\t--------------------------------------------------------------------------------------------------------" << endl;

		cout << "\t" << "| " << left << setw(9) << "UserName";
		cout  << "| " << left << setw(25) << "Full Name";
		cout  << "| " << left << setw(14) << "Phone";
		cout  << "| " << left << setw(20) << "Email";
		cout  << "| " << left << setw(10) << "Password";
		cout  << "| " << left << setw(6) << "Permissions" << endl;

		cout << "\t--------------------------------------------------------------------------------------------------------" << endl;

		if (vUsers.empty()) {
			cout << "\t\t\tNo Users Available In the System! " << endl;
		}
		else {

			for (auto& u : vUsers) {
				_PrintUserRecordLine(u);
				cout << endl;
			}

		}

		cout << "\t--------------------------------------------------------------------------------------------------------" << endl;


	}

};

