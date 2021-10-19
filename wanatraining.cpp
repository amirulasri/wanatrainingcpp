#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <rainbow.hpp>
using namespace std;
//GLOBAL VARIABLE
int totalfees = 0;

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

void displayNetTotal(double nettotal){
    set_color(YELLOW, BG_DEFAULT);
    cout << "===== NET TOTAL =====" << endl;
    cout << "RM " << nettotal;
}

double netTotal(double totalfees, double staffactfee){
    int result;
    result = totalfees - staffactfee;
    return result;
}

void displayStaffActFee(int staffactfee){
    set_color(GREEN, BG_DEFAULT);
    string resultfeestaff;
    if(staffactfee > 0){
        resultfeestaff = "Because the total fee more than RM2500, 10% (RM" + to_string(staffactfee) + ") will be deducted for staff activities.";
    }else{
        resultfeestaff = "Not charged";
    }
    cout << "===== Staff Activities Charges =====" << endl << resultfeestaff << "\n\n";

}

double feeActivity(int totalfees){
    //DEDUCTED 10% IF MORE THAN 2500
    int staffactfee = 0;
    if(totalfees > 2500){
        staffactfee = totalfees *0.1;
    }
    return staffactfee;
}

void calcTotalFee(int *arraystudentfee, int noofstudents){
    set_color(MAGENTA, BG_DEFAULT);
    cout << "\n\n===== Total Fees =====" << endl;
    for (int i = 0; i < noofstudents; i++)
    {
        totalfees = totalfees + arraystudentfee[i];
    }
    cout<<"RM "<<totalfees << "\n\n";
}

void displayMonthFee(int *arraycoursecode, int noofstudents)
{
    int studentfee;
    int arraystudentfee[noofstudents];
    set_color(MAGENTA, BG_DEFAULT);
    cout << "\n\n===== Student Fees =====" << endl;
    for (int i = 0; i < noofstudents; i++)
    {
        set_color(BLUE, BG_DEFAULT);
        Sleep(300);
        if (arraycoursecode[i] == 1)
        {
            arraystudentfee[i] = 200;
        }
        else if (arraycoursecode[i] == 2)
        {
            arraystudentfee[i] = 150;
        }
        else if (arraycoursecode[i] == 3)
        {
            arraystudentfee[i] = 100;
        }
        cout << "Student " << i + 1;
        set_color(WHITE, BG_DEFAULT);
        cout << " :";
        set_color(GREEN, BG_DEFAULT);
        cout << " RM " << arraystudentfee[i] << endl;
    }
    calcTotalFee(arraystudentfee, noofstudents);
}

void setFee(int noofstudents)
{
    set_color(BLUE, BG_DEFAULT);
    int arraycoursecode[noofstudents];
    cout << "Enter code for each students. Below are the course list with code and price:" << endl;
    set_color(CYAN, BG_DEFAULT);
    cout << "\n1. JAVA PROGRAMMING (RM 200)\n2. MS OFFICE (Word, Excel, Powerpoint) (RM 150)\n3. AUTOCAD (RM 100)\n0. CANCEL AND EXIT\n\n";
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
    cout << monthname << " selected" << endl;
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
    double staffactfee;
    double nettotal;
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
    monthnumber = getMonth();
    set_color(MAGENTA, BG_DEFAULT);
    displayMonth(monthnumber);
    noofstudents = getNoOfStudent();
    setFee(noofstudents);
    staffactfee = feeActivity(totalfees);
    Sleep(1000);
    displayStaffActFee(staffactfee);
    nettotal = netTotal(totalfees, staffactfee);
    Sleep(1000);
    displayNetTotal(nettotal);
    set_color(DEFAULT, BG_DEFAULT);
    Sleep(1000);
    cout << "\n\nProgram ended" << endl;
    system("PAUSE");
}