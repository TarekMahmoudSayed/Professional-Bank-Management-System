#pragma once

#include <iostream>

#include "clsScreen.h"
#include  "clsInputValidate.h"
#include "clsCurrency.h"

class clsCurrecnyCalculatorScreen : protected clsScreen{

    /*
        Currency to USD -> Curreny / USD
        USD to Currency  -> USD * Currency
        Currency1 to Currency2 && 1 more -> Currency1 to USD ->  to Currency2
        else -> 


    */

	static string _ReadCurrency1Code() {

		string CurrencyCode;

		cout << "\nPlease Enter Currency1 Code ? ";
		CurrencyCode = clsInputValidate::ReadString();

		return (CurrencyCode);
	}

	static string _ReadCurrency2Code() {

		string CurrencyCode;

		cout << "\nPlease Enter Currency2 Code ? ";
		CurrencyCode = clsInputValidate::ReadString();

		return (CurrencyCode);
	}

	static void _PrintCurrencyCard(clsCurrency Currency) {

		cout << "---------------------------" << endl;
		cout << "Country : " << Currency.Country() << endl;
		cout << "Code    : " << Currency.CurrencyCode() << endl;
		cout << "Name    : " << Currency.CurrencyName() << endl;
		cout << "Rate    : " << Currency.Rate() << endl;
		cout << "---------------------------" << endl;

	}

	static void PrintResultLine(string From, string To, double Amount, double Ans) {

		cout << "\n" << Amount << " " << From << " = " << Ans << " " << To << endl;

	}

public :

    static void ShowCurrecnyCalculator() {

		char c = 'y';

		while (tolower(c) == 'y') {

			system("cls");

			clsScreen::_DrawScreenHeader("Currency Calculator Screen");

			clsCurrency Currency1 = clsCurrency::FindByCode(_ReadCurrency1Code());

			while (Currency1.IsEmpty()) {
				cout << "\nCurrency1 Not Found :-(" << endl;
				Currency1 = clsCurrency::FindByCode(_ReadCurrency1Code());

			}

			clsCurrency Currency2 = clsCurrency::FindByCode(_ReadCurrency2Code());

			while (Currency2.IsEmpty()) {
				cout << "\nCurrency2 Not Found :-(" << endl;
				Currency2 = clsCurrency::FindByCode(_ReadCurrency2Code());

			}

			cout << "\nEnter Amount To Exchange: ";
			double Amount = clsInputValidate::ReadDblNumber();

			cout << "\nConvert From : " << endl;

			if (Currency2.CurrencyCode() == "USD") {

				_PrintCurrencyCard(Currency1);

				PrintResultLine(Currency1.CurrencyCode(), Currency2.CurrencyCode(), Amount, Currency1.ConvertToUSD(Amount));

			}
			else if (Currency1.CurrencyCode() == "USD") {

				_PrintCurrencyCard(Currency1);

				PrintResultLine(Currency1.CurrencyCode(), Currency2.CurrencyCode(), Amount, Currency2.Rate() * Amount);

			}
			else {

				_PrintCurrencyCard(Currency1);

				PrintResultLine(Currency1.CurrencyCode(), "USD", Amount, Currency1.ConvertToUSD(Amount));

				cout << "\nTo : " << endl;

				_PrintCurrencyCard(Currency2);

				PrintResultLine(Currency1.CurrencyCode(), Currency2.CurrencyCode(), Amount, Currency1.ConvertToAnotherCurrency(Amount, Currency2));

				
			}

			cout << "\nDo you want to perform another calculation [y/n] ? ";
			cin >> c;


		}

        

    }


};

