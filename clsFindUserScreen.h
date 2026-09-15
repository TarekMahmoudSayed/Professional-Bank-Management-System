#pragma once

#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindUserScreen : protected clsScreen {

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


	static void ShowFindUser() {

		clsScreen::_DrawScreenHeader("Find User Screen");

		string UserName = "";

		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::isUserExist(UserName)) {

			cout << "\nUser is not found, choose another one: ";
			UserName = clsInputValidate::ReadString();

		}

		clsUser User = clsUser::Find(UserName);

		if (!User.isEmpty()) {
			cout << "\nUser Found :-) " << endl;
		}
		else {
			cout << "\nUser was not found :-( " << endl;
		}

		_PrintUser(User);
		

	}




};

