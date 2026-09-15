#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsUtil.h"

using namespace std; 

class clsBankClient : public clsPerson {

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 , AddNewMode = 2};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _MarkForDelete = false;

	inline static vector <clsBankClient> _vAllClients;

	static clsBankClient _ConvertLineToClientObject(const string& Line, const string& Seperator = "#//#") {

		clsBankClient Client = getEmptyClientObject();

		vector <string> vClient = clsString::Split(Line, Seperator);

		if (vClient.size() < 7) {
			return getEmptyClientObject();
		}

		Client._Mode = enMode::UpdateMode;
		Client.setFirstName(vClient[0]);
		Client.setLastName(vClient[1]);
		Client.setEmail(vClient[2]);
		Client.setPhone(vClient[3]);
		Client._AccountNumber = vClient[4];
		Client._PinCode = vClient[5];

		try {
			Client._AccountBalance = stod(vClient[6]);
		}
		catch (...) {
			Client._AccountBalance = 0;
		}

		return Client;

	}

	static string _ConvertClientObjectToLine(clsBankClient Client, const string& Seperator = "#//#") {

		string Line = "";

		Line += Client.getFirstName() + Seperator;
		Line += Client.getLastName() + Seperator;
		Line += Client.getEmail() + Seperator;
		Line += Client.getPhone() + Seperator;
		Line += Client.getAccountNumber() + Seperator;
		Line += Client.getPinCode() + Seperator;
		Line += to_string(Client.getAccountBalance());

		return Line;



	}

	static clsBankClient getEmptyClientObject() {

		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);

	}

	static void _LoadClientsDateFromFile() {

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		string Line = "";

		if (MyFile.is_open()) {

			_vAllClients.clear();

			while (getline(MyFile, Line)) {

				clsBankClient Client = _ConvertLineToClientObject(Line);

				_vAllClients.push_back(Client);

			}

			MyFile.close();

		}

	}

	static void _SaveClientDateToFile(const vector <clsBankClient>& AllClinets) {

		fstream MyFile;

		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open()) {

			string Line = "";

			for (const auto& c : AllClinets) {
				if (!c._MarkForDelete) {
					Line = _ConvertClientObjectToLine(c);
					MyFile << Line << endl;
				}
					
			}

				

		}

		MyFile.close();


	}

	void _Update() {

		_LoadClientsDateFromFile();

		for (auto & c : _vAllClients) {

			if (c.getAccountNumber() == getAccountNumber()) {
				c = *this;
				break;

			}

		}

		_SaveClientDateToFile(_vAllClients);

	}

	void _AddNew() {

		_AddDataLineToFile(_ConvertClientObjectToLine(*this));

	}

	void _AddDataLineToFile(const string& Line) {

		fstream MyFile;

		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open()) {

			MyFile << Line << endl;

		}

		MyFile.close();


	}


public :

	enum enSaveResult { svFaildEmptyObject = 0, svSucceeded = 1 , svFaildAccountNumberExist = 2};

	clsBankClient(enMode Mode, string FirstName, string LastName, string Phone , string Email, 
		string AccountNumber, string PinCode, double AccountBalance) : clsPerson (FirstName, LastName, Email, Phone) {

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;

	}

	string getAccountNumber() {
		return _AccountNumber;
	}

	void setPinCode(string PinCode) {
		_PinCode = PinCode;
	}

	string getPinCode() {
		return _PinCode;
	}

	void setAccountBalance(double AccountBalance) {
		_AccountBalance = AccountBalance;
	}

	double getAccountBalance() {
		return _AccountBalance;
	}

	bool isEmpty() {
		return _Mode == enMode::EmptyMode;
	}

	//void Print() {

	//	cout << "\n\nClient Card :" << endl;
	//	cout << "----------------------------------" << endl;
	//	cout << "FirstName      : " << getFirstName() << endl;
	//	cout << "LastName       : " << getLastName() << endl;
	//	cout << "FullName       : " << getFullName() << endl;
	//	cout << "Phone          : " << getPhone() << endl;
	//	cout << "Email          : " << getEmail() << endl;
	//	cout << "AccountNumber  : " << _AccountNumber << endl;
	//	cout << "Password       : " << _PinCode << endl;
	//	cout << "AccountBalance : " << _AccountBalance << endl;
	//	cout << "----------------------------------" << endl;


	//}

	static clsBankClient Find(string AccountNumber) {

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client._AccountNumber == AccountNumber) {
					MyFile.close();
					return Client;
				}

			}

		}

		MyFile.close();

		return getEmptyClientObject();


	}

	static clsBankClient Find(string AccountNumber, string PinCode) {

		fstream MyFile;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) {

			string Line;

			while (getline(MyFile, Line)) {

				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client._AccountNumber == AccountNumber && Client._PinCode == PinCode) {
					MyFile.close();
					return Client;
				}

			}

		}

		MyFile.close();

		return getEmptyClientObject();


	}
	
	static bool isClientExist(string AccountNumber) {

		clsBankClient Client = Find(AccountNumber);

		return (!Client.isEmpty());
		
	}

	enSaveResult Save() {

		switch (_Mode) {
		case enMode::EmptyMode :
			return enSaveResult::svFaildEmptyObject;

		case enMode::UpdateMode :
			_Update();
			return enSaveResult::svSucceeded;

		case enMode::AddNewMode :
			if (isClientExist(_AccountNumber)) {
				return enSaveResult::svFaildAccountNumberExist;
			}
			else {
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}

		}


	}

	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete() {

		_LoadClientsDateFromFile();

		for (auto& c : _vAllClients) {

			if (c.getAccountNumber() == _AccountNumber) {
				c._MarkForDelete = true;
				break;
			}

		}

		_SaveClientDateToFile(_vAllClients);

		*this = getEmptyClientObject();

		return true;

	}

	static vector <clsBankClient> GetClientsList() {

		_LoadClientsDateFromFile();

		return _vAllClients;

	}

	static double GetTotalBalances() {

		_LoadClientsDateFromFile();

		double TotalBalances = 0.00;

		for (auto& c : _vAllClients) {
			TotalBalances += c.getAccountBalance();
		}

		return TotalBalances;

	}

	void Deposit(double Amount) {

		_AccountBalance += Amount;
		Save();

	}

	bool Withdraw(double Amount) {

		if (Amount > _AccountBalance) {
			return false;
		}
		else {
			_AccountBalance -= Amount;
			Save();
			return true;
		}

	
	}


};