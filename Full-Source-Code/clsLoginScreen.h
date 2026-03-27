#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "clsMainScreen.h"

class clsLoginScreen :protected clsScreen
{

private:

	static bool _Login()
	{
		string UserName, Password;
		bool LoginFailed = false;
		short FailedAttempts = 0;
		do
		{	
			

			if (LoginFailed)
			{
				cout << "\nInvalid UserName / Password..!\n\n";
				FailedAttempts++;
				cout << "You have " <<( 3 - FailedAttempts )<< " trial(s) to login\n";
			}


			if (FailedAttempts == 3)
			{
				cout << "\nYou have exhausted all login attempts!\n\n";
				return false;
			}
			

			UserName = clsInputValidate::ReadString("Enter Username ?");
			Password = clsInputValidate::ReadString("Enter Password ?");
			
			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();
			

		} while (LoginFailed);

		CurrentUser.RegisterLogin();

		clsMainScreen::ShowMainMenue();
		return true;

	}


public:


	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\tLogin Screen");
		return _Login();



	}






};

