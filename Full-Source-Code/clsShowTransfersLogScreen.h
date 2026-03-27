#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"
#include "clsColors.h"

class clsTransferLogScreen :protected clsScreen
{

private:

    static void PrintTransferLogRecordLine(clsBankClient::stTrnsferLogRecord TransferLogRecord)
    {
        cout << setw(8) << left << "" << clsColors::Grey() << "| " << clsColors::Reset()
            << clsColors::BrightYellow() << setw(23) << left << TransferLogRecord.DateTime << clsColors::Reset();

        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::Cyan() << setw(8) << left << TransferLogRecord.SourceAccountNumber << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::Cyan() << setw(8) << left << TransferLogRecord.DestinationAccountNumber << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::Red() << setw(8) << left << TransferLogRecord.Amount << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::BrightGreen() << setw(10) << left << TransferLogRecord.srcBalanceAfter << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::BrightGreen() << setw(10) << left << TransferLogRecord.destBalanceAfter << clsColors::Reset();
        cout << clsColors::Grey() << "| " << clsColors::Reset() << clsColors::BrightMagenta() << setw(8) << left << TransferLogRecord.UserName << clsColors::Reset();
    }

public:

    static void ShowTransferLogScreen()
    {
        vector <clsBankClient::stTrnsferLogRecord> vTransferLogRecord = clsBankClient::GetTransfersLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << clsColors::BrightCyan() << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << clsColors::Reset() << endl;

        cout << setw(8) << left << "";
        cout << clsColors::BlueBackground() << "| " << left << setw(23) << "Date/Time" << clsColors::Reset();
        cout << clsColors::BlueBackground() << "| " << left << setw(8) << "s.Acct" << clsColors::Reset();
        cout << clsColors::BlueBackground() << "| " << left << setw(8) << "d.Acct" << clsColors::Reset();
        cout << clsColors::BlueBackground() << "| " << left << setw(8) << "Amount" << clsColors::Reset();
        cout << clsColors::BlueBackground() << "| " << left << setw(10) << "s.Balance" << clsColors::Reset();
        cout << clsColors::BlueBackground() << "| " << left << setw(10) << "d.Balance" << clsColors::Reset();
        cout << clsColors::BlueBackground() << "| " << left << setw(8) << "User" << clsColors::Reset();

        cout << clsColors::BrightCyan() << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << clsColors::Reset() << endl;

        if (vTransferLogRecord.size() == 0)
        {
            cout << "\n" << setw(32) << "" << clsColors::Red() << "No Transfers Available In the System!" << clsColors::Reset() << "\n";
        }
        else
        {
            for (clsBankClient::stTrnsferLogRecord Record : vTransferLogRecord)
            {
                PrintTransferLogRecordLine(Record);
                cout << endl;
            }
        }

        cout << clsColors::BrightCyan() << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << clsColors::Reset() << endl;
    }

};