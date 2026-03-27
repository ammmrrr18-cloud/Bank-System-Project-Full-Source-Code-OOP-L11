#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen :protected clsScreen
{

	static void _PrintClient(clsBankClient Client,string Message= "\nClient Card:")
	{
		
		cout <<"\n"<< Message;

		cout << "\n___________________\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static double _ReadAmount(clsBankClient SourceClient)
	{
		double Amount = 0.0;

		cout << "\nEnter transfer amount ?";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}

	  return Amount;
	}

	static string _ReadAccountNumber(string Message)
	{
		string AccountNumber;
		cout << Message << endl;
		
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}


public:


	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\tTransfer Screen");


		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("\nPlease Enter Account Number to Transfer From: "));
		_PrintClient(SourceClient,"Source Client Card");


		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nPlease enter account number to Transfrom to:"));
		
		while (SourceClient.AccountNumber() == DestinationClient.AccountNumber())
		{
			cout << "\nError: Destination account cannot be the same as the source account.\n";
			DestinationClient = clsBankClient::Find(_ReadAccountNumber("Please enter a different account number to transfer to: "));
		}

		_PrintClient(DestinationClient, "Destination Client Card");


		double Amount = _ReadAmount(SourceClient);


		char Answer = 'n';
		cout << "\nAre you sure that you want to perform this operation ? y/n?";
		cin >> Answer;
		
		if (Answer == 'y' || Answer == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.GetUserName()))
			{
				
				cout << "\nTransfer done successfully\n";
				
				
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
			}
			else
			{
				cout << "\nTransfer Faild because amount is greater than Account Balance\n";
			}



		}
		else
		{
			cout << "\nthis operation is Canseled";
		}


		 




	}


};

