#pragma once

#include <iostream>
#include "clsDate.h"
#include "Global.h"

using namespace std;

class clsScreen{

protected :

	static void _DrawScreenHeader(string Title, string SubTitle = "") {

		cout << "\t\t\t\t\t______________________________________";		
		cout << "\n\n\t\t\t\t\t\t   " << Title << endl;

		if (SubTitle != "") {
			cout << "\t\t\t\t\t\t     " << SubTitle << endl;
		}

		cout << "\t\t\t\t\t______________________________________" << endl;

		_AddDateAndCurrentLoginUser();

	}

	static void _AddDateAndCurrentLoginUser() {

		cout << "\n\t\t\t\t\tUser: " << CurrentUser.getUserName() << endl;
		cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate::GetSystemDate()) <<endl<< endl;

	}

	static bool _CheckAccessRights(clsUser::enPermissions Permission) {

		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			return false;
		}
		else
		{
			return true;
		}

	}

};

