#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // This is used for chanding the colour of the text

bool DrawNoose(int noose, bool GameOver = 0)
{
    switch (noose)
    {
    case 0:
    {
        system("cls");
        cout << "  ____________" << endl;
        cout << "  |          |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " /|\\" << endl;
        break;
    }
    case 1:
    {
        system("cls");
        cout << "  ____________" << endl;
        cout << "  |          |" << endl;
        cout << "  |          O" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " /|\\" << endl;
        break;
    }
    case 2:
    {
        system("cls");
        cout << "  ____________" << endl;
        cout << "  |          |" << endl;
        cout << "  |          O" << endl;
        cout << "  |          |" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " /|\\" << endl;
        break;
    }
    case 3:
    {
        system("cls");
        cout << "  ____________" << endl;
        cout << "  |          |" << endl;
        cout << "  |          O" << endl;
        cout << "  |         /|" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " /|\\" << endl;
        break;
    }
    case 4:
    {
        system("cls");
        cout << "  ____________" << endl;
        cout << "  |          |" << endl;
        cout << "  |          O" << endl;
        cout << "  |         /|\\" << endl;
        cout << "  |" << endl;
        cout << "  |" << endl;
        cout << " /|\\" << endl;
        break;
    }
    case 5:
    {
        system("cls");
        cout << "  ____________" << endl;
        cout << "  |          |" << endl;
        cout << "  |          O" << endl;
        cout << "  |         /|\\" << endl;
        cout << "  |         /" << endl;
        cout << "  |" << endl;
        cout << " /|\\" << endl;
        break;
    }
    case 6:
    {
        system("cls");
        cout << "  ____________" << endl;
        cout << "  |          |" << endl;
        cout << "  |          O" << endl;
        cout << "  |         /|\\" << endl;
        cout << "  |         / \\" << endl;
        cout << "  |" << endl;
        cout << " /|\\" << endl;
        GameOver = true;
        return GameOver;
        break;
    }
    }
}

void Play(string word, int noose, bool GameOver)
{
    cout << "Enter a word (up to 15 characters)" << endl;
    SetConsoleTextAttribute(hConsole, 15);
    getline(cin, word);

    system("cls");

    cout << "  ____________" << endl;
    cout << "  |          |" << endl;
    cout << "  |" << endl;
    cout << "  |" << endl;
    cout << "  |" << endl;
    cout << "  |" << endl;
    cout << " /|\\" << endl << endl;

    char spaces[15] = { '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', '_', };
    int isChar = 0;
    bool loop = 1;
    char playerChar;

    for (size_t i = 0; i < word.size(); i++)
    {
        cout << spaces[i] << " ";
    }

    cout << endl;

    while (loop)
    {
        cin >> playerChar;
        for (size_t i = 0; i < word.size(); i++)
        {
            if (playerChar == word[i])
            {
                spaces[i] = word[i];
                cout << playerChar << " ";
                isChar++;
            }
            else
            {
                cout << spaces[i] << " ";
            }
        }

        cout << endl;

        if (isChar == 0)
        {
            noose++;
            DrawNoose(noose, GameOver);
            cout << endl;
            for (size_t i = 0; i < word.size(); i++)
            {
                cout << spaces[i] << " ";
            }
        }
        else
        {
            DrawNoose(noose, GameOver);
            isChar = 0;
            cout << endl;
            for (size_t i = 0; i < word.size(); i++)
            {
                cout << spaces[i] << " ";
            }
        }
        cout << endl;


        if (noose == 6)
        {
            system("cls");
            cout << "  ____________" << endl;
            cout << "  |          |" << endl;
            cout << "  |          O" << endl;
            cout << "  |         /|\\" << endl;
            cout << "  |         / \\" << endl;
            cout << "  |" << endl;
            cout << " /|\\" << endl << endl;
            SetConsoleTextAttribute(hConsole, 4);
            cout << " You lost! The word was \"" << word << "\"" << endl;
            Beep(261.6256, 400);
            Beep(233.0819, 280);
            SetConsoleTextAttribute(hConsole, 15);
            break;
        }

        string winWord;
        for (size_t i = 0; i < word.size(); i++)
        {
            winWord += spaces[i];
        }

        if (winWord == word)
        {
            system("cls");
            SetConsoleTextAttribute(hConsole, 2);
            cout << " Great! You Won!" << endl;
            Beep(440.0000, 125);
            Beep(493.8833, 125);
            Beep(554.3653, 175);
            Beep(493.8833, 125);
            Beep(440.0000, 150);
            SetConsoleTextAttribute(hConsole, 15);
            loop = 0;
        }
    }
}

void mainMenu()
{
    string sentances[2] = { "Begin Game" , "How to Play?" };
    int arrow = 0;
    bool choose = true;
    string word;
    char playerChar;
    int noose = 0;
    bool GameOver = 0;
    while (choose)
    {
        SetConsoleTextAttribute(hConsole, 4); // For colouring the title in red
        cout << "'||  ||`                         '||\\   /||`                  " << endl;
        cout << " ||  ||                           ||\\\\.//||                   " << endl;
        cout << " ||''||   '''|.  `||''|,  .|''|,  ||     ||   '''|.  `||''|,  " << endl;
        cout << " ||  ||  .|''||   ||  ||  ||  ||  ||     ||  .|''||   ||  ||  " << endl;
        cout << ".||  ||. `|..||. .||  ||. `|..|| .||     ||. `|..||. .||  ||. " << endl;
        cout << "                              ||                              " << endl;
        cout << "                           `..|'                              " << endl;
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
                    cout << " How to play:" << endl;
                    cout << endl;
                    cout << " The game must be played by two players. The first player writes a word, the second player has to guess it." << endl;
                    cout << " If the second player guesses the word, he wins. Otherwise, noose with hanged man will be printed on the screen and you loose." << endl;
                    cout << " The second player has 5 tries to get the word." << endl;
                    cout << " The first person has to type a word, then the letters will be replaced with blank spaces (_). Example" << endl;
                    cout << " Player enters: house" << endl << "_ _ _ _ _" << endl;
                    cout << " Then the second player will try to guess the letter/word by typing it. Example" << endl;
                    cout << " Player enters: o" << endl << "_ o _ _ _" << endl << endl;
                    system("pause");
                }
                break;
            }
        }
        system("cls");
    }


    Play(word, noose, GameOver);
}