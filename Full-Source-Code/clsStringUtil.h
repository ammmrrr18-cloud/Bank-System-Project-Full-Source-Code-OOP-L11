#pragma once

#include <iostream>
#include <string>
#include "clsMathUtil.h"

using namespace std;

class clsStringUtil
{
public:

    enum enCharType {
        SmallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };


    /* Returns a random character based on the specified CharType (Small, Capital, Digit, or Mixed) */
    static char GetRandomCharacter(enCharType CharType)
    {

        //updated this method to accept mixchars
        if (CharType == MixChars)
        {
            //Capital/Samll/Digits only
            CharType = (enCharType)clsMathUtil::RandomNumber(1, 3);

        }

        switch (CharType)
        {

        case enCharType::SmallLetter:
        {
            return char(clsMathUtil::RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(clsMathUtil::RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return char(clsMathUtil::RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(clsMathUtil::RandomNumber(48, 57));
            break;
        }
    default:
        {
            return char(clsMathUtil::RandomNumber(65, 90));
            break;
        }
        }
    }

    /* Generates a random word of a given length using the specified character type */
    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word = "";
        for (short i = 1; i <= Length; i++)
        {
            Word += GetRandomCharacter(CharType);
        }
        return Word;
    }

    /* Generates a security key in the format: XXXX-XXXX-XXXX-XXXX */
    static string GenerateKey()
    {
        string Key = "";
        Key = GenerateWord(enCharType::CapitalLetter, 4) + '-';
        Key += GenerateWord(enCharType::CapitalLetter, 4) + '-';
        Key += GenerateWord(enCharType::CapitalLetter, 4) + '-';
        Key += GenerateWord(enCharType::CapitalLetter, 4);
        return Key;
    }

    /* Generates and prints a specific number of security keys */
    static void GenerateKeys(short NumberOfKeys)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey() << endl;
        }
    }

    /* Encrypts text by shifting character values based on the EncryptionKey */
    static string EncryptText(string Text, int EncryptionKey=1)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }

    /* Decrypts text by reversing the shift applied during encryption */
    static string DecryptText(string Text, int EncryptionKey=1)
    {
        for (int i = 0; i < Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }

    /* Prints all possible 3-letter combinations from AAA to ZZZ */
    static void PrintWordsFromAAAtoZZZ()
    {
        cout << endl;
        string word = "";
        for (int i = 65; i <= 90; i++)
        {
            for (int j = 65; j <= 90; j++)
            {
                for (int k = 65; k <= 90; k++)
                {
                    word += char(i);
                    word += char(j);
                    word += char(k);
                    cout << word << endl;
                    word = "";
                }
            }
        }
    }

    /* Attempts to crack a 3-letter password by trying all possible combinations (Brute Force) */
    static bool GuessPassword(string OriginalPassword)
    {
        cout << endl;
        string word = "";
        int counter = 1;

        for (int i = 65; i <= 90; i++)
        {
            for (int j = 65; j <= 90; j++)
            {
                for (int k = 65; k <= 90; k++)
                {
                    word += char(i);
                    word += char(j);
                    word += char(k);

                    cout << "Trail [" << counter << "]: " << word << endl;

                    if (OriginalPassword == word)
                    {
                        cout << "\nPassword is " << word << endl;
                        cout << "Found after " << counter << " Trail(s)\n";
                        return true;
                    }
                    counter++;
                    word = "";
                }
            }
        }
        return false;
    }

    /* Prints an inverted pattern of letters based on the provided number (e.g., EEEEE, DDDD, ...) */
    static void PrintInvertedLetterPattern(int Number)
    {
        cout << endl;
        for (int i = Number + 64; i >= 65; i--)
        {
            for (int j = 1; j <= i - 64; j++)
            {
                cout << char(i);
            }
            cout << endl;
        }
    }

    /* Prints an increasing pattern of letters (e.g., A, BB, CCC, ...) */
    static void PrintLetterPattern(int Number)
    {
        cout << endl;
        for (int i = 65; i <= Number + 64; i++)
        {
            for (int j = 1; j <= i - 64; j++)
            {
                cout << char(i);
            }
            cout << endl;
        }
    }

    /* Prints an inverted pattern of numbers (e.g., 55555, 4444, 333, ...) */
    static void PrintInvertedNumberPattern(int Number)
    {
        cout << endl;
        for (int i = Number; i >= 1; i--)
        {
            for (int j = i; j >= 1; j--)
            {
                cout << i;
            }
            cout << endl;
        }
    }

    /* Prints an increasing pattern of numbers (e.g., 1, 22, 333, ...) */
    static void PrintNumberPattern(int Number)
    {
        cout << endl;
        for (int i = 1; i <= Number; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << i;
            }
            cout << endl;
        }
    }


};