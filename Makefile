# Name: Jeff McCullen and Emma Elliott
# Date: April 10, 2016
# Description: Boggle makefile.

CC = g++
CFLAGS = -g #-Wall

all: boggle.exe tests.exe

tests.exe: tests.o BogglePieceGenerator.o Lexicon.o
	$(CC) $(CFLAGS) -o tests.exe tests.o BogglePieceGenerator.o Lexicon.o

boggle.exe: Main.o BogglePieceGenerator.o Lexicon.o ConsoleInterface.o \
BoggleBoard.o
	$(CC) $(CFLAGS) -o boggle.exe Main.o BogglePieceGenerator.o \
	Lexicon.o ConsoleInterface.o BoggleBoard.o

BoggleBoard.o: BoggleBoard.cpp BoggleBoard.h BogglePieceGenerator.h
	$(CC) $(CFLAGS) -c BoggleBoard.cpp

ConsoleInterface.o: ConsoleInterface.cpp ConsoleInterface.h \
BoggleBoard.h
	$(CC) $(CFLAGS) -c ConsoleInterface.cpp

tests.o: tests.cpp
	$(CC) $(CFLAGS) -c tests.cpp

Main.o: Main.cpp ConsoleInterface.h ComputerPlayer.h Lexicon.h \
	BogglePieceGenerator.h
	$(CC) $(CFLAGS) -c Main.cpp

BogglePieceGenerator.o: BogglePieceGenerator.cpp BogglePieceGenerator.h
	$(CC) $(CFLAGS) -c BogglePieceGenerator.cpp

Lexicon.o: Lexicon.cpp Lexicon.h

BoggleBoard.h: BogglePieceGenerator.h

ComputerPlayer.h: Lexicon.h

ConsoleInterface.h: BoggleBoard.h

clean:
	rm -f tests.exe boggle.exe *.o *~
