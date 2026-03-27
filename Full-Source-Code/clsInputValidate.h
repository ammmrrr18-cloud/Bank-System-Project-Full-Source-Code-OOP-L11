#pragma once
#include <iostream>
#include "clsDate.h"

using namespace std;
class clsInputValidate
{
public:


	static bool IsNumberBetween(short Num, short From, short To)
	{
		return (Num >= From && Num <= To);

	}

	static bool IsNumberBetween(int Num,int From,int To)
	{
		return (Num >= From && Num <= To);
			
	}

	static bool IsNumberBetween(float Num, float From, float To)
	{
		return (Num >= From && Num <= To);
	}

	static bool IsNumberBetween(double Num, double From, double To)
	{
		return (Num >= From && Num <= To);
	}


	// My version using CompareDates: faster, shorter, and clearer logic
	// ; avoids multiple function calls and repeated conditions, easier to maintain and read
	static bool IsDateBetween(clsDate Date, clsDate FromDate, clsDate ToDate)
	{

	if(clsDate::CompareDates(Date, FromDate)== clsDate::Equal || clsDate::CompareDates(Date, ToDate)== clsDate::Equal)
		return true;
	if(clsDate::CompareDates(Date, FromDate)== clsDate::After && clsDate::CompareDates(Date, ToDate) == clsDate::Before)
		return true;
	if (clsDate::CompareDates(Date, FromDate) == clsDate::Before && clsDate::CompareDates(Date, ToDate) == clsDate::After)
		return true;


	return false;
	}

	// Professor's version using IsDate1After/Before/Equal: longer, more verbose, multiple
	// function calls, repeated checks, harder to read and maintain

	//static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	//{
	//	//Date>=From && Date<=To
	//	if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualToDate2(Date, From))
	//		&&
	//		(clsDate::IsDate1BeforeThanDate2(Date, To) || clsDate::IsDate1EqualToDate2(Date, To))
	//		)
	//	{
	//		return true;
	//	}
	//	//Date>=To && Date<=From
	//	if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualToDate2(Date, To))
	//		&&
	//		(clsDate::IsDate1BeforeThanDate2(Date, From) || clsDate::IsDate1EqualToDate2(Date, From))
	//		)
	//	{
	//		return true;
	//	}
	//	return false;
	//}



	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Number = ReadShortNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}

	

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		float Number;

		while (!(cin >> Number))
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage << endl;

		}

		return Number;
	}

	static float ReadFloatNumberBetween(float From, float To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		float Number = 0;
		Number = ReadFloatNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadFloatNumber();
		}

		return Number;
	}



	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		int Number;

		while (!(cin>>Number))
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage << endl;

		}

		return Number;
	}
	
	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = 0;
		Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		double Number;

		while (!(cin>> Number))
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage << endl;

		}

		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = 0;

		Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}

		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString(string Message="")
	{
		string s = "";

		if(Message!="")
			cout << Message << endl;
		
		getline(cin >> ws, s);
		return s;
	}

	
};










