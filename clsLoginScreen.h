#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen{

	static bool _Login() {

		bool LoginFaild = false;

		do {

			if (LoginFaild) {
				cout << "\nInvalid UserName/Password " << endl;
			}

			cout << "\nEnter UserName? ";
			string UserName = clsInputValidate::ReadString();
			cout << "\nEnter Password? ";
			string Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.isEmpty();

		} while (LoginFaild);

		return true;

	}


public :

	static void ShowLoginScreen() {

		clsScreen::_DrawScreenHeader("Login Screen");

		if (_Login()) {
			system("cls");

			clsUtil::_Loading("Login Successed Loading");

			system("cls");

			clsMainScreen::ShowMainMenue();
		}
	}

};

