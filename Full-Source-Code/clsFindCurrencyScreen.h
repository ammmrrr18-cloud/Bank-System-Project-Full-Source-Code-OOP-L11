#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen:protected clsScreen
{

private:

	static void _PrintCurrencyCard(clsCurrency &Currency1)
	{
		cout << "\nCurrency Card\n";

		cout << "----------------------------\n";
		cout << "Country    : " << Currency1.GetCountry() << endl;
		cout << "Code       : " << Currency1.GetCurrencyCode() << endl;
		cout << "Name       : " << Currency1.GetCurrencyName() << endl;
		cout << "Rate(1$) = : " << Currency1.GetExchangeRate() << endl;
		cout << "----------------------------\n";


	}

	static void _ShowResults(clsCurrency& Currency1)
	{
		if (!Currency1.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";

			_PrintCurrencyCard(Currency1);
		}
		else
		{
			cout << "\nCurrency Not Found :-(\n";
		}
	}

public:


	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");


		short Answer = 0;
		cout << "\nFind By: [1] Code or [2] Country ?";
		cin >> Answer;


		if (Answer == 1)
		{

			string CurrencyCode = "";
			cout << "\nPlease Enter CurrencyCode ?";
			CurrencyCode = clsInputValidate::ReadString();

			clsCurrency Currency1 = clsCurrency::FindByCurrencyCode(CurrencyCode);

			_ShowResults(Currency1);

		}
		
		else
		{
			string Country = "";
			cout << "\nPlease Enter Country ?";
			Country = clsInputValidate::ReadString();

			clsCurrency Currency1 = clsCurrency::FindByCountry(Country);

			_ShowResults(Currency1);

		}




	}








};

