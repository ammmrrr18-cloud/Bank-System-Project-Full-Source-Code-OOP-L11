#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsUser.h"
#include "clsColors.h"

class clsLoginRegisterScreen :protected clsScreen
{

private:

    static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
    {
        cout << setw(8) << left << "" << clsColors::Grey() << "| " << clsColors::Reset()
            << clsColors::BrightYellow() << setw(35) << left << LoginRegisterRecord.DateTime << clsColors::Reset();

        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::BrightCyan() << setw(20) << left << LoginRegisterRecord.UserName << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::Magenta() << setw(20) << left << LoginRegisterRecord.Password << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::BrightGreen() << setw(10) << left << LoginRegisterRecord.Permissions << clsColors::Reset();
    }

public:

    static void ShowLoginRegisterScreen()
    {
        if (!clsScreen::checkAccessRights(clsUser::pShowLoginRegister))
        {
            return;
        }

        vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

        string Title = "\tLogin Register List Screen";
        string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << clsColors::BrightBlue() << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << clsColors::Reset() << endl;

        cout << clsColors::BrightMagenta();
        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << clsColors::Reset();

        cout << clsColors::BrightBlue() << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << clsColors::Reset() << endl;

        if (vLoginRegisterRecord.size() == 0)
        {
            cout << "\n" << setw(32) << "" << clsColors::Red() << "No Logins Available In the System!" << clsColors::Reset() << "\n";
        }
        else
        {
            for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
            {
                PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }
        }

        cout << clsColors::BrightBlue() << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << clsColors::Reset() << endl;
    }

};