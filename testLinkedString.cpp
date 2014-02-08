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
#include <cassert>
#include "LinkedString.hpp"

using namespace std;


void printstars(int num)
{
    cout << endl;
    for(int i = 0; i < num; ++i)
        cout << "*";
    cout << endl;
}

void test_cpctor_print_assign_bracket_length()
{
    cout << "test_cpctor_print_assign_bracket_length():" << endl;
    /* test copy constructor */
        String a("Cats");
        String b(a);

    /* test print */
        cout << "a: " << a << "\nb: " << b << endl;

    /* test assignment operator */
        String c = b;
        String d;
        d = b; //All strings should be "Cats"
        cout << "\nc: " << c << "\nd: " << d << endl;

    /* test square brackets */
        cout << "\na[0]: " << a[0]; //Should print 'C'
        cout << "\nb[3]: " << b[3]; //Should print 's'
        cout << "\nc[10]: " << c[10]; //Shoulc print 'C'

    /* test length */
        cout << "\n\nlenA: " << a.length() << "\nlenB: " << b.length() << flush;
}

void test_indexOf_equality_plus_plusEquals_read()
{
    cout << "test_indexOf_equality_plus_plusEquals_read:" << endl;
    /* test indexOf(char) */
        String a("Cats");
        cout << a.indexOf('C') << " " << a.indexOf('a') << endl; //Should print "0 1"

    /* test equality */
        String b = a;
        assert( a == b);

    /* test plus */
        cout << "a + b: " << a + b << endl; //Should print "CatsCats"
        cout << "a: " << a << "\nb: " << b << endl;

    /* test plus Equals */
        a += b;
        cout << "a += b: " << a << endl; //Should print "CatsCats"
        cout << "a: " << a << "\nb: " << b << endl;

    /* test read */
        String c;
        cin >> c;
        cout << c << flush;
}

int main()
{
    test_cpctor_print_assign_bracket_length();
    printstars(80);
    test_indexOf_equality_plus_plusEquals_read();
    printstars(80);

    String test("TEST");
    test.testInBounds(2);
    cout << "test inBounds(int) passed." << endl;
    printstars(80);

    return 0;
}



