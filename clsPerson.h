#pragma once

#include <iostream>

using namespace std;

class clsPerson{

	string _FirstName;
	string _LastName;
	string _Phone;
	string _Email;

public :

	clsPerson(string FirstName, string LastName, string Email, string Phone) {
		_FirstName = FirstName;
		_LastName = LastName;
		_Phone = Phone;
		_Email = Email;
	}

	clsPerson() {
		_FirstName = "";
		_LastName = "";
		_Phone = "";
		_Email = "";

	}

	void setFirstName(string FirstName) {
		_FirstName = FirstName;
	}

	string getFirstName() {
		return _FirstName;
	}

	void setLastName(string LastName) {
		_LastName = LastName;
	}

	string getLastName() {
		return _LastName;
	}

	void setPhone(string Phone) {
		_Phone = Phone;
	}

	string getPhone() {
		return _Phone;
	}

	void setEmail(string Email) {
		_Email = Email;
	}

	string getEmail() {
		return _Email;
	}

	string getFullName() {
		return _FirstName + " " + _LastName;
	}

};

