/**
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description:
*/
#include "ConsoleInterface.h"
#include "ComputerPlayer.h"
#include "Lexicon.h"
#include "BogglePieceGenerator.h"
#include <iostream>
#include <string>
#include <fstream>
#include <assert.h>

using namespace std;

void testLexicon();
void testLexiconFromConsole();
int main(int argc, char** argv)
{
	testLexiconFromConsole();
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
