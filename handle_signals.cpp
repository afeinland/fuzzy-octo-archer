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
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>


using namespace std;

int INTcount = 0, QUITcount = 0, TSTPcount = 0;

void print_summary(int numINT, int numQUIT, int numTSTP)
{
    cout << "Interrupt: " << numINT << "\nStop: " << numTSTP
        << "\nQuit: " << numQUIT << endl;
}


void handler(int s)
{
    switch(s)
    {
        case SIGINT: /* ctrl-C */
            cout << "I" << endl;
            ++INTcount;
            break;
        case SIGQUIT: /* ctrl-\ */
            cout << 'Q' << endl;
            ++QUITcount;
            break;
        case SIGTSTP:
            cout << 'S' << endl;
            ++TSTPcount;
            if(TSTPcount < 3)
                kill(getpid(), SIGSTOP);
            break;
        default:
            cout << "Premature Exit" << endl;
    }
    if(TSTPcount == 3)
    {
        print_summary(INTcount, QUITcount, TSTPcount);
        exit(1);
    }
}

void init_sig_handlers()
{

/* signal handler for SIGINT and SIGQUIT */
    struct sigaction sigHandler;
    sigHandler.sa_handler = handler;
    sigemptyset(&sigHandler.sa_mask);
    sigHandler.sa_flags = 0;

/* signal handler for SIGTSTP */
    struct sigaction sigHandler_TSTP;
    sigHandler_TSTP.sa_handler = handler;
    sigemptyset(&sigHandler_TSTP.sa_mask);
    sigHandler_TSTP.sa_flags = SA_NODEFER;

    sigaction(SIGINT, &sigHandler, NULL); /* ctrl-C */
    sigaction(SIGQUIT, &sigHandler, NULL); /* ctrl-\ */
    sigaction(SIGTSTP, &sigHandler_TSTP, NULL); /* ctrl-Z */
}

int main(int argc,char** argv)
{
    init_sig_handlers();

    while(1)
        cout << 'X' << flush;

    return 0;

}

