#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // This is used for chanding the colour of the text

void playerChoice(string choice)
{
	bool loop = 1;
	while (loop)
	{
		SetConsoleTextAttribute(hConsole, 8);
		cout << "Plese, preform an action." << endl << "(choose between \"Ok\" and \"No\") \n> ";
		SetConsoleTextAttribute(hConsole, 15);
		getline(cin, choice);
		if (choice.find("Ok") != string::npos)
		{
			cout << "Good.";
			loop = 0;
			Beep(440.0000, 250);
			Beep(493.8833, 200);
			Beep(523.2511, 200);
		}
		else if (choice.find("No") != string::npos)
		{
			cout << "Well then.";
			loop = 0;
			Beep(440.0000, 250);
			Beep(493.8833, 200);
			Beep(415.3047, 200);
		}
		else
		{
			system("cls");
			SetConsoleTextAttribute(hConsole, 4);
			cout << "Plese choose a valid answer" << endl;
		}
	}
}

void naming(string fName, string lName)
{
	bool sure = 1;
	string answer;
	while (sure)
	{
		cout << "Enter your first name:" << endl << "> ";
		SetConsoleTextAttribute(hConsole, 15);
		getline(cin, fName);
		SetConsoleTextAttribute(hConsole, 8);
		cout << "Enter your last name:" << endl << "> ";
		SetConsoleTextAttribute(hConsole, 15);
		getline(cin, lName);
		SetConsoleTextAttribute(hConsole, 8);
		cout << "Are you sure this is you name - " << fName << " " << lName << "?\n > ";
		getline(cin, answer);
		if (answer.find("Yes") != string::npos)
		{
			Beep(440.0000, 250);
			Beep(493.8833, 200);
			Beep(554.3653, 200);
			sure = 0;
		}
		else
		{
			system("cls");
		}
	}
	system("cls");
}

// This function is used to display the Main Menu
void mainMenu()
{
	string sentances[2] = { "Begin Game" , "How to Play?" };
	int arrow = 0;
	bool choose = true;
	while (choose)
	{
		SetConsoleTextAttribute(hConsole, 4); // For colouring the title in red
		cout << " ____  __ __ ______ ______  ____ ____   ____ __    _  _     ____  ____  ____  ____   ___ ______" << endl;
		cout << " || )) || || | || | | || | ||    || \\\\ ||    ||    \\\\//    ||    ||    ||    ||     //   | || |" << endl;
		cout << " ||=)  || ||   ||     ||   ||==  ||_// ||==  ||     )/     ||==  ||==  ||==  ||==  ((      ||  " << endl;
		cout << " ||_)) \\\\_//   ||     ||   ||___ || \\\\ ||    ||__| //      ||___ ||    ||    ||___  \\\\__   ||  " << endl;
		cout << "" << endl;

		SetConsoleTextAttribute(hConsole, 8); // For colouring the instructions in grey

		//From here the Menu begins
		cout << " Use the UP and DOWN arrows to move and Space to select:" << endl;
		if (arrow == 0)
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << " -->" << '\t' << sentances[0] << "\t<--" << endl;
			cout << '\t' << sentances[1] << endl;
		}
		SetConsoleTextAttribute(hConsole, 8);
		if (arrow == 1)
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << '\t' << sentances[0] << endl;
			cout << " -->" << '\t' << sentances[1] << "\t<--" << endl;
		}

		// Selecting to begin the game or see the rules and "how to play"
		if (_kbhit)
		{
			switch (_getch())
			{
			case KEY_UP:
				if (arrow == 0)
				{
					Beep(195.9977, 200); // Low frequency sound to signify an impossible action
				}
				else
				{
					arrow--;
					Beep(391.9954, 200); // A high frequency sound to signify an compleated action
				}
				break;
			case KEY_DOWN:
				if (arrow == 1)
				{
					Beep(195.9977, 200);
				}
				else
				{
					arrow++;
					Beep(391.9954, 200);
				}
				break;
			case ' ':
				if (arrow == 0)
				{
					Beep(440.0000, 200);
					choose = false;
				}
				else
				{
					system("cls");
					system("pause");
				}
				break;
			}
		}
		system("cls");
	}
}