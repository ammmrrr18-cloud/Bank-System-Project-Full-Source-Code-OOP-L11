#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"


using namespace std;
class clsCurrency
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };

	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _ExchangeRate;

	static clsCurrency ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string>vCurrency = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stof( vCurrency[3]));

	}

	static vector <clsCurrency> _LoadsCurrenciesFromFile()
	{
		fstream MyFile;
		vector<clsCurrency>vCurrencies;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line = "";

			while (getline(MyFile, Line))
			{
				vCurrencies.push_back(ConvertLineToCurrencyObject(Line));
			}

			MyFile.close();

		}

		return vCurrencies;
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.GetCountry() + Seperator;
		stCurrencyRecord += Currency.GetCurrencyCode() + Seperator;
		stCurrencyRecord += Currency.GetCurrencyName() + Seperator;
		stCurrencyRecord += to_string(Currency.GetExchangeRate());

		return stCurrencyRecord;

	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency &C : vCurrencys)
			{

				DataLine = _ConvertCurrencyObjectToLine(C);
				MyFile << DataLine << endl;

			}

			MyFile.close();

		}

	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	void _Update()
	{
		fstream MyFile;
		vector <clsCurrency>vCurrencies = _LoadsCurrenciesFromFile();

		for (clsCurrency &C: vCurrencies)
		{
			if (C.GetCurrencyCode() == _CurrencyCode)
			{
				C = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(vCurrencies);
	}

public:


	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float ExchangeRate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_ExchangeRate = ExchangeRate;
		
	}


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string GetCountry()
	{
		return _Country;
	}
	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}
	string GetCurrencyName()
	{
		return _CurrencyName;
	}


	float GetExchangeRate()
	{
		return _ExchangeRate;
	}
	void UpdateExchangeRate(float NewExchangeRate)
	{
		_ExchangeRate = NewExchangeRate;
		_Update();
	}

	__declspec(property(get = GetExchangeRate, put = UpdateExchangeRate)) float  ExchangeRate;


	static clsCurrency FindByCountry(string Country)
	{
		
		vector<clsCurrency>vCurrency = _LoadsCurrenciesFromFile();

		Country = clsString::UpperAllString(Country);

		for (clsCurrency &CurrencyObject : vCurrency)
		{
			if (clsString::UpperAllString( CurrencyObject.GetCountry()) == Country)
			{
				return CurrencyObject;
			}
		}

		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCurrencyCode(string CurrencyCode)
	{

		vector<clsCurrency>vCurrency = _LoadsCurrenciesFromFile();
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		
		for (clsCurrency& CurrencyObject : vCurrency)
		{
			if (CurrencyObject.GetCurrencyCode() == CurrencyCode)
			{
				return CurrencyObject;
			}
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = FindByCurrencyCode(CurrencyCode);

		return (!Currency.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadsCurrenciesFromFile();
	}


	float ConvertToUSD(float ExchangeAmount)
	{
		return (float)ExchangeAmount / GetExchangeRate();
	}

	float ConvertToOtherCountry(float ExchangeAmount, clsCurrency CurrencyTo)
	{
		float AmountInUSD = ConvertToUSD(ExchangeAmount);

		if (CurrencyTo.GetCurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)AmountInUSD * CurrencyTo.GetExchangeRate();
	}






};

