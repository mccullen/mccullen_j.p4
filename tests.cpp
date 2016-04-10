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
int main(int argc, char** argv)
{
	testLexicon();
	return 0;
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
