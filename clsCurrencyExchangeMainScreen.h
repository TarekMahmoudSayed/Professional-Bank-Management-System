#pragma once

#include <iostream>

#include  "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrecnyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeMainScreen : protected clsScreen{

    enum enCurrencyExchangeMenueOptions {eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrency = 3, 
                                        eCurrecnyCalculator =4, eMainMenue = 5 };

    static short _ReadCurrencyExchangeMenueOption() {

        short Choise = 0;

        cout << setw(37) << left << "" << "Choose what do you want to do [1 to 5]? ";
        Choise = clsInputValidate::ReadShortNumberBetween(1, 5);

        return Choise;

    }

    static void _GoBackToCurrencyExchangeScreen() {
        cin.ignore();
        cout << "\n\t\t\t\t\tPress any key to go back to Currency Exchange ";
        cin.get();
        system("cls");
        clsUtil::_Loading("Going Back To CurrencyExchange Menue Screen");
        system("cls");
        ShowCurrencyExchangeScreen();
    }

    static void _ShowListCurrenciesScreen() {
        //cout << "List Currencies Screen Will Be Here " << endl;
        clsCurrenciesListScreen::ShowCurrenciesList();
    }

    static void _ShowFindCurrencyScreen() {
        //cout << "Find Currency Screen Will Be Here Soon" << endl;
        clsFindCurrencyScreen::ShowFindCurrency();
    }

    static void _ShowUpdateCurrencyScreen() {
        //cout << "Update Currency Screen Will Be Here " << endl;
        clsUpdateCurrencyScreen::ShowUpdateCurrency();
    }

    static void _ShowCurrecnyCalculatorScreen() {
        //cout << "Currecny Calculator Screen Will Be Here " << endl;
        clsCurrecnyCalculatorScreen::ShowCurrecnyCalculator();
    }
    

    static void PerformCurrencyExchangeMenueOptions(short Choise) {

        switch (enCurrencyExchangeMenueOptions(Choise)) {

        case enCurrencyExchangeMenueOptions::eListCurrencies :

            system("cls");

            clsUtil::_Loading("List Currencies Screen Loading");

            system("cls");

            _ShowListCurrenciesScreen();

            _GoBackToCurrencyExchangeScreen();

            break;

        case enCurrencyExchangeMenueOptions::eFindCurrency :

            system("cls");

            clsUtil::_Loading("Find Currency Screen Loading");

            system("cls");

            _ShowFindCurrencyScreen();

            _GoBackToCurrencyExchangeScreen();

            break;

        case enCurrencyExchangeMenueOptions::eUpdateCurrency :

            system("cls");

            clsUtil::_Loading("Update Currency Screen Loading");

            system("cls");

            _ShowUpdateCurrencyScreen();

            _GoBackToCurrencyExchangeScreen();

            break;

        
        case enCurrencyExchangeMenueOptions::eCurrecnyCalculator :

            system("cls");

            clsUtil::_Loading("Currecny Calculator Screen Loading");

            system("cls");

            _ShowCurrecnyCalculatorScreen();

            _GoBackToCurrencyExchangeScreen();

            break;

        case enCurrencyExchangeMenueOptions::eMainMenue :

            break;

        }
        


    }
    

public :

	static void ShowCurrencyExchangeScreen() {

		clsScreen::_DrawScreenHeader("Currecny Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        PerformCurrencyExchangeMenueOptions(_ReadCurrencyExchangeMenueOption());


	}

};

