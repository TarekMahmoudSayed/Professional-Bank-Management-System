#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
using namespace std;

class clsDeleteUserScreen : protected clsScreen{

	static void _PrintUser(clsUser& User) {

		cout << "\n\User Card :" << endl;
		cout << "----------------------------------" << endl;
		cout << "FirstName      : " << User.getFirstName() << endl;
		cout << "LastName       : " << User.getLastName() << endl;
		cout << "FullName       : " << User.getFullName() << endl;
		cout << "Phone          : " << User.getPhone() << endl;
		cout << "Email          : " << User.getEmail() << endl;
		cout << "UserName       : " << User.getUserName() << endl;
		cout << "Password       : " << User.getPassword() << endl;
		cout << "Permissions    : " << User.getPermissions() << endl;
		cout << "----------------------------------" << endl;

	}

public :

	static void ShowDeleteUser() {

		clsScreen::_DrawScreenHeader("Delete User Screen");

		string UserName = "";

		cout << "\n\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::isUserExist(UserName)) {

			cout << "\nUserName is not found, enter another one : ";
			UserName = clsInputValidate::ReadString();

		}

		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);

		char c = 'n';

		cout << "\nAre you sure you want to delete this User (y/n) ? ";
		cin >> c;

		if (tolower(c) == 'y') {
			if (User.Delete()) {
				cout << "\n\nUser Deleted Successfully " << endl;
				_PrintUser(User);
			}
			else {
				cout << "\n\nError , User was not delete " << endl;
			}
		}
	}

};

