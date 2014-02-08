# Course: Course Name <Winter 2014>
#
# First Name: Alex
# Last Name: Feinland
# CS Login: afein001
# UCR email: afein001@ucr.edu
# SID: 861056485
#
# Lecture Section: <100>
# Lab Section: <21>
# TA: Bryan Marsh
#
# Assignment <HW4>
#
# I hereby certify that the code in this file 
# is ENTIRELY my own original work.
CFLAGS = -ggdb -Wall

all: testLinkedString handle_signals my_shell

testLinkedString: testLinkedString.o LinkedString.o
	g++ $(CFLAGS) -o testLinkedString testLinkedString.o LinkedString.o

testLinkedString.o: testLinkedString.cpp
	g++ $(CFLAGS) -c testLinkedString.cpp

LinkedString.o: LinkedString.cpp LinkedString.hpp
	g++ $(CFLAGS) -c LinkedString.cpp



handleSignals: handle_signals.cpp
	g++ $(CFLAGS) -o handle_signals handle_signals.cpp



my_shell: my_shell.cpp
	g++ $(CFLAGS) -o my_shell my_shell.cpp


clean:
	rm testLinkedString handle_signals my_shell testLinkedString.o LinkedString.o

strip:
	strip -S testLinkedString

print:
	cat LinkedString.hpp LinkedString.cpp testLinkedString.cpp
