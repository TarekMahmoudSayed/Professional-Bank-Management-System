#pragma once
#include <iostream>

#include "clsCurrency.h"
#include "clsScreen.h"

using namespace std;

class clsCurrenciesListScreen : protected clsScreen{

	static void _PrintCurrencyRecordLine(clsCurrency Currency) {

		cout << setw(8) << left << "";
		cout << "| "  << setw(30) << left  << Currency.Country() << "";
		cout << "| "  << setw(10) << left  << Currency.CurrencyCode() << "";
		cout << "| "  << setw(45) << left  << Currency.CurrencyName() << "";
		cout << "| "  << setw(10) << left  << Currency.Rate() << "";

	}

public:

	static void ShowCurrenciesList() {

		vector < clsCurrency > vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "Currencies List Screen";
		string subTitle = "(" + to_string(vCurrencies.size()) + ") Currency.";

		clsScreen::_DrawScreenHeader(Title, subTitle);

		cout << "\n\n\t-----------------------------------------------------------------------------------";
		cout << "---------------------" << endl;

		cout << setw(8) << left << "";
		cout << "| " << setw(30) << left << "Country" ;
		cout << "| " << setw(10) << left << "Code" ;
		cout << "| " << setw(45) << left << "Name" ;
		cout << "| " << setw(10) << left << "Rate/(1$)" ;

		cout << "\n\t-----------------------------------------------------------------------------------";
		cout << "---------------------" << endl;

		if (vCurrencies.empty())
			cout << "\t\t\t\tNo Currencies Available In the System!";
		else {

		}

			for (clsCurrency Currency : vCurrencies)
			{

				_PrintCurrencyRecordLine(Currency);
				cout << endl;
			}

			cout << "\n\t-----------------------------------------------------------------------------------";
			cout << "---------------------" << endl;

	}

};

