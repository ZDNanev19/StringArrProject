#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	string sentances[2] = { "Begin Game" , "How to Play?" };
	int arrow = 0;
	bool choose = true;
	while (choose)
	{
		SetConsoleTextAttribute(hConsole, 4);
		cout << " ____  __ __ ______ ______  ____ ____   ____ __    _  _     ____  ____  ____  ____   ___ ______" << endl;
		cout << " || )) || || | || | | || | ||    || \\\\ ||    ||    \\\\//    ||    ||    ||    ||     //   | || |" << endl;
		cout << " ||=)  || ||   ||     ||   ||==  ||_// ||==  ||     )/     ||==  ||==  ||==  ||==  ((      ||  " << endl;
		cout << " ||_)) \\\\_//   ||     ||   ||___ || \\\\ ||    ||__| //      ||___ ||    ||    ||___  \\\\__   ||  " << endl;
		cout << "" << endl;

		SetConsoleTextAttribute(hConsole, 8);

		//Menu
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

		if (_kbhit)
		{
			switch (_getch())
			{
			case KEY_UP:
				if (arrow == 0)
				{
					Sleep(0);
				}
				else
				{
					arrow--;
				}
				break;
			case KEY_DOWN:
				if (arrow == 1)
				{
					Sleep(0);
				}
				else
				{
					arrow++;
				}
				break;
			case ' ':
				if (arrow == 0)
				{
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