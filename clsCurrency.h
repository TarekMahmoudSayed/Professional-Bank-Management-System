#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "clsString.h"

using namespace std;

class clsCurrency{

private:

	enum enMode {EmptyMode = 0, UpdateMode = 1};

	enMode _Mode;

	string _CountryName;
	string _CurrencyCode;
	string _CurrencyName;

	double _Rate;

	inline static vector <clsCurrency> _vAllCurrencies;

	static clsCurrency _ConvertCurrencyLineToRecord(string Line, string Seperator = "#//#") {

		clsCurrency Currency = GetEmptyCurrencyObject();

		vector <string> vCurrencyData = clsString::Split(Line, Seperator);

		Currency._Mode = enMode::UpdateMode;

		if (vCurrencyData.size() < 4) {
			return GetEmptyCurrencyObject();
		}

		Currency._CountryName = vCurrencyData[0];
		Currency._CurrencyCode = vCurrencyData[1];
		Currency._CurrencyName = vCurrencyData[2];

		try {
			Currency._Rate = stod(vCurrencyData[3]);
		}
		catch (...) {
			Currency._Rate = 0;
		}

		return Currency;

	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#") {

		string Line = "";

		Line += Currency._CountryName + Seperator;
		Line += Currency._CurrencyCode + Seperator;
		Line += Currency._CurrencyName + Seperator;
		Line += to_string(Currency._Rate);

		return Line;

	}

	static void _LoadCurrenciesDataFromFile() {

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open()) {

			_vAllCurrencies.clear();

			string Line = "";

			while (getline(MyFile, Line)) {
				_vAllCurrencies.push_back(_ConvertCurrencyLineToRecord(Line));
			}

			MyFile.close();

		}

	}

	static void _SaveCurrenciesDataToFile(vector <clsCurrency> vCurrencies) {

		fstream MyFile;

		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open()) {

			for (auto& C : vCurrencies) {
				MyFile << _ConvertCurrencyObjectToLine(C) << endl;
			}

			MyFile.close();

		}


	}

	void _Update() {

		_LoadCurrenciesDataFromFile();


		for (auto& c : _vAllCurrencies) {

			if (c.CurrencyCode() == _CurrencyCode) {
				c = *this;
				break;
			}

		}

		_SaveCurrenciesDataToFile(_vAllCurrencies);

	}



public :

	clsCurrency(enMode Mode, string CountryName, string CurrencyCode, string CurrencyName, double Rate) {
		_Mode = Mode;
		_CountryName = CountryName;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate; 
	}


	string Country() {
		return _CountryName;
	}

	string CurrencyName() {
		return _CurrencyName;
	}

	string CurrencyCode() {
		return _CurrencyCode;
	}

	double Rate() {
		return _Rate;
	}

	void UpdateRate(double NewRate) {
		_Rate = NewRate;
		_Update();
	}

	bool IsEmpty() {
		return _Mode == enMode::EmptyMode;
	}

	static clsCurrency FindByCode(string CurrencyCode) {

		CurrencyCode = clsString::UpperAllString(CurrencyCode);

		_LoadCurrenciesDataFromFile();

		for (auto& C : _vAllCurrencies) {

			if (CurrencyCode == C.CurrencyCode()) {
				return C;
			}

		}

		return GetEmptyCurrencyObject();

	}

	static clsCurrency FindByCountry(string Country) {

		Country = clsString::UpperAllString(Country);

		_LoadCurrenciesDataFromFile();

		for (auto& C : _vAllCurrencies) {

			if (Country == clsString::UpperAllString(C.Country())) {
				return C;
			}

		}

		return GetEmptyCurrencyObject();

	}

	static bool isCurrencyExist(string CurrencyCode) {

		clsCurrency Currency = FindByCode(CurrencyCode);

		return !Currency.IsEmpty();

	}

	static vector <clsCurrency> GetCurrenciesList() {

		_LoadCurrenciesDataFromFile();

		return _vAllCurrencies;

	}

	static clsCurrency GetEmptyCurrencyObject() {
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	double ConvertToUSD(double Amount) {

		return (Amount / _Rate);

	}

	 double ConvertToAnotherCurrency(double Amount, clsCurrency Currency2) {

		 double Tem = ConvertToUSD(Amount);

		 return Tem * Currency2.Rate();

	}

};
