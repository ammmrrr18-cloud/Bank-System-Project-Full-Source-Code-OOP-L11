#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsStringUtil.h"


using namespace std;
class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;
    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkedForDeleted = false;


    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], clsStringUtil::DecryptText(vClientData[5]), stod(vClientData[6]));

    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += clsStringUtil::EncryptText(Client.PinCode) + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> &vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient &C : vClients)
            {

                if (C._MarkedForDeleted == false)
                {

                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    string _PrepareTransferLoginRecored(clsBankClient& DestinationClient, double TransferAmount, string UserName,string Seperator = "#//#")
    {
        string TransferRecored = "";

        TransferRecored = clsDate::GetSystemDateTimeString() + Seperator;
        TransferRecored += AccountNumber() + Seperator;
        TransferRecored += DestinationClient.AccountNumber() + Seperator;
        TransferRecored += to_string(TransferAmount) + Seperator;
        TransferRecored += to_string(AccountBalance) + Seperator;
        TransferRecored += to_string(DestinationClient.AccountBalance) + Seperator;
        TransferRecored += UserName;

        return TransferRecored;
    }

    void _RegisterTransferLog(clsBankClient& DestinationClient, double TransferAmount, string UserName)
    {
        fstream Myfile;

        Myfile.open("TransferLog.txt", ios::out | ios::app);

        if (Myfile.is_open())
        {
            Myfile << _PrepareTransferLoginRecored(DestinationClient, TransferAmount, UserName) << endl;
            Myfile.close();
        }


    }

    struct stTrnsferLogRecord;

    static stTrnsferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
    {
        stTrnsferLogRecord TrnsferLogRecord;

        vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
        TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
        TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
        TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
        TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
        TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
        TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
        TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

        return TrnsferLogRecord;

    }



public:

    struct stTrnsferLogRecord
    {
        string DateTime;
        string SourceAccountNumber;
        string DestinationAccountNumber;
        float Amount;
        float srcBalanceAfter;
        float destBalanceAfter;
        string UserName;

    };



    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    bool MarkedForDeleted()
    {
        return _MarkedForDeleted;
    }

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    /*
       No UI Related code iside object.
     void Print()
     {
         cout << "\nClient Card:";
         cout << "\n___________________";
         cout << "\nFirstName   : " << FirstName;
         cout << "\nLastName    : " << LastName;
         cout << "\nFull Name   : " << FullName();
         cout << "\nEmail       : " << Email;
         cout << "\nPhone       : " << Phone;
         cout << "\nAcc. Number : " << _AccountNumber;
         cout << "\nPassword    : " << _PinCode;
         cout << "\nBalance     : " << _AccountBalance;
         cout << "\n___________________\n";

     }*/



    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {



        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };


    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {

                return enSaveResults::svFaildEmptyObject;

            }

        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        bool Found = false;
        vector<clsBankClient> vClient = _LoadClientsDataFromFile();

        for (clsBankClient& C : vClient)
        {
            if (C._AccountNumber == _AccountNumber)
            {
                C._MarkedForDeleted = true;
                Found = true;
                break;
            }
        }

        if (!Found)
            return false;


        _SaveCleintsDataToFile(vClient);
        *this = _GetEmptyClientObject();
        return true;
    }

    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        vector<clsBankClient>vClients = clsBankClient::GetClientsList();
        double TotalBalances = 0;

        for (clsBankClient& C: vClients)
        {
            TotalBalances += C.AccountBalance;
        }

        return TotalBalances;
    }



    enum enWithdrawResult
    {
        wrSucceeded = 0,
        wrInvalidAmount = 1,
        wrInsufficientBalance = 2
    };
    enum enDepositResults { dpFaildInvalidAmount = 0, dpSucceeded = 1 };


  /*  bool Deposit(double Amount)
    {

        if (Amount <= 0)
        {
            return false;
        }

        _AccountBalance += Amount;
        Save();
        return true;
    }*/

    enDepositResults Deposit(double Amount)
    {

        if (Amount <= 0)
        {
            return enDepositResults::dpFaildInvalidAmount;
        }

        _AccountBalance += Amount;
        Save();
        return enDepositResults::dpSucceeded;
    }


    /*bool Withdraw(double Amount)
    {


        if (Amount <= 0 || Amount > _AccountBalance)
        {
            return false;
        }

            _AccountBalance -= Amount;
            Save();
            return true;
        
    }*/
    
    enWithdrawResult Withdraw(double Amount)
    {

        if (Amount <= 0)
            return enWithdrawResult::wrInvalidAmount;

        if (Amount > _AccountBalance)
            return enWithdrawResult::wrInsufficientBalance;
       
        _AccountBalance -= Amount;
        Save();
        return enWithdrawResult::wrSucceeded;

    }

    bool Transfer(double Amount,clsBankClient & DestinationClient, string UserName)
    {

        if (Amount > _AccountBalance)
        {
            return false;
        }

        Withdraw(Amount);
        DestinationClient.Deposit(Amount);

        _RegisterTransferLog(DestinationClient, Amount, UserName);

        return true;
    }


    static  vector <stTrnsferLogRecord> GetTransfersLogList()
    {
        vector <stTrnsferLogRecord> vTransferLogRecord;

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;

            stTrnsferLogRecord TransferRecord;

            while (getline(MyFile, Line))
            {

                TransferRecord = _ConvertTransferLogLineToRecord(Line);

                vTransferLogRecord.push_back(TransferRecord);

            }

            MyFile.close();

        }

        return vTransferLogRecord;

    }








};