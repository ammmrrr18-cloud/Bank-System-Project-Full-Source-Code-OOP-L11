#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsCurrencyCalculatorScreen:protected clsScreen
{

private:

	static void _PrintCurrencyCard(clsCurrency& Currency1,string Message="\n\nConvert From:\n")
	{
		cout << Message << endl;

		cout << "----------------------------\n";
		cout << "Country    : " << Currency1.GetCountry() << endl;
		cout << "Code       : " << Currency1.GetCurrencyCode() << endl;
		cout << "Name       : " << Currency1.GetCurrencyName() << endl;
		cout << "Rate(1$) = : " << Currency1.GetExchangeRate() << endl;
		cout << "----------------------------\n";


	}
	static clsCurrency _GetCurrencyObject(string Message)
	{
		string CurrencyCode = "";

		cout << Message;
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is Not found,please enter another one :";
			CurrencyCode = clsInputValidate::ReadString();
		}

		return clsCurrency::FindByCurrencyCode(CurrencyCode);
	}
	static float _ReadExchangeAmount()
	{
		float ExchangeAmount = 0;

		cout << "\nEnter Amount to Exchange: ";
		ExchangeAmount = clsInputValidate::ReadFloatNumber();

		return ExchangeAmount;
	}


	static void _PrintConverationResult(float ExchangeAmount, string CurrencyCodeFrom, float ConvertedAmount, string CurrencyCodeTo)
	{
		cout << ExchangeAmount << " " << CurrencyCodeFrom << " = " << ConvertedAmount << " " << CurrencyCodeTo << endl;
	}

	static void _PerformCalculationAndShow(float ExchangeAmount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		_PrintCurrencyCard(CurrencyFrom, "\nConvert From:");

		float AmountInUSD = CurrencyFrom.ConvertToUSD(ExchangeAmount);
		_PrintConverationResult(ExchangeAmount, CurrencyFrom.GetCurrencyCode(), AmountInUSD, "USD");

		if (CurrencyTo.GetCurrencyCode() != "USD")
		{
			cout << "\nConverting from USD to:\n";
			_PrintCurrencyCard(CurrencyTo, "\nConvert To:");

			float ConvertedAmount = CurrencyFrom.ConvertToOtherCountry(ExchangeAmount, CurrencyTo);
			_PrintConverationResult(ExchangeAmount, CurrencyFrom.GetCurrencyCode(), ConvertedAmount, CurrencyTo.GetCurrencyCode());
		}
	}



public:
	
	static void ShowCurrencyCalculatorScreen()
	{

		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y')
		{

			system("cls");
			_DrawScreenHeader("\tCurrency Calculator Screen");


			clsCurrency CurrencyFrom = _GetCurrencyObject("\nPlease enter Currency1 Code : ");
			clsCurrency CurrencyTo = _GetCurrencyObject("\nPlease enter Currency2 Code : ");
			float ExchangeAmount = _ReadExchangeAmount();


			_PerformCalculationAndShow(ExchangeAmount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> Continue;
		}



	}



};




