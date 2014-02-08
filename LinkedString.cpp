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
#include "LinkedString.hpp"
#include <iostream>
#include <cassert>


using namespace std;

/// Both constructors should construct
/// from the parameter s
String::String( const char * s)
:head(NULL)
{
    for(int i = strlen(s) - 1; i >= 0; --i)
        head = ListNode::addNodeToFront(s[i], head);
}

String::String( const String & s )
:head(ListNode::copy(s.head))
{
}

String String::operator = ( const String & s )
{
    if(head)
     {
         //delete the linked list
     }

    this -> head = ListNode::copy(s.head);
    return *this;
}

char & String::operator [] ( const int index ) //Returns info in head by default
{
    int i;
    ListNode * p;
    for(i = 0, p = head; p != NULL; ++i, p = p -> next)
        if(i == index)
            return p-> info;
    cout << "Out Of Bounds returning index 0 - ";
    return head -> info;
}
int String::length() const
{
    int toReturn = 0;
    for(ListNode *p = head; p != NULL; p = p -> next)
        ++toReturn;
    return toReturn;
}

int String::indexOf( char c ) const
{
    int count = 0;
    for(ListNode * p = head; p != NULL; p = p -> next, ++count)
        if(p -> info == c)
            return count;
    return -1;
}

bool String::operator == ( const String & s ) const
{
    if(length() != s.length())
        return false;

    for(ListNode *p = head, *q = s.head; p != NULL; p = p -> next, q = q -> next)
        if(p -> info != q -> info)
            return false;
    return true;
}
/// concatenates this and s
String String::operator + ( const String & s ) const
{
    String toReturn(*this);
    toReturn += s;
    return toReturn;
}
/// concatenates s onto end of this
String String::operator += ( const String & s )
{
    ListNode *l1 = this -> head, *l2 = s.head;

    for( ; l1 -> next != NULL; l1 = l1 -> next)
    {
        //Empty
    }

    for(int i = s.length(); i > 0; --i, l1 = l1 -> next, l2 = l2 -> next)
    {
        l1 -> next = new ListNode(l2 -> info, NULL);
    }
    return *this;
}

void String::print( ostream & out ) const
{
    for(ListNode * p = head; p != NULL; p = p -> next)
        out << p -> info;
}

void String::read( istream & in )
{
    if(head)
        ListNode::deleteList(head);
    head = NULL;
    char tmp[1024];
    in.getline(tmp, '\n');
    int i = strlen(tmp) - 1;
    for( ; i >= 0; --i)
        head = ListNode::addNodeToFront(tmp[i], head);

}

String::~String()
{
    ListNode * tmp;
    for(ListNode * p = head; p != NULL; )
    {
        tmp = p -> next;
        delete p;
        p = tmp;
    }

}

void String::testInBounds(int i)
{
    assert(inBounds(i));
}

ostream & operator << ( ostream & out, String  str )
{
    str.print(out);
    return out;
}
istream & operator >> ( istream & in, String & str )
{
    str.read(in);
    return in;
}


