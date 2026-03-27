#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsColors.h" 

class clsClientListScreen :protected clsScreen
{

private:
    static void PrintClientRecordLine(clsBankClient Client)
    {
        cout << setw(8) << left << "" << clsColors::Grey() << "| " << clsColors::Reset()
            << clsColors::Cyan() << setw(15) << left << Client.AccountNumber() << clsColors::Reset();

        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::Magenta() << setw(20) << left << Client.FullName() << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::BrightYellow() << setw(12) << left << Client.Phone << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::Blue() << setw(20) << left << Client.Email << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::BrightGreen() << setw(10) << left << Client.PinCode << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::Green() << setw(12) << left << Client.AccountBalance << clsColors::Reset();
    }

public:

    static void ShowClientsList()
    {

        if (!checkAccessRights(clsUser::pListClients))
        {
            return;
        }

        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t  Client List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << clsColors::Magenta() << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << clsColors::Reset() << endl;

        cout << clsColors::BrightYellow();
        cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << clsColors::Reset();

        cout << clsColors::Magenta() << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << clsColors::Reset() << endl;

        if (vClients.size() == 0)
        {
            cout << "\n" << setw(32) << "" << clsColors::Red() << "No Clients Available In the System!" << clsColors::Reset() << "\n";
        }
        else
        {
            for (clsBankClient Client : vClients)
            {
                PrintClientRecordLine(Client);
                cout << endl;
            }
        }

        cout << clsColors::Magenta() << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << clsColors::Reset() << endl;

    }

};