#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"



using namespace std;

class clsUpdateUserScreen : protected clsScreen{

	static void _ReadUserInfo(clsUser& User) {

		cout << "\nEnter FirstName : ";
		User.setFirstName(clsInputValidate::ReadString());
		cout << "\nEnter LastName : ";
		User.setLastName(clsInputValidate::ReadString());
		cout << "\nEnter Phone : ";
		User.setPhone(clsInputValidate::ReadString());
		cout << "\nEnter Email : ";
		User.setEmail(clsInputValidate::ReadString());
		cout << "\nEnter Password : ";
		User.setPassword(clsInputValidate::ReadString());
		cout << "\nEnter Permissions : \n\n";

		User.setPermissions(_ReadPermissionsToSet());

	}

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

	static int _ReadPermissionsToSet() {

		char Ans = 'n';

		int Permissions = 0;

		cout << "Do you want to give full access [y/n]? ";
		cin >> Ans;

		if (tolower(Ans) == 'y') {
			return clsUser::enPermissions::eAll;
		}

		cout << "\nDo you want to give access to : " << endl;

		cout << "\nShow Clients List [y/n]? ";
		cin >> Ans;
		if (tolower(Ans) == 'y') {
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client [y/n]? ";
		cin >> Ans;
		if (tolower(Ans) == 'y') {
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client [y/n]? ";
		cin >> Ans;
		if (tolower(Ans) == 'y') {
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client [y/n]? ";
		cin >> Ans;
		if (tolower(Ans) == 'y') {
			Permissions += clsUser::enPermissions::pUpdateClient;
		}

		cout << "\nFind Client [y/n]? ";
		cin >> Ans;
		if (tolower(Ans) == 'y') {
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions [y/n]? ";
		cin >> Ans;
		if (tolower(Ans) == 'y') {
			Permissions += clsUser::enPermissions::pTransaction;
		}

		cout << "\nManage Users [y/n]? ";
		cin >> Ans;
		if (tolower(Ans) == 'y') {
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		return Permissions;

	}

public :

	static void ShowUpdateUser() {

		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient)) {
			return;
		}

		clsScreen::_DrawScreenHeader("Update User Screen");

		string UserName = "";

		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::isUserExist(UserName)) {
			cout << "\nUserName is not found, enter another one : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);

		char c = 'n';

		cout << "\nAre you sure you want to Update this User (y/n) ? ";
		cin >> c;

		if (tolower(c) == 'y') {

			cout << "\n\nUpdate User Info:";
			cout << "\n____________________\n";

			_ReadUserInfo(User);

			clsUser::enSaveResult SaveResult = User.Save();

			switch (SaveResult) {
			case clsUser::enSaveResult::svFaildEmptyObject:
				cout << "\nError User was not saved because it's empty " << endl;
				break;
			case clsUser::enSaveResult::svSucceeded:
				cout << "\nUser Updated Successfully :-) " << endl;
				_PrintUser(User);
				break;
		
			}
		}

		

	}


};

