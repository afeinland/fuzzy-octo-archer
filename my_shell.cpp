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

void parse_input(int & argc, char *buf, char *argv[])
{
    while(*buf != 0)
    {
        while(*buf == ' ' || *buf == '\t')
            *buf++ = '\0';
        *argv++ = buf;
        argc++;
        while(*buf != '\0' && *buf != ' ' && *buf != '\t')
            buf++;
    }
    *argv = 0;
}






int main()
{
    char buf[1024];
    char * argv[512];
    int argc = 0;
    while(1)
    {
        print_prompt();
        cin.getline(buf, 1023, '\n');
        parse_input(argc, buf, argv);
        for(int i = 0; i < argc; ++i)
            cout << argv[i] << endl;
        //get input
        //parse input
        //execute on input
    }


    return 0;
}

