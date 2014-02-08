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

#ifndef LINKEDSTRING_HPP
#define LINKEDSTRING_HPP

#include <iostream>

class String
  {
public:
    /// Both constructors should construct
    /// from the parameter s
    String( const char * s = "");
    String( const String & s );
    String operator = ( const String & s );
    char & operator [] ( const int index );
    int length() const;
    int indexOf( char c ) const;
    bool operator == ( const String & s ) const;
    /// concatenates this and s
    String operator + ( const String & s ) const;
    /// concatenates s onto end of this
    String operator += ( const String & s );
    void print( std::ostream & out ) const;
    void read( std::istream & in );
    void testInBounds(int i);
    ~String();
private:
    bool inBounds( int i )
    {
      return i >= 0 && i < length();
    }
    struct ListNode
    {
      char info;
      ListNode * next;
      ListNode(char newInfo, ListNode * newNext)
        : info( newInfo ), next( newNext )
      {
      }

        static ListNode * addNodeToFront(char c, ListNode * l)
        {
            if(!l)
            {
                l = new ListNode(c, NULL);
            }
            else
            {
                l -> next = new ListNode(l -> info, l -> next);
                l -> info = c;
            }
            return l;
        }

        static ListNode * copy(ListNode * l)
        {
            if(!l)
                return NULL;

            return new ListNode(l -> info, copy(l -> next));
        }

        static void deleteList(ListNode * l)
        {
            if(! l -> next)
                delete l;
            deleteList(l -> next);
            delete l;
        }



    };
    ListNode * head;
  };
  std::ostream & operator << ( std::ostream & out, String str );
  std::istream & operator >> ( std::istream & in, String & str );
  
#endif //LINKEDSTRING_HPP
