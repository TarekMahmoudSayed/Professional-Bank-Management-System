#pragma once
#include <iostream>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

using namespace std;


class clsUpdateCurrencyScreen : protected clsScreen{

	static string _ReadCurrencyCode() {

		string CurrencyCode;

		cout << "\nPlease Enter Currency Code ? ";
		CurrencyCode = clsInputValidate::ReadString();

		return (CurrencyCode);
	}

	static clsCurrency _FindByCode() {

		return clsCurrency::FindByCode(_ReadCurrencyCode());

	}

	static void _PrintCurrencyCard(clsCurrency Currency) {

		cout << "\nCurrency Card : " << endl;
		cout << "---------------------------" << endl;
		cout << "Country : " << Currency.Country() << endl;
		cout << "Code    : " << Currency.CurrencyCode() << endl;
		cout << "Name    : " << Currency.CurrencyName() << endl;
		cout << "Rate    : " << Currency.Rate() << endl;
		cout << "---------------------------" << endl;

	}

	static double _ReadNewRate() {

		double rate = 0;
		cout << "\nEnter New Rate: ";
		rate = clsInputValidate::ReadDblNumber();

		return rate;

	}

	static bool _UpdateCurreny(clsCurrency& Currency) {

		Currency.UpdateRate(_ReadNewRate());

		return true;

	}

public :

	static void ShowUpdateCurrency() {

		clsScreen::_DrawScreenHeader("Update Currency Screen");

		clsCurrency Currency = _FindByCode();

		while (Currency.IsEmpty()) {
			cout << "\nCurrency Not Found :-(" << endl;
			Currency = _FindByCode();

		}

		_PrintCurrencyCard(Currency);

		char ans = 'n';

		cout << "\nAre you sure you want to update the rate of this currency [y/n]? ";
		cin >> ans;

		if (tolower(ans) == 'y') {

			cout << "\nUpdate Currency Rate: " << endl;
			cout << "-----------------------------" << endl;

			if (_UpdateCurreny(Currency)) {
				cout << "\nCurrency Rate Updated Successfully :-)" << endl;
				_PrintCurrencyCard(Currency);
			}
			else {
				cout << "\nError, Try Again " << endl;
			}

		}
		else {

			cout << "\nUpdate Currency was Cancelled " << endl;

		}

	}

};

