#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsColors.h"
#include <iomanip>

using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{

private:

    static void PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << "\t\t"
            << clsColors::Grey() << "| " << clsColors::BrightCyan() << setw(18) << left << Client.AccountNumber()
            << clsColors::Grey() << "| " << clsColors::BrightYellow() << setw(30) << left << Client.FullName()
            << clsColors::Grey() << "| " << clsColors::BrightGreen() << setw(12) << left << Client.AccountBalance
            << clsColors::Reset() << endl;
    }

public:

    static void ShowTotalBalances()
    {

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << clsColors::Magenta() << "\n\t\t-----------------------------------------------------------------------\n" << clsColors::Reset();

        cout << "\t\t"
            << clsColors::BrightBlue() << "| " << setw(18) << left << "Account Number"
            << "| " << setw(30) << left << "Client Name"
            << "| " << setw(12) << left << "Balance" << clsColors::Reset() << endl;

        cout << clsColors::Magenta() << "\t\t-----------------------------------------------------------------------\n" << clsColors::Reset();

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t" << clsColors::Red() << "No Clients Available In the System!" << clsColors::Reset();
        else
        {
            for (clsBankClient Client : vClients)
            {
                PrintClientRecordBalanceLine(Client);
            }
        }

        cout << clsColors::Magenta() << "\t\t-----------------------------------------------------------------------\n" << clsColors::Reset();

        cout << "\n\t\t\t\t" << clsColors::Yellow() << "Total Balances = " << clsColors::BrightYellow() << TotalBalances << clsColors::Reset() << endl;

        cout << "\t\t\t" << clsColors::Underline() << clsColors::BrightMagenta() << "( " << clsString::NumberToText(TotalBalances) << " )" << clsColors::Reset() << "\n\n";
    }

};
