#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"


class clsUpdateCurrencyRateScreen:protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency& Currency1)
	{
		cout << "\nCurrency Card\n";

		cout << "----------------------------\n";
		cout << "Country    : " << Currency1.GetCountry() << endl;
		cout << "Code       : " << Currency1.GetCurrencyCode() << endl;
		cout << "Name       : " << Currency1.GetCurrencyName() << endl;
		cout << "Rate(1$) = : " << Currency1.GetExchangeRate() << endl;
		cout << "----------------------------\n";


	}

	static float _ReadRate()
	{
		cout << "\nEnter New Rate: ";
		float NewRate = 0;

		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	}

	static void _UpdateNewRate(clsCurrency& Currency1)
	{
		float NewRate = 0;

		cout << "\n\nUpdate Currency Rate:\n";
		cout << "\n----------------------\n";

		NewRate = _ReadRate();
		Currency1.UpdateExchangeRate(NewRate);

		cout << "\nCurrency Rate Updated Successfully :-)\n";
		_PrintCurrencyCard(Currency1);
	}

public:


	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen");

		string CurrencyCode = "";

		cout << "\nPlease Enter CurrencyCode ?";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency1 = clsCurrency::FindByCurrencyCode(CurrencyCode);
		_PrintCurrencyCard(Currency1);


		char Answer = 'n';

		cout << "\nAre you sure you want to update the Rate of this Currency y/n?";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			_UpdateNewRate(Currency1);
		}
		else
		{
			cout << "\n\nThis operation was Cansled ...!\n\n";
		}



	}




};

