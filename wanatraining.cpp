#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <rainbow.hpp>
#include <cstdlib>
/*
NOTES:
- PROGRAM DEVELOPED BY AMIRUL ASRI, FIRDAUS, AISYAH FROM SECTION 1 SWC1323 GROUP 2
- RAINBOW.HPP NOT INCLUDE SO NEED TO INSTALL THE LIBRARY MANUALLY
- BELOW HAVE SOME CODE FOR VIRTUAL TERMINAL PROCESSING TO ENABLE COLORED TEXT IN CLI APP
- SET COLOR FUNCTION USE FOR TEXT COLORING WHEN PROGRAM IS RUNNING. NEED RAINBOW.HPP LIBRARY (INCLUDE IN SOURCE)
*/
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

// FUNCTION FOR DISPLAYING NET TOTAL AFTER CHARGE FOR STAFF ACTIVITY
void displayNetTotal(double nettotal)
{
    set_color(YELLOW, BG_DEFAULT);
    cout << "===== NET TOTAL =====" << endl;
    cout << "RM " << nettotal;
}

// CALCULATE NET TOTAL AFTER CHARGE FOR STAFF ACTIVITY
double netTotal(double totalfees, double staffactfee)
{
    int result;
    result = totalfees - staffactfee;
    return result;
}

// DISPLAY HOW MANY CHARGE FOR STAFF ACTIVITY WILL BE DEDUCTED FROM TOTAL FEE
void displayStaffActFee(int staffactfee)
{
    set_color(CYAN, BG_DEFAULT);
    string resultfeestaff;
    if (staffactfee > 0)
    {
        resultfeestaff = "Because the total fee more than RM2500, 10% (RM" + to_string(staffactfee) + ") will be deducted for staff activities.";
    }
    else
    {
        resultfeestaff = "Not charged";
    }
    cout << "===== Staff Activities Charges =====" << endl
         << resultfeestaff << "\n\n";
}

// CALCULATE CHARGE FOR STAFF ACTIVITY WILL BE DEDUCTED FROM TOTAL FEE
double feeActivity(int totalfees)
{
    //DEDUCTED 10% IF MORE THAN 2500
    int staffactfee = 0;
    if (totalfees > 2500)
    {
        staffactfee = totalfees * 0.1;
    }
    return staffactfee;
}

// DISPLAY THE TOTAL FEE
void displayTotalFee(double totalfees)
{
    set_color(MAGENTA, BG_DEFAULT);
    cout << "\n\n===== Total Fees =====" << endl;
    cout << "RM " << totalfees << "\n\n";
}

// CALCULATE THE TOTAL FEE
double calcTotalFee(int *arraystudentfee, int noofstudents)
{
    double result = 0;
    for (int i = 0; i < noofstudents; i++)
    {
        result = result + arraystudentfee[i];
    }
    return result;
}

// DISPLAY EVERY STUDENT FEE USING FOR LOOP
void displayMonthFee(int *arraystudentfee, int noofstudents)
{
    set_color(CYAN, BG_DEFAULT);
    cout << "\n\n===== Student Fees =====" << endl;
    Sleep(1000);
    for (int i = 0; i < noofstudents; i++)
    {
        set_color(BLUE, BG_DEFAULT);
        Sleep(200);
        cout << "Student " << i + 1;
        set_color(WHITE, BG_DEFAULT);
        cout << " :";
        set_color(GREEN, BG_DEFAULT);
        cout << " RM " << arraystudentfee[i] << endl;
    }
}

// SET STUDENT FEE BASED ON COURSE CODE INPUT BY USER
int *setFee(int noofstudents)
{
    set_color(BLUE, BG_DEFAULT);
    int coursecodeinput;
    int *arraystudentfee = new int[noofstudents];
    cout << "Enter code for each students. Below are the course list with code and price:" << endl;
    set_color(CYAN, BG_DEFAULT);
    cout << "\n1. JAVA PROGRAMMING (RM 200)\n2. MS OFFICE (Word, Excel, Powerpoint) (RM 150)\n3. AUTOCAD (RM 100)\n0. CANCEL AND EXIT\n\n";
    for (int i = 0; i < noofstudents; i++)
    {
        set_color(YELLOW, BG_DEFAULT);
        cout << "Student " << i + 1 << ": ";
        set_color(WHITE, BG_DEFAULT);
        cin >> coursecodeinput;

        if (coursecodeinput == 0)
        {
            set_color(RED, BG_DEFAULT);
            cout << "Cancelled by user!" << endl;
            set_color(DEFAULT, BG_DEFAULT);
            system("PAUSE");
            exit(EXIT_SUCCESS);
        }
        else if (coursecodeinput == 1)
        {
            arraystudentfee[i] = 200;
        }
        else if (coursecodeinput == 2)
        {
            arraystudentfee[i] = 150;
        }
        else if (coursecodeinput == 3)
        {
            arraystudentfee[i] = 100;
        }
        else
        {
            set_color(RED, BG_DEFAULT);
            cout << "INVALID CODE OPTION! Try again or enter 0 if you want to cancel and exit!" << endl;
            i = i - 1;
        }

    }
    return arraystudentfee;
}

// GET NUMBER OF STUDENT BEFORE PROCEED TO SET FEE
int getNoOfStudent()
{
    set_color(BLUE, BG_DEFAULT);
    cout << "\nEnter number of students (At least 20 students): ";
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

// DISPLAY THE MONTH BASED ON MONTH NUMBER INPUT BY USER
void displayMonth(int monthnumber)
{
    string monthname;
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
    cout << monthname << " selected" << endl;
}

// GET THE MONTH NUMBER BEFORE PROCEED TO DISPLAY MONTH FUNCTION
int getMonth()
{
    int monthnumber;
    cin >> monthnumber;
    return monthnumber;
}

// CALL ALL THE FUNCTION DEFINED BY DEVELOPER
int main()
{
    EnableVTMode();
    //DECLARING VARIABLE
    int monthnumber;
    int totalfees;
    double staffactfee;
    double nettotal;
    int noofstudents = 0;
    int *arraystudentfee;
    //DISPLAYING WELCOME TEXT and Wana Training center
    set_color(YELLOW, BG_DEFAULT);
    cout << "W     W    A    N    N    A      " << endl;
    Sleep(500);
    cout << "W  W  W   A A   N N  N   A A     " << endl;
    Sleep(500);
    cout << "W W W W  AAAAA  N  N N  AAAAA   ";
    set_color(MAGENTA, BG_DEFAULT);
    cout << "  Training" << endl;
    Sleep(500);
    set_color(YELLOW, BG_DEFAULT);
    cout << "WW   WW A     A N    N A     A  ";
    set_color(CYAN, BG_DEFAULT);
    cout << "  Center" << endl;
    Sleep(2000);
    set_color(BLUE, BG_DEFAULT);
    cout << "Welcome!. To get started, enter month number (1 - 12): ";
    set_color(GREEN, BG_DEFAULT);

    //GET ALL VALUE FROM THE FUNCTION CALLED AND DIPLAY ALL RESULT TO THE SCREEN
    monthnumber = getMonth();
    set_color(MAGENTA, BG_DEFAULT);
    displayMonth(monthnumber);
    noofstudents = getNoOfStudent();
    arraystudentfee = setFee(noofstudents);
    displayMonthFee(arraystudentfee, noofstudents);
    totalfees = calcTotalFee(arraystudentfee, noofstudents);
    Sleep(1000);
    displayTotalFee(totalfees);
    staffactfee = feeActivity(totalfees);
    Sleep(1000);
    displayStaffActFee(staffactfee);
    nettotal = netTotal(totalfees, staffactfee);
    Sleep(1000);
    displayNetTotal(nettotal);
    set_color(DEFAULT, BG_DEFAULT);
    Sleep(1000);
    cout << "\n\nProgram ended. Want to try GUI application? (y/n): ";
    char promptgui;
    cin >> promptgui;
    if (promptgui == 'y' || promptgui == 'Y')
    {
        cout << "Opening GUI Application" << endl;
        system("start wanatraining.exe");
    }
    cout << "Application will closed after 5 second\nDeveloped by (Group 2): ";
    set_color(YELLOW, BG_DEFAULT);
    cout << "Amirul Asri, ";
    set_color(CYAN, BG_DEFAULT);
    cout << "Firdaus, ";
    set_color(MAGENTA, BG_DEFAULT);
    cout << "Aisyah";
    set_color(DEFAULT, BG_DEFAULT);
    Sleep(5000);
}