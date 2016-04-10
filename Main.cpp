#include "ConsoleInterface.h"
#include "ComputerPlayer.h"
#include "Lexicon.h"
#include "BogglePieceGenerator.h"
#include <iostream>
#include <string>
#include <fstream>

void printStatus(Lexicon::Status status)
{
	switch (status)
	{
	case Lexicon::WORD:
		cout << "word\n";
		break;
	case Lexicon::WORD_PREFIX:
		cout << "prefix\n";
		break;
	case Lexicon::NOT_WORD:
		cout << "not word\n";
		break;
	}
}
int main(int argc, char* argv[])
{
	Lexicon lexicon("junk.txt");

	cout << "cat: ";
	printStatus(lexicon.wordStatus("cat"));

	cout << "ca: ";
	printStatus(lexicon.wordStatus("ca"));

	cout << "car: ";
	printStatus(lexicon.wordStatus("car"));

	cout << "hello: ";
	printStatus(lexicon.wordStatus("hello"));

	cout << "eff: ";
	printStatus(lexicon.wordStatus("eff"));



/*

  int boardSize = 4;
  int rseed = 7;
  int minLetters = 3;
  string lexiconFile = "lexicon-clean.txt";

  if(argc != 5 && argc != 1){
    cerr << "Incorrect number of command line arguments" << endl;
    exit(1);
  }

  if( argc == 5 ){
    boardSize = atoi(argv[1]);
    rseed = atoi(argv[2]);
    minLetters = atoi(argv[3]);
    lexiconFile = string(argv[4]);
  }

  // check the arguments passed in
  ifstream testStream(lexiconFile.c_str());
  if( boardSize < 3 || rseed == 0 ||	minLetters < 2 || testStream.fail() ){
    cerr << "Invalid arguments" << endl;
    exit(1);
  }
  testStream.close();

  // make the random character generator
  BogglePieceGenerator charGen(boardSize*boardSize, rseed);

  // make the console interface
  ConsoleInterface console;

  // make the lexicon file
  Lexicon lexicon(lexiconFile);

  // make the computer player
  ComputerPlayer computer(lexicon);

  // make the log file prefixes
  string humanFilePrefix = "human";
  string computerFilePrefix = "comp";

  int playCount = 0;
  bool wannaPlay = true;
  while( wannaPlay ){
    playCount++;

    // make the board
    BoggleBoard board(boardSize, charGen);

    // print the initial board
    console.printBoard(board);
    cout << endl;

    // STUDENT SECTION

    // get human player words
    string humanPlayerWord;
    while( console.readNextMove(humanPlayerWord) ){

      // check to see whether the string is the correct length
      // if not, ask for another

      // check to see whether the string is actually a word
      // if not, ask for another

      // check to see whether it is on the board
      // if not, ask for another

      // check to see whether it has been played before
      // if so, ask for another

    }

    int humanScore = ...

      // log the human player's words
      console.logWords(humanWords.begin(), humanWords.end(), humanFilePrefix, playCount);

    // ask computer player for words
    cout << endl << "Thinking..." << endl << endl;;
    computer.playBoggle(...);
    int computerScore = ...;

    // log the computer player's words
    console.logWords(compWords.begin(), compWords.end(), computerFilePrefix, playCount);

    // print score
    console.printScore(humanScore, computerScore);

    // END STUDENT SECTION 

    wannaPlay = console.playAnotherGame();
  }
  */
}
