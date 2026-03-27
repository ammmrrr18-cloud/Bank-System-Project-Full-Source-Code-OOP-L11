#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include<string>
#include <vector>

using namespace std;

class clsDate
{

private:


	short _Day;
	short _Month;
	short _Year;

	vector<string> Split(string S1, string Delim)
	{

		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;

	}


public:
	

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}


	clsDate(string Date)
	{
		vector<string>vDate = Split(Date, "/");


		this->_Day = stoi(vDate[0]);
		this->_Month = stoi(vDate[1]);
		this->_Year = stoi(vDate[2]);

	}

	clsDate(short Day, short Month, short Year)
	{
		this->_Day = Day;
		this->_Month = Month;
		this->_Year = Year;
	}

	clsDate(short DayOrderInYear, short Year)
	{
		clsDate Date = GetDateFromDayOrderInYear(DayOrderInYear, Year);

		this->_Day = Date._Day;
		this->_Month = Date._Month;
		this->_Year = Date._Year;

	}




	void SetDay(short Day)
	{
		this->_Day = Day;
	}
	short GetDay()
	{
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month)
	{
		this->_Month = Month;
	}
	short GetMonth()
	{
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetYear(short Year)
	{
		this->_Year = Year;
	}
	short GetYear()
	{
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear)) short Year;


	void Print()
	{
		cout << DateToString(*this) << endl;
	}




	static bool IsLeapYear(short Year)
	{
		return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
	}
	bool IsLeapYear()
	{
		return  IsLeapYear(_Year);
	}

	static short NumberOfDaysInAMonth(short Year, short Month)
	{
		if (Month < 1 || Month > 12)
			return 0;

		short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : (NumberOfDays[Month - 1]);
	}
	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Year, _Month);
	}


	static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (short i = 1;i < Month;i++)
		{
			TotalDays += NumberOfDaysInAMonth(Year, i);
		}

		TotalDays += Day;

		return TotalDays;
	}
	short NumberOfDaysFromTheBeginingOfTheYear()
	{
		return NumberOfDaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
	}


	static clsDate GetDateFromDayOrderInYear(short DayOrderInYear, short Year)
	{
		clsDate Date;

		short RemainnigDays = DayOrderInYear;
		short MonthDays = 0;

		Date.Year = Year;
		Date.Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Year, Date.Month);

			if (RemainnigDays > MonthDays)
			{
				RemainnigDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainnigDays;
				break;
			}
		}

		return Date;
	}
	clsDate GetDateFromDayOrderInYear(short DayOrderInYear)
	{
		return GetDateFromDayOrderInYear(DayOrderInYear, _Year);
	}



	static clsDate GetSystemDate()
	{
		clsDate Date;

		time_t Time = time(0);
		tm* Now = localtime(&Time);

		Date._Year = Now->tm_year + 1900;
		Date._Month = Now->tm_mon + 1;
		Date._Day = Now->tm_mday;

		return Date;
	}

	static string GetSystemDateTimeString()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}




	static short NumberOfDaysInAYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	short NumberOfDaysInAYear()
	{
		return NumberOfDaysInAYear(_Year);
	}


	static short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}
	short NumberOfHoursInAYear()
	{
		return NumberOfHoursInAYear(_Year);
	}

	static int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}
	int NumberOfMinutesInAYear()
	{
		return NumberOfMinutesInAYear(_Year);
	}


	static int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}
	int NumberOfSecondsInAYear()
	{
		return NumberOfSecondsInAYear(_Year);
	}


	static short NumberOfHoursInAMonth(short Year, short Month)
	{
		return NumberOfDaysInAMonth(Year, Month) * 24;
	}
	short NumberOfHoursInAMonth()
	{
		return NumberOfHoursInAMonth(_Year, _Month);
	}


	static int NumberOfMinutesInAMonth(short Year, short Month)
	{
		return NumberOfHoursInAMonth(Year, Month) * 60;
	}
	int NumberOfMinutesInAMonth()
	{
		return NumberOfMinutesInAMonth(_Year, _Month);
	}


	static int NumberOfSecondsInAMonth(short Year, short Month)
	{
		return NumberOfMinutesInAMonth(Year, Month) * 60;
	}
	int NumberOfSecondsInAMonth()
	{
		return NumberOfSecondsInAMonth(_Year, _Month);
	}



	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short A = (14 - Month) / 12;
		short Y = Year - A;
		short M = Month + 12 * A - 2;
		return (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
	}
	static short DayOfWeekOrder(clsDate Date)
	{
		return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}
	short DayOfWeekOrder()
	{
		//return DayOfWeekOrder(_Day, _Month, _Year);
		//           OR
		return DayOfWeekOrder(*this);
	}




	static string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
		return arrDayNames[DayOfWeekOrder];
	}
	string DayShortName()
	{
		return DayShortName(DayOfWeekOrder(_Day, _Month, _Year));
	}


	static string MonthShortName(short MonthNumber)
	{
		string Months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		return Months[MonthNumber - 1];
	}
	string MonthShortName()
	{
		return MonthShortName(_Month);
	}


	static void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays;

		// Index of the day from 0 to 6
		int current = DayOfWeekOrder(1, Month, Year);

		NumberOfDays = NumberOfDaysInAMonth(Year, Month);

		// Print the current month name
		printf("\n  _______________%s_______________\n\n",
			MonthShortName(Month).c_str());

		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);


			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");

	}

	static void PrintYearCalendar(short Year)
	{
		printf("\n  __________________________________\n");
		printf("\n          Calendar - %d", Year);
		printf("\n  __________________________________\n");

		for (short i = 1;i <= 12;i++)
		{
			PrintMonthCalendar(i, Year);
		}
	}



	static clsDate AddDays(short Days, clsDate Date)
	{
		short RemainingDays = Days + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
		short MonthDays = 0;

		Date.Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.Year, Date.Month);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;

				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;
				}
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}

		return Date;
	}
	void AddDays(short Days)
	{
		*this = AddDays(Days, *this);
	}



	static bool IsDate1BeforeThanDate2(clsDate& Date1, clsDate& Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false) : false);
	}
	bool IsDate1BeforeThanDate2(clsDate& Date2)
	{
		return IsDate1BeforeThanDate2(*this, Date2);
	}



	static bool IsDate1EqualToDate2(clsDate& Date1, clsDate& Date2)
	{
		return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
	}
	bool IsDate1EqualToDate2(clsDate& Date2)
	{
		return IsDate1EqualToDate2(*this, Date2);
	}



	static bool IsLastDayInMonth(clsDate& Date1)
	{
		return (Date1.Day == NumberOfDaysInAMonth(Date1.Year, Date1.Month));
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}


	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}
	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(Month);
	}



	static clsDate IncreaseDateByOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}

		return Date;
	}
	void IncreaseDateByOneDay()
	{
		*this = IncreaseDateByOneDay(*this);
	}


	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;

		while (IsDate1BeforeThanDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return IncludeEndDay ? ++Days : Days;
	}
	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}


	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;

		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}
	void SwapDates(clsDate& Date2)
	{
		SwapDates(*this, Date2);
	}



	static clsDate IncreaseDateByXDays(clsDate Date, short NumberOfDays)
	{
		for (short i = 1;i <= NumberOfDays;i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}
	void IncreaseDateByXDays(short NumberOfDays)
	{
		*this = IncreaseDateByXDays(*this, NumberOfDays);
	}



	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		Date = IncreaseDateByXDays(Date, 7);

		return Date;
	}
	void IncreaseDateByOneWeek()
	{
		*this = IncreaseDateByOneWeek(*this);
	}



	static clsDate IncreaseDateByOneMonth(clsDate Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);

		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}
	void IncreaseDateByOneMonth()
	{
		*this = IncreaseDateByOneMonth(*this);
	}



	static clsDate IncreaseDateByXMonths(clsDate Date, short NumberOfMonths)
	{
		for (short i = 1;i <= NumberOfMonths;i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}

		return Date;
	}
	void IncreaseDateByXMonths(short NumberOfMonths)
	{
		*this = IncreaseDateByXMonths(*this, NumberOfMonths);
	}



	static clsDate IncreaseDateByOneYear(clsDate Date)
	{
		Date.Year++;

		return Date;
	}
	void IncreaseDateByOneYear()
	{
		*this = IncreaseDateByOneYear(*this);
	}


	static clsDate IncreaseDateByXYears(clsDate Date, short NumberOfYears)
	{
		for (short i = 1;i <= NumberOfYears;i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}

		return Date;
	}
	void IncreaseDateByXYears(short NumberOfYears)
	{
		*this = IncreaseDateByXYears(*this, NumberOfYears);
	}



	static clsDate IncreaseDateByXYearsFaster(clsDate Date, short NumberOfYears)
	{
		Date.Year += NumberOfYears;

		return Date;
	}
	void IncreaseDateByXYearsFaster(short NumberOfYears)
	{
		*this = IncreaseDateByXYearsFaster(*this, NumberOfYears);
	}



	static clsDate IncreaseDateByOneDecade(clsDate Date)
	{
		Date.Year += 10;

		return Date;
	}
	void IncreaseDateByOneDecade()
	{
		*this = IncreaseDateByOneDecade(*this);
	}



	static clsDate IncreaseDateByXDecades(clsDate Date, short NumberOfDecades)
	{
		for (short i = 1;i <= NumberOfDecades;i++)
		{
			Date = IncreaseDateByOneDecade(Date);
		}

		return Date;
	}
	void IncreaseDateByXDecades(short NumberOfDecades)
	{
		*this = IncreaseDateByXDecades(*this, NumberOfDecades);
	}


	static clsDate IncreaseDateByXDecadesFaster(clsDate Date, short NumberOfDecades)
	{
		Date.Year += (NumberOfDecades * 10);

		return Date;
	}
	void IncreaseDateByXDecadesFaster(short NumberOfDecades)
	{
		*this = IncreaseDateByXDecadesFaster(*this, NumberOfDecades);
	}


	static clsDate IncreaseDateByOneCentury(clsDate Date)
	{
		Date.Year += 100;

		return Date;
	}
	void IncreaseDateByOneCentury()
	{
		*this = IncreaseDateByOneCentury(*this);
	}



	static clsDate IncreaseDateByOneMillennium(clsDate Date)
	{
		Date.Year += 1000;

		return Date;
	}
	void  IncreaseDateByOneMillennium()
	{
		*this = IncreaseDateByOneMillennium(*this);
	}



	static bool IsFirstDayInMonth(short Day)
	{
		return (Day == 1);
	}
	bool IsFirstDayInMonth()
	{
		return IsFirstDayInMonth(_Day);
	}


	static bool IsFirstMonthInYear(short Month)
	{
		return (Month == 1);
	}
	bool IsFirstMonthInYear()
	{
		return IsFirstMonthInYear(_Month);
	}



	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (IsFirstDayInMonth(Date._Day))
		{
			if (IsFirstMonthInYear(Date._Month))
			{
				Date._Day = 31;
				Date._Month = 12;
				Date._Year--;
			}
			else
			{
				Date._Month--;
				Date._Day = NumberOfDaysInAMonth(Date._Year, Date._Month);
			}
		}
		else
		{
			Date._Day--;
		}

		return Date;
	}
	void DecreaseDateByOneDay()
	{
		*this = DecreaseDateByOneDay(*this);
	}



	//==================== Decrease Days ====================

	static clsDate DecreaseDateByXDays(clsDate Date, short NumberOfDays)
	{
		for (short i = 1; i <= NumberOfDays; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByXDays(short NumberOfDays)
	{
		*this = DecreaseDateByXDays(*this, NumberOfDays);
	}

	//==================== Decrease Weeks ====================

	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{
		return DecreaseDateByXDays(Date, 7);
	}
	void DecreaseDateByOneWeek()
	{
		*this = DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(clsDate Date, short NumberOfWeeks)
	{
		for (short i = 1; i <= NumberOfWeeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void DecreaseDateByXWeeks(short NumberOfWeeks)
	{
		*this = DecreaseDateByXWeeks(*this, NumberOfWeeks);
	}

	//==================== Decrease Months ====================

	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{
		if (IsFirstMonthInYear(Date.Month))
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}

		short DaysInMonth = NumberOfDaysInAMonth(Date.Year, Date.Month);
		if (Date.Day > DaysInMonth)
			Date.Day = DaysInMonth;

		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		*this = DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(clsDate Date, short NumberOfMonths)
	{
		for (short i = 1; i <= NumberOfMonths; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonths(short NumberOfMonths)
	{
		*this = DecreaseDateByXMonths(*this, NumberOfMonths);
	}

	//==================== Decrease Years ====================

	static clsDate DecreaseDateByOneYear(clsDate Date)
	{
		Date.Year--;
		return Date;
	}

	void DecreaseDateByOneYear()
	{
		*this = DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(clsDate Date, short NumberOfYears)
	{
		for (short i = 1; i <= NumberOfYears; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	void DecreaseDateByXYears(short NumberOfYears)
	{
		*this = DecreaseDateByXYears(*this, NumberOfYears);
	}

	static clsDate DecreaseDateByXYearsFaster(clsDate Date, short NumberOfYears)
	{
		Date.Year -= NumberOfYears;
		return Date;
	}

	void DecreaseDateByXYearsFaster(short NumberOfYears)
	{
		*this = DecreaseDateByXYearsFaster(*this, NumberOfYears);
	}

	//==================== Decrease Decades ====================

	static clsDate DecreaseDateByOneDecade(clsDate Date)
	{
		Date.Year -= 10;
		return Date;
	}

	void DecreaseDateByOneDecade()
	{
		*this = DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(clsDate Date, short NumberOfDecades)
	{
		for (short i = 1; i <= NumberOfDecades; i++)
		{
			Date = DecreaseDateByOneDecade(Date);
		}
		return Date;
	}

	void DecreaseDateByXDecades(short NumberOfDecades)
	{
		*this = DecreaseDateByXDecades(*this, NumberOfDecades);
	}

	static clsDate DecreaseDateByXDecadesFaster(clsDate Date, short NumberOfDecades)
	{
		Date.Year -= (NumberOfDecades * 10);
		return Date;
	}

	void DecreaseDateByXDecadesFaster(short NumberOfDecades)
	{
		*this = DecreaseDateByXDecadesFaster(*this, NumberOfDecades);
	}

	//==================== Century & Millennium ====================

	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		Date.Year -= 100;
		return Date;
	}

	void DecreaseDateByOneCentury()
	{
		*this = DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate Date)
	{
		Date.Year -= 1000;
		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		*this = DecreaseDateByOneMillennium(*this);
	}




	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}
	static bool IsBusinessDay(short DayOfWeekOrder)
	{
		return (DayOfWeekOrder >= 0 && DayOfWeekOrder <= 4);
	}
	bool IsBusinessDay()
	{
		return clsDate::IsBusinessDay(*this);

		//     OR
		//return clsDate::IsBusinessDay(DayOfWeekOrder());
	}


	static short DaysUntilTheEndOfWeek(short DayOfWeekOrder)
	{
		return (6 - DayOfWeekOrder);
	}
	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(this->DayOfWeekOrder());
	}



	static short DaysUntilTheEndOfMonth(clsDate Date)
	{
		return (NumberOfDaysInAMonth(Date.Year, Date.Month) - Date.Day);
	}
	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}



	static short DaysUntilTheEndOfYear(clsDate Date)
	{
		return (NumberOfDaysInAYear(Date.Year) - NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year));
	}
	short DaysUntilTheEndOfYear()
	{
		return DaysUntilTheEndOfYear(*this);
	}


	static short GetNumberOfWeekendDays(clsDate Date1, clsDate Date2)
	{
		short Weekends = 0;

		while (IsDate1BeforeThanDate2(Date1, Date2))
		{
			if (IsWeekEnd(Date1))
			{
				Weekends++;
			}
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return IsWeekEnd(Date1) ? ++Weekends : Weekends;
	}
	short GetNumberOfWeekendDays(clsDate Date2)
	{
		return GetNumberOfWeekendDays(*this, Date2);
	}


	static short GetActualVacationDays(clsDate Date1, clsDate Date2)
	{
		return GetDifferenceInDays(Date1, Date2) - GetNumberOfWeekendDays(Date1, Date2);
	}
	short GetActualVacationDays(clsDate Date2)
	{
		return GetActualVacationDays(*this, Date2);
	}





	static bool IsEndOfWeek(clsDate Date)
	{
		return (DayOfWeekOrder(Date) == 6);
	}
	bool IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}


	static bool IsWeekEnd(clsDate Date)
	{
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}
	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}




	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{
		while (VacationDays >= 0)
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);

			if (IsBusinessDay(DateFrom))
				VacationDays--;
		}

		return DateFrom;
	}
	clsDate CalculateVacationReturnDate(short VacationDays)
	{
		return CalculateVacationReturnDate(*this, VacationDays);
	}


	//i added this method to calculate business days between 2 days
	static short CalculateBusinessDays(clsDate DateFrom, clsDate DateTo)
	{

		short Days = 0;
		while (IsDate1BeforeThanDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return Days;

	}
	short CalculateBusinessDays(clsDate DateTo)
	{
		return CalculateBusinessDays(*this, DateTo);
	}


	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		/*short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}*/

		return CalculateBusinessDays(DateFrom, DateTo);

	}
	short CalculateVacationDays(clsDate DateTo)
	{
		return CalculateVacationDays(*this, DateTo);
	}
	//above method is eough , no need to have method for the object




	static bool IsDate1AfterDate2(clsDate& Date1, clsDate& Date2)
	{
		return (Date1.Year > Date2.Year) ? true : ((Date1.Year == Date2.Year) ? ((Date1.Month > Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day > Date2.Day) : false) : false);
	}
	bool IsDate1AfterDate2(clsDate& Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}



	enum enCompareDates { Before = -1, Equal = 0, After = 1 };


	static enCompareDates CompareDates(clsDate& Date1, clsDate& Date2)
	{
		if (IsDate1BeforeThanDate2(Date1, Date2))
			return enCompareDates::Before;
		else if (IsDate1EqualToDate2(Date1, Date2))
			return enCompareDates::Equal;
		else
			return enCompareDates::After;
	}
	enCompareDates CompareDates(clsDate& Date2)
	{
		return CompareDates(*this, Date2);
	}


	static bool IsValidDate(clsDate Date)
	{
		return (Date.Day <= NumberOfDaysInAMonth(Date.Year, Date.Month) && Date.Month <= 12 && Date.Year > 0);
	}
	bool IsValidDate()
	{
		return IsValidDate(*this);
	}


	static string DateToString(clsDate Date)
	{
		return to_string(Date._Day) + '/' + to_string(Date._Month) + '/' + to_string(Date._Year);
	}
	string DateToString()
	{
		return DateToString(*this);
	}

	enum enDateFormat { Text = 1, DayMonthYear = 2, MonthDayYear = 3, YearMonthDay = 4, YearDayMonth = 5 };

	static string DateToString(clsDate Date, enDateFormat DateFormat, string Separetor = "")
	{
		switch (DateFormat)
		{
		case enDateFormat::Text:
			return "Day:" + to_string(Date._Day) + ", Month:" + to_string(Date._Month) + ", Year:" + to_string(Date._Year);

		case enDateFormat::DayMonthYear:
			return to_string(Date._Day) + Separetor + to_string(Date._Month) + Separetor + to_string(Date._Year);

		case enDateFormat::MonthDayYear:
			return to_string(Date._Month) + Separetor + to_string(Date._Day) + Separetor + to_string(Date._Year);

		case enDateFormat::YearDayMonth:
			return to_string(Date._Year) + Separetor + to_string(Date._Day) + Separetor + to_string(Date._Month);

		case enDateFormat::YearMonthDay:
			return to_string(Date._Year) + Separetor + to_string(Date._Month) + Separetor + to_string(Date._Day);
		}
	}
	string DateToString(enDateFormat DateFormat, string Separetor = "")
	{
		return DateToString(*this, DateFormat, Separetor);
	}


};
