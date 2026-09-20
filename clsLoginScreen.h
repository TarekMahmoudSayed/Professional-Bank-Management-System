#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen{

	static bool _Login() {

		short Trials = 3;
		bool LoginFaild = false;

		do {

			if (Trials && LoginFaild) {
				cout << "\nInvalid UserName/Password " << endl;
				cout << "You Have " << Trials << " Trials To Login. " << endl;
			}

			cout << "\nEnter UserName? ";
			string UserName = clsInputValidate::ReadString();
			cout << "\nEnter Password? ";
			string Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);
			LoginFaild = CurrentUser.IsEmpty();


		} while (LoginFaild && --Trials);

		if (Trials) {
			return true;
		}

		return false;


	}


public :

	static bool ShowLoginScreen() {

		clsScreen::_DrawScreenHeader("Login Screen");

		if (_Login()) {

			CurrentUser.RegisterLogIn();

			system("cls");

			clsUtil::_Loading("Login Successed Loading");

			system("cls");

			clsMainScreen::ShowMainMenue();
			return true;
		}
		else {

			cout << "\n\nYou Are Locked after 3 faild trials. " << endl;

			return false;
		}
	}

};

