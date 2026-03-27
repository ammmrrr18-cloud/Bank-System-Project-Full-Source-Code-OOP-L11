#pragma once
#include <iostream>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsDeleteClientScreen :protected clsScreen
{

private:

 static void _PrintClient(clsBankClient &Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:

 static void ShowDeleteClientScreen()
{

     if (!checkAccessRights(clsUser::pDeleteClient))
     {
         return;
     }


    _DrawScreenHeader("\tDelete Client Screen");

    string AccountNumber = "";

    cout << "Please enter an account number ?" << endl;
    cin >> AccountNumber;
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number is not exist,Please enter an another one : ";
        cin >> AccountNumber;
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    _PrintClient(Client1);

    char Answer;
    cout << "\nAre you sure that you want to delete this Client (y or n) ?";
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        if (Client1.Delete())
        {
            cout << "\nClient Deleted Successfully\n";
            _PrintClient(Client1);
        }
        else
        {
            cout << "Error Client Not Found\n";
        }

    }



}



};

