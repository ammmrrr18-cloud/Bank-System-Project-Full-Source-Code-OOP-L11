#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsColors.h"

class clsCurrenciesListScreen :protected clsScreen
{

private:
    static void PrintCurrencyRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << clsColors::Grey() << "| " << clsColors::Reset()
            << clsColors::BrightYellow() << setw(30) << left << Currency.GetCountry() << clsColors::Reset();

        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::BrightBlue() << setw(8) << left << Currency.GetCurrencyCode() << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::Cyan() << setw(45) << left << Currency.GetCurrencyName() << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::BrightGreen() << setw(10) << left << Currency.GetExchangeRate() << clsColors::Reset();
    }

public:

    static void ShowCurrenciesListScreen()
    {
        vector <clsCurrency> vCurrencys = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencys.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);

        cout << clsColors::Cyan() << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << clsColors::Reset() << endl;

        cout << clsColors::Magenta();
        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << clsColors::Reset();

        cout << clsColors::Cyan() << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << clsColors::Reset() << endl;

        if (vCurrencys.size() == 0)
        {
            cout << "\n" << setw(32) << "" << clsColors::Red() << "No Currencies Available In the System!" << clsColors::Reset() << "\n";
        }
        else
        {
            for (clsCurrency Currency : vCurrencys)
            {
                PrintCurrencyRecordLine(Currency);
                cout << endl;
            }
        }

        cout << clsColors::Cyan() << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << clsColors::Reset() << endl;
    }

};