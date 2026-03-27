#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include"clsDate.h"

using namespace std;

class clsMathUtil
{

private:

    /* Helper function to format columns based on number size */
    static string _ColumSperator(int i)
    {
        if (i < 10)
            return "    |  ";
        else
            return "  |  ";
    }

    /* Helper function to print the header of the multiplication table */
    static void _PrintTableHeader()
    {
        cout << "\n\t\t\tMultiplication Table From 1 to 10\n\n";
        cout << '\t';

        for (short i = 1; i <= 10; i++)
        {
            cout << i << '\t';
        }

        cout << '\n';

        for (short i = 1; i <= 83; i++)
        {
            cout << '_';
        }

        cout << '\n';
    }

public:

    enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };
    enum enOddOrEven { Odd = 1, Even = 2 };
    enum enPalindromeOrNot { Palindrome = 1, NotPalindrome = 2 };
    enum enPositiveOrNegative { Positive = 1, Negative = 2 };

    /* Main function to print the 1 to 10 multiplication table */
    static void PrintMultiplicationTable()
    {
        _PrintTableHeader();

        for (short i = 1; i <= 10; i++)
        {
            cout << " " << i << _ColumSperator(i);

            for (short j = 1; j <= 10; j++)
            {
                cout << i * j << '\t';
            }

            cout << '\n';
        }
    }

    /* Returns the absolute value of a float number */
    static float MyABS(float Number)
    {
        if (Number < 0.0)
            return (Number * -1.0);
        else
            return Number;
    }

    /* Returns the fraction part of a float number */
    static float GetFractionPart(float Number)
    {
        return Number - int(Number);
    }

    /* Rounds a float number to the nearest integer */
    static float MyRound(float Number)
    {
        int IntegerPart = Number;
        float FractionPart = GetFractionPart(Number);

        if (abs(FractionPart) >= 0.5)
        {
            if (Number > 0)
                return ++IntegerPart;
            else
                return --IntegerPart;
        }
        else
        {
            return IntegerPart;
        }
    }

    /* Returns the largest integer less than or equal to the number */
    static float MyFloor(float Number)
    {
        if (Number > 0)
            return int(Number);
        else
            return int(--Number);
    }

    /* Returns the smallest integer greater than or equal to the number */
    static float MyCeil(float Number)
    {
        if (abs(GetFractionPart(Number)) > 0)
        {
            if (Number > 0)
                return int(++Number);
            else
                return int(Number);
        }
        else
            return int(Number);
    }

    /* Returns the square root of a number using pow function */
    static short MySqrt(short Number)
    {
        return pow(Number, 0.5);
    }

    /* Checks if a number is Prime or Not Prime */
    static enPrimeNotPrime CheckPrime(int Number)
    {
        int M = round(Number / 2);

        for (int counter = 2; counter <= M; counter++)
        {
            if (Number % counter == 0)
            {
                return enPrimeNotPrime::NotPrime;
            }
        }

        return enPrimeNotPrime::Prime;
    }

    /* Checks if the number is a Perfect Number (sum of divisors equals the number) */
    static bool IsPerfectNumber(int Number)
    {
        int Sum = 0;
        int M = round(Number / 2);

        for (int i = 1; i <= M; i++)
        {
            if (Number % i == 0)
                Sum += i;
        }

        return Number == Sum;
    }

    /* Returns the reversed version of a number */
    static int GetReverseNumber(int Number)
    {
        int Remainder = 0, ReverseNumber = 0;

        while (Number > 0)
        {
            Remainder = Number % 10;
            Number /= 10;
            ReverseNumber = ReverseNumber * 10 + Remainder;
        }

        return ReverseNumber;
    }

    /* Checks if the number is Palindrome (reads the same backwards) */
    static bool IsPalindromeNumber(int Number)
    {
        return Number == GetReverseNumber(Number);
    }

    /* Returns the sum of digits in a number */
    static int SumOfDigits(int Number)
    {
        int Remainder = 0, Sum = 0;

        while (Number > 0)
        {
            Remainder = Number % 10;
            Number /= 10;
            Sum += Remainder;
        }

        return Sum;
    }

    /* Returns the frequency of a specific digit in a number */
    static int CountDigitFrequency(short DigitToCheck, int Number)
    {
        int Remainder = 0, FreqCount = 0;

        while (Number > 0)
        {
            Remainder = Number % 10;
            Number /= 10;

            if (DigitToCheck == Remainder)
                FreqCount++;
        }

        return FreqCount;
    }

    /* Checks if the number is Odd or Even */
    static enOddOrEven CheckOddOrEven(int Number)
    {
        if (Number % 2 != 0)
            return enOddOrEven::Odd;
        else
            return enOddOrEven::Even;
    }

    /* Checks if the number is Positive or Negative */
    static enPositiveOrNegative CheckPositiveOrNegative(int Number)
    {
        if (Number > 0)
            return enPositiveOrNegative::Positive;
        else
            return enPositiveOrNegative::Negative;
    }

    /* Prints whether the number is perfect or not */
    static void PrintPerfectResult(int Number)
    {
        if (IsPerfectNumber(Number))
            cout << endl << Number << " is perfect number\n";
        else
            cout << endl << Number << " is not perfect number\n";
    }

    /* Prints all prime numbers from 1 to N */
    static void PrintPrimeNumbersFrom1ToN(int Number)
    {
        cout << "\nThe prime number from 1 to " << Number << " are :\n";
        for (int counter = 1; counter <= Number; counter++)
        {
            if (CheckPrime(counter) == enPrimeNotPrime::Prime)
                cout << counter << endl;
        }
    }

    /* Prints all perfect numbers from 1 to N */
    static void PrintPerfectNumberFron1ToN(int Number)
    {
        if (Number >= 6)
        {
            cout << "\nThe perfect numbers from 1 to " << Number << " are :\n";
            for (int i = 6; i <= Number; i++)
            {
                if (IsPerfectNumber(i))
                    cout << i << endl;
            }
        }
        else
            cout << "\nThere are no perfect Numbers from 1 to " << Number;

        cout << endl;
    }

    /* Prints frequency of all digits present in the number */
    static void PrintAllDigitsFrequency(int Number)
    {
        cout << endl;
        for (short i = 0; i <= 9; i++)
        {
            short DigitFrequency = CountDigitFrequency(i, Number);
            if (DigitFrequency > 0)
            {
                cout << "\nDigit " << i << " frequency is " << DigitFrequency << " times(s).\n";
            }
        }
    }

    /* Initializes the random number generator seed using current time */
    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    /* Generates a random number within a specific range [From to To] */
    static int RandomNumber(int From, int To)
    {
        int RandNum = rand() % (To - From + 1) + From;
        return RandNum;
    }

    /* Prints each digit of a number on a new line */
    static void PrintDigits(int Number)
    {
        int Remainder = 0;
        cout << endl;
        while (Number > 0)
        {
            Remainder = Number % 10;
            Number /= 10;
            cout << Remainder << endl;
        }
    }

    /* Swaps two short integers using reference */
    static void Swap(short& A, short& B)
    {
        short Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    /* Swaps two integers using reference */
    static void Swap(int& A, int& B)
    {
        int Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    /* Swaps two double numbers using reference */
    static void Swap(double& A, double& B)
    {
        double Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    /* Swaps two boolean values using reference */
    static void Swap(bool& A, bool& B)
    {
        bool Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    /* Swaps two characters using reference */
    static void Swap(char& A, char& B)
    {
        char Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    /* Swaps two strings using reference */
    static void Swap(string& A, string& B)
    {
        string Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static  void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);

    }
};