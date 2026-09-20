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

	static clsCurrency _GetCurrency(string Message) {

		string CurrencyCode;

		cout << Message;
		CurrencyCode = clsInputValidate::ReadString();

		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);

		while (Currency1.IsEmpty()) {
			cout << "\nCurrency Not Found :-(" << endl;
			cout << Message;
			CurrencyCode = clsInputValidate::ReadString();
			Currency1 = clsCurrency::FindByCode(CurrencyCode);

		}


		return Currency1;
	}

	static double ReadAmount() {

		double Amount = 0;

		cout << "\nEnter Amount To Exchange: ";
		Amount = clsInputValidate::ReadDblNumber();

		return Amount;

	}

	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card") {

		cout << "\n" << Title << endl;
		cout << "---------------------------" << endl;
		cout << "Country : " << Currency.Country() << endl;
		cout << "Code    : " << Currency.CurrencyCode() << endl;
		cout << "Name    : " << Currency.CurrencyName() << endl;
		cout << "Rate    : " << Currency.Rate() << endl;
		cout << "---------------------------" << endl;

	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{

		_PrintCurrencyCard(Currency1, "Convert From:");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";

		_PrintCurrencyCard(Currency2, "To:");

		float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();

	}

public :

    static void ShowCurrecnyCalculator() {

		char c = 'y';

		while (tolower(c) == 'y') {

			system("cls");

			clsScreen::_DrawScreenHeader("Currency Calculator Screen");

			clsCurrency Currency1 = _GetCurrency("\nPlease Enter Currency1 Code ? ");

			clsCurrency Currency2 = _GetCurrency("\nPlease Enter Currency2 Code ? ");
			
			double Amount = ReadAmount();

			_PrintCalculationsResults(Amount, Currency1, Currency2);

			cout << "\n\nDo you want to perform another calculation [y/n] ? ";
			cin >> c;


		}


    }


};

