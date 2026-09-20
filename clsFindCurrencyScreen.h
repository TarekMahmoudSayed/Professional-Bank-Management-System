#pragma once

#include <iostream>

#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen {

	enum enFindBy {eFindByCode = 1, eFindByCountry = 2};

	static short _ReadFindBy() {

		short Choice;

		cout << "\nFind By: [1] Code or [2] Country ? ";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 2);

		return Choice;

	}

	static string _ReadCurrencyCode() {

		string CurrencyCode;

		cout << "\nPlease Enter Currency Code ? ";
		CurrencyCode = clsInputValidate::ReadString();

		return (CurrencyCode);
	}

	static clsCurrency _FindByCode() {

		return clsCurrency::FindByCode(_ReadCurrencyCode());

	}

	static string _ReadCurrencyCountry() {

		string Country;

		cout << "\nPlease Enter Country ? ";
		Country = clsInputValidate::ReadString();

		return (Country);
	}

	static clsCurrency _FindByCountry() {

		return (clsCurrency::FindByCountry(_ReadCurrencyCountry()));

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

	static void _ShowResults (clsCurrency Currency) {

		if (!Currency.IsEmpty()) {
			cout << "\nCurrency Found :-) " << endl;
			_PrintCurrencyCard(Currency);
		}
		else {
			cout << "\nCurreny Not Found :-(" << endl;
		}

	}

public :

	static void ShowFindCurrency() {

		clsScreen::_DrawScreenHeader("Find Currency Screen");

		clsCurrency Currency = clsCurrency::GetEmptyCurrencyObject();

		switch (enFindBy(_ReadFindBy())) {

		case enFindBy::eFindByCode:

			Currency = _FindByCode();

			break;

			
		case enFindBy::eFindByCountry:

			Currency = _FindByCountry();
			
			break;

		}

		
		_ShowResults(Currency);
		

	}


};

