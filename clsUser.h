#pragma once

#include <iostream>
#include <fstream>
#include "clsPerson.h"
#include "clsUtil.h"
#include "clsString.h"

class clsUser : public clsPerson{

private :

	enum enMode {EmptyMode = 0, AddNewMode = 1, UpdateMode = 2};
	enMode _Mode;

	string _UserName;
	string _Password;

	int _Permissions;

	bool _MarkForDelete = false;

	inline static vector <clsUser> _vAllUsers;

	static clsUser _ConvertLineToUserObject(const string& Line, const string& Seperator = "#//#") {

		clsUser User = GetEmptyUserObject();

		vector <string> vUserData = clsString::Split(Line, Seperator);

		if (vUserData.size() < 7) {
			return GetEmptyUserObject();
		}

		User._Mode = enMode::UpdateMode;
		User.setFirstName(vUserData[0]);
		User.setLastName(vUserData[1]);
		User.setEmail(vUserData[2]);
		User.setPhone(vUserData[3]);
		User._UserName = vUserData[4];
		User._Password = vUserData[5];

		try {
			User._Permissions = stoi(vUserData[6]);
		}
		catch (...) {
			User._Permissions = 0;
		}

		return User;

	}

	static string _ConvertUserObjectToLine(clsUser& User, const string& Seperator = "#//#") {

		string Line = "";

		Line += User.getFirstName() + Seperator;
		Line += User.getLastName() + Seperator;
		Line += User.getEmail() + Seperator;
		Line += User.getPhone() + Seperator;
		Line += User._UserName + Seperator;
		Line += User._Password + Seperator;
		Line += to_string(User._Permissions);

		return Line;

	}

	static clsUser GetEmptyUserObject () {
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static void _LoadUsersDataFromFile() {

		fstream MyFile;

		MyFile.open("Users.txt", ios::in);

		string Line;

		if (MyFile.is_open()) {

			_vAllUsers.clear();
			

			while (getline(MyFile, Line)) {

				clsUser User = _ConvertLineToUserObject(Line);

				_vAllUsers.push_back(User);

			}

			MyFile.close();

		}


	}

	static void _SaveUsersDataToFile(vector <clsUser>& vUsers) {

		fstream myfile;

		myfile.open("Users.txt", ios::out);

		if (myfile.is_open()) {
			string Line = "";
			for (auto& u : vUsers) {

				if (!u._MarkForDelete) {
					Line = _ConvertUserObjectToLine(u);
					myfile << Line << endl;
				}
			}

			myfile.close();

		}


	}

	void _AddNew() {

		_AddDateLineToFile(_ConvertUserObjectToLine(*this));


	}

	void _Update() {

		_LoadUsersDataFromFile();

		for (auto& u : _vAllUsers) {

			if (u.getUserName() == getUserName()) {
				u = *this;
				break;
			}

		}

		_SaveUsersDataToFile(_vAllUsers);

	}

	static void _AddDateLineToFile(string Line) {

		fstream MyFile;

		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << Line << endl;

			MyFile.close();

		}


	}

public :

	enum enPermissions {eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
						pUpdateClient = 8, pFindClient = 16, pTransaction = 32, pManageUsers = 64
	};

	enum enSaveResult { svFaildEmptyObject = 2, svSucceeded = 1, svFaildUserNameExist = 3 };

	clsUser(enMode Mode, string FirstName, string LastName, string Phone, string Email,
		string UserName, string Password, int Permissions) : clsPerson(FirstName, LastName, Email, Phone) {

		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;

	}

	void setUserName(string UserName) {
		_UserName = UserName;
	}

	string getUserName() {
		return _UserName;
	}

	void setPassword(string Password) {
		_Password = Password;
	}

	string getPassword() {
		return _Password;
	}

	void setPermissions(int Permissions) {
		_Permissions = Permissions;
	}

	int getPermissions() {
		return _Permissions;
	}

	bool isEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	static clsUser Find(string UserName) {

		_LoadUsersDataFromFile();

		for (auto& u : _vAllUsers) {

			if (u._UserName == UserName) {
				return u;
			}

		}

		return GetEmptyUserObject();

	}

	static clsUser Find(string UserName, string Password) {

		_LoadUsersDataFromFile();

		for (auto& u : _vAllUsers) {

			if (u._UserName == UserName && u._Password == Password) {
				return u;
			}

		}

		return GetEmptyUserObject();

	}

	static bool isUserExist(string UserName) {
		clsUser User = Find(UserName);
		return !User.isEmpty();
	}

	static bool isUserExist(string UserName, string Password) {
		clsUser User = Find(UserName, Password);
		return !User.isEmpty();
	}

	static clsUser GetAddNewUserObject(string UserName) {
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete() {

		_LoadUsersDataFromFile();


		for (auto& u : _vAllUsers) {

			if (u.getUserName() == _UserName) {
				u._MarkForDelete = true;
				break;
			}

		}

		*this = GetEmptyUserObject();

		_SaveUsersDataToFile(_vAllUsers);

		return true;

	}

	static vector <clsUser> GetUsersList() {
		_LoadUsersDataFromFile();
		return _vAllUsers;
	}

	enSaveResult Save () {

		switch (_Mode) {

		case enMode::EmptyMode :

			return enSaveResult::svFaildEmptyObject;

		case enMode::UpdateMode :

			_Update();
			return enSaveResult::svSucceeded;

		case enMode::AddNewMode :

			if (!isUserExist(_UserName)) {
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
			else {
				return enSaveResult::svFaildUserNameExist;
			}

		}

	}

	bool CheckAccessPermission(enPermissions Permissions) {

		if (_Permissions == enPermissions::eAll) {
			return true;
		}

		if ((_Permissions & Permissions) == Permissions) {
			return true;
		}
		else {
			return false;
		}

	}


};

