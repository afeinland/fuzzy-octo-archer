// Course: Course Name <Winter 2014>
//
// First Name: Alex
// Last Name: Feinland
// CS Login: afein001
// UCR email: afein001@ucr.edu
// SID: 861056485
//
// Lecture Section: <100>
// Lab Section: <21>
// TA: Bryan Marsh
//
// Assignment <HW4>
//
// I hereby certify that the code in this file 
// is ENTIRELY my own original work.
#include <iostream>
#include <unistd.h>

using namespace std;

void print_prompt()
{
    cout << "\nmy_shell% " << flush;
}


void getpath(char * arg)
{
    char * tmp = arg;
    while(*tmp != ' ')
    {
        strncat(arg, tmp, 1);
        ++tmp;
    }
}


int main()
{
    char tmpargv[512];
    char * arg = NULL; //program name
    while(1)
    {
        print_prompt();
        cin.getline(arg, 511, ' ');
        cin.getline(tmpargv, 511, '\n');
        execv(arg, NULL);
    }


    return 0;
}

