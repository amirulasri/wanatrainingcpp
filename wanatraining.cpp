#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <rainbow.hpp>
using namespace std;

bool EnableVTMode()
{
    // Set output mode to handle virtual terminal sequences
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return false;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        return false;
    }
    return true;
}

void displayMonthFee(int *arraycoursecode, int noofstudents)
{
    int studentfee;
    set_color(MAGENTA, BG_DEFAULT);
    cout << "\n\n===== Student Fees =====" << endl;
    for (int i = 0; i < noofstudents; i++)
    {
        set_color(BLUE, BG_DEFAULT);
        if (arraycoursecode[i] == 1)
        {
            studentfee = 200;
        }
        else if (arraycoursecode[i] == 2)
        {
            studentfee = 150;
        }
        else if (arraycoursecode[i] == 3)
        {
            studentfee = 100;
        }
        cout << "Student " << i + 1;
        set_color(WHITE, BG_DEFAULT);
        cout << " :";
        set_color(GREEN, BG_DEFAULT);
        cout << " RM " << studentfee << endl;
    }
}

void setFee(int noofstudents)
{
    set_color(BLUE, BG_DEFAULT);
    int arraycoursecode[noofstudents];
    cout << "Enter code for each students. Below are the course list with code:\n1. JAVA PROGRAMMING\n2. MS OFFICE (Word, Excel, Powerpoint)\n3. AUTOCAD\n0. CANCEL AND EXIT\n\n"
         << endl;
    //int *arrayfee = new int[noofstudents];
    for (int i = 0; i < noofstudents; i++)
    {
        set_color(YELLOW, BG_DEFAULT);
        cout << "Student " << i + 1 << ": ";
        set_color(WHITE, BG_DEFAULT);
        cin >> arraycoursecode[i];
        if ((arraycoursecode[i] != 1) && (arraycoursecode[i] != 2) && (arraycoursecode[i] != 3))
        {
            if ((arraycoursecode[i] == 0))
            {
                set_color(RED, BG_DEFAULT);
                cout << "Cancelled by user!" << endl;
                set_color(DEFAULT, BG_DEFAULT);
                system("PAUSE");
                exit(EXIT_SUCCESS);
            }
            set_color(RED, BG_DEFAULT);
            cout << "INVALID CODE OPTION! Try again or enter 0 if you want to cancel and exit!" << endl;
            i = i - 1;
        }
    }
    displayMonthFee(arraycoursecode, noofstudents);
}

int getNoOfStudent()
{
    set_color(BLUE, BG_DEFAULT);
    cout << "\nEnter number of students: ";
    set_color(GREEN, BG_DEFAULT);
    int noofstudents;
    cin >> noofstudents;
    if (noofstudents < 20)
    {
        set_color(RED, BG_DEFAULT);
        cout << "STUDENT NEED AT LEAST 20! Program ended!" << endl;
        set_color(DEFAULT, BG_DEFAULT);
        system("PAUSE");
        exit(EXIT_SUCCESS);
    }
    return noofstudents;
}

void displayMonth(int monthnumber)
{
    string monthname;
    if (monthnumber == 1)
    {
        monthname = "January";
    }
    if (monthnumber == 1)
    {
        monthname = "January";
    }
    else if (monthnumber == 2)
    {
        monthname = "February";
    }
    else if (monthnumber == 3)
    {
        monthname = "March";
    }
    else if (monthnumber == 4)
    {
        monthname = "April";
    }
    else if (monthnumber == 5)
    {
        monthname = "May";
    }
    else if (monthnumber == 6)
    {
        monthname = "Jun";
    }
    else if (monthnumber == 7)
    {
        monthname = "July";
    }
    else if (monthnumber == 8)
    {
        monthname = "August";
    }
    else if (monthnumber == 9)
    {
        monthname = "September";
    }
    else if (monthnumber == 10)
    {
        monthname = "October";
    }
    else if (monthnumber == 11)
    {
        monthname = "November";
    }
    else if (monthnumber == 12)
    {
        monthname = "December";
    }
    else
    {
        set_color(RED, BG_DEFAULT);
        cout << "INVALID MONTH NUMBER! Program ended!" << endl;
        set_color(DEFAULT, BG_DEFAULT);
        system("PAUSE");
        exit(EXIT_SUCCESS);
    }
    cout << monthname << " selected";
}

int getMonth()
{
    int monthnumber;
    cin >> monthnumber;
    return monthnumber;
}

int main()
{
    EnableVTMode();
    int monthnumber;
    int noofstudents;
    set_color(BLUE, BG_DEFAULT);
    cout << "Wana Training Center \n\nTo get started, enter month number (1 - 12): ";
    set_color(GREEN, BG_DEFAULT);
    monthnumber = getMonth();
    set_color(MAGENTA, BG_DEFAULT);
    displayMonth(monthnumber);
    noofstudents = getNoOfStudent();
    setFee(noofstudents);
    cout << "\nOK SETAKAT TU JE.. NNTI KITA BINCANG LAGI UNTUK SIAPKAN C++ APP NI SEPENUHNYA!" << endl;
    set_color(DEFAULT, BG_DEFAULT);
    system("PAUSE");
}