#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
HANDLE screen;
void menu(int ch)
{
    system("cls");
    int i = 0;
    char m[3][30] = {"option 1 ", "option 2 ", "option 3"};
    //You can increase the index of this array and add as many options as you want to the menu
    while (i < 3)
    {
        if (ch == i + 1)
        {
            screen = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(screen, 1);
            cout << endl
                 << m[i];
            screen = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(screen, 7);
        }
        else
            cout << endl
                 << m[i];
        i++;
    }
}
int main()
{
    system("cls");
    int i = 1;
    int ch = ' ';
    while (1)
    {
        menu(i);
        ch = getch();
        switch (ch)
        {
        case 72:
            if (i != 1)
            {
                i--;
                menu(i);
            }
            break;
        case 80:
            if (i != 6)
            {
                i++;
                menu(i);
            }
            break;
        case 13:
            if (1 != 6)
            {
                switch (i)
                {
                case 1:
                    cout<<endl<<"\nOption 1 was done";
                    break;
                case 2:
                    cout<<endl<<"\nOption 2 was done";
                    break;
                case 3:
                    cout<<endl<<"\nOption 3 was done";
                    break;
                default:
                    break;
                }
            }
            else
                exit(1);
            getch();
            break;
        case 27:
            exit(1);
        default:
            break;
        }
    }
}