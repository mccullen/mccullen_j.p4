/**
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description: Tests for boggle board.
*/
#include "ConsoleInterface.h"
#include "ComputerPlayer.h"
#include "Lexicon.h"
#include "BogglePieceGenerator.h"
#include "BoggleBoard.h"
#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>

using namespace std;

void testLexicon();
void testLexiconFromConsole();
int main(int argc, char** argv)
{
	//testLexiconFromConsole();

	const int WIDTH = 4;
	BogglePieceGenerator gen1(WIDTH*WIDTH,7);
	BoggleBoard b1(WIDTH, gen1);

	// Test copy constructor
	BoggleBoard b2(b1);
	for (int i = 0; i < WIDTH; ++i)
	{
		for (int k = 0; k < WIDTH; ++k)
		{
			assert(b1.getLetter(i,k) == b2.getLetter(i,k));
		}
	}

	try
	{
		b1.getLetter(4, 3);
		assert(false);
	}
	catch (OutOfBoundsException e)
	{
	}
	BogglePieceGenerator gen2(WIDTH*WIDTH,5);
	BoggleBoard b3(WIDTH, gen1);
	b2 = b3;

	bool different = false;
	for (int i = 0; i < WIDTH && !different; ++i)
	{
		for (int k = 0; k < WIDTH && !different; ++k)
		{
			if (b1.getLetter(i,k) != b2.getLetter(i,k))
			{
				different = true;
			}
		}
	}
	assert(different);

	//testLexicon();
	return 0;
}

void testLexiconFromConsole()
{
	Lexicon lexicon("lexicon-clean.txt");

	string word;
	string exitWord = "-1";
	do
	{
		cout << "Enter word or " << exitWord << " to exit: ";
		cin >> word;

		if (word != exitWord)
		{
			switch (lexicon.wordStatus(word))
			{
			case Lexicon::WORD:
				cout << "WORD\n";
				break;
			case Lexicon::NOT_WORD:
				cout << "NOT_WORD\n";
				break;
			case Lexicon::WORD_PREFIX:
				cout << "WORD_PREFIX\n";
				break;
			}
		}
	} while (word != exitWord);
}
void testLexicon()
{
	Lexicon lexicon("testLexicon.txt");

	assert(lexicon.wordStatus("cat") ==
		Lexicon::WORD);
	assert(lexicon.wordStatus("ca") ==
		Lexicon::WORD_PREFIX);
	assert(lexicon.wordStatus("car") ==
		Lexicon::WORD_PREFIX);
	assert(lexicon.wordStatus("hello") ==
		Lexicon::NOT_WORD);
	assert(lexicon.wordStatus("jeff") ==
		Lexicon::WORD);

}
