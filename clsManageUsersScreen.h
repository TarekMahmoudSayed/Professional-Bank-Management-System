#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUser.h"
#include "clsUtil.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;


class clsManageUsersScreen : protected clsScreen{

	enum enMangeUsersMenueOptions {
		ListUsers = 1, AddNewUser = 2, DeleteUser = 3,
		UpdateUser = 4, FindUser = 5, MainMenue = 6
	};


	static short _ReadManageUsersMenueOption() {

		cout << setw(37) << left << "" << "Choose what do you want to do [1 to 6] ? ";
		short choice = clsInputValidate::ReadShortNumberBetween(1, 6);

		return choice;

	}

	static void  _ShowListUsersScreen() {
		//cout << "List User Screen Will Be Here " << endl;
		clsListUsersScreen::ShowUsersList();
	}

	static void  _ShowAddNewUserScreen() {
		//cout << "Add New User Screen Will Be Here " << endl;
		clsAddNewUserScreen::ShowAddNewUser();

	}

	static void  _ShowDeleteUserScreen() {
		//cout << "Delete User Screen Will Be Here " << endl;
		clsDeleteUserScreen::ShowDeleteUser();
	}

	static void  _ShowUpdateUserScreen() {
		//cout << "Update User Screen Will Be Here " << endl;
		clsUpdateUserScreen::ShowUpdateUser();
	}

	static void  _ShowFindUserScreen() {
		//cout << "Find User Screen Will Be Here " << endl;
		clsFindUserScreen::ShowFindUser();
	}

	static void _GoBackToManageUsersMenueScreen() {
		cin.ignore();
		cout << "\n\t\t\t\tPress any key to go back to Manage Users menue ";
		cin.get();
		system("cls");
		clsUtil::_Loading("Going Back To Manage Users Menue Screen");
		system("cls");
		ShowManageUsersMenueScreen();
	}


	static void _PerformManageUsersMenueOptions(short choise) {

		switch (enMangeUsersMenueOptions(choise)) {

		case enMangeUsersMenueOptions::AddNewUser :
			system("cls");
			clsUtil::_Loading("Add New User Screen Loading");
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenueScreen();
			break;
		case enMangeUsersMenueOptions::ListUsers :
			system("cls");
			clsUtil::_Loading("List Users Screen Loading");
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenueScreen();
			break;
		case enMangeUsersMenueOptions::UpdateUser :
			system("cls");
			clsUtil::_Loading("Update User Screen Loading");
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenueScreen();
			break;
		case enMangeUsersMenueOptions::DeleteUser :
			system("cls");
			clsUtil::_Loading("Delete User Screen Loading");
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenueScreen();
			break;
		case enMangeUsersMenueOptions::FindUser :
			system("cls");
			clsUtil::_Loading("Find User Screen Loading");
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenueScreen();
			break;
		case enMangeUsersMenueOptions::MainMenue :
			break;
		}

	}



public :

	static void ShowManageUsersMenueScreen() {

		if (!clsScreen::CheckAccessRights(clsUser::enPermissions::pManageUsers)) {
			return;
		}

		clsScreen::_DrawScreenHeader("Manage Users Screen");

		cout << setw(37) << " " << "=========================================== " << endl;
		cout << setw(37) << " " << "\t\t   Manage Users Menue " << endl;
		cout << setw(37) << " " << "=========================================== " << endl;
		cout << setw(37) << " " << "\t[1] List Users. " << endl;
		cout << setw(37) << " " << "\t[2] Add New User. " << endl;
		cout << setw(37) << " " << "\t[3] Delete User. " << endl;
		cout << setw(37) << " " << "\t[4] Update User. " << endl;
		cout << setw(37) << " " << "\t[5] Find User. " << endl;
		cout << setw(37) << " " << "\t[6] Main Menue. " << endl;
		cout << setw(37) << " " << "=========================================== " << endl;

		_PerformManageUsersMenueOptions(_ReadManageUsersMenueOption());


	}


};

