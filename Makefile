#Makefile for DTW 240

CC = g++	#compiler to use
LD = $(CC)	#command used to link objects

INCDIR = -I../	#additional directories to look for include files

CCFLAGS = -Wall -Wno-deprecated $(INCDIR) -g -c	#compiler options
LDFLAGS = -Wall -Wno-deprecated -g	     	    #linker options

OBJS = DTW.o testDTW.o Signal.o testSignal.o
EXECS = testDTW testSignal

all:	$(EXECS)

testDTW: testDTW.o DTW.o
	$(CC) -Wall -o testDTW testDTW.o DTW.o

testSignal: testSignal.o Signal.o
	$(cc) -Wall -o testSignal testSignal.o Signal.o

Signal.o: Signal.h 

DTW.o: DTW.h

clean:
	/bin/rm -f $(OBJS) $(EXECS)
