# Name: Jeff McCullen and Emma Elliott
# Date: April 10, 2016
# Description: Boggle makefile.

CC = g++
CFLAGS = -g -Wall

all: boggle.exe

boggle.exe: Main.o BogglePieceGenerator.o Lexicon.o
	$(CC) $(CFLAGS) -o boggle.exe Main.o BogglePieceGenerator.o \
	Lexicon.o

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
	rm -f boggle.exe *.o *~
