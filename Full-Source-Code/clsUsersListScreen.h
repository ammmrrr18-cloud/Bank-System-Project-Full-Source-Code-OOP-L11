#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsColors.h"

class clsUsersListScreen :protected clsScreen
{

private:
    static void _PrintUserRecordLine(clsUser User)
    {
        cout << setw(8) << left << "" << clsColors::Grey() << "| " << clsColors::Reset()
            << clsColors::BrightGreen() << setw(12) << left << User.UserName << clsColors::Reset();

        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::BrightCyan() << setw(25) << left << User.FullName() << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::BrightYellow() << setw(12) << left << User.Phone << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::Cyan() << setw(20) << left << User.Email << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::Red() << setw(10) << left << User.Password << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::Magenta() << setw(12) << left << User.Permissions << clsColors::Reset();
    }

public:

    static void ShowUsersList()
    {
        vector <clsUser> vUsers = clsUser::GetUsersList();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << clsColors::BrightMagenta() << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << clsColors::Reset() << endl;

        cout << clsColors::BrightBlue();
        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << clsColors::Reset();

        cout << clsColors::BrightMagenta() << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << clsColors::Reset() << endl;

        if (vUsers.size() == 0)
        {
            cout << "\n" << setw(32) << "" << clsColors::Red() << "No Users Available In the System!" << clsColors::Reset() << "\n";
        }
        else
        {
            for (clsUser& User : vUsers)
            {
                _PrintUserRecordLine(User);
                cout << endl;
            }
        }

        cout << clsColors::BrightMagenta() << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << clsColors::Reset() << endl;
    }

};