/**
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description:
*/
#include "ConsoleInterface.h"
#include "ComputerPlayer.h"
#include "Lexicon.h"
#include "BogglePieceGenerator.h"
#include "utility.h"
#include <iostream>
#include <string>
#include <fstream>
#include <set>


int main(int argc, char* argv[])
{
  // Set default command line arguments
  int boardSize = 4;
  int rseed = 7;
  int minLetters = 3;
  string lexiconFile = "lexicon-clean.txt";

  // If there is an invalid number of command line arguments,
  // print an error and exit.
  if(argc != 5 && argc != 1){
    cerr << "Incorrect number of command line arguments" << endl;
    exit(1);
  }

  // If the user entered four command line arguments, change the
  // default arguments to the ones specified at the command line.
  if( argc == 5 ){
    boardSize = atoi(argv[1]);
    rseed = atoi(argv[2]);
    minLetters = atoi(argv[3]);
    lexiconFile = string(argv[4]);
  }

  // check the arguments passed in to make sure they are valid. Print error
  // and exit if one or more are invalid.
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
  ComputerPlayer computer;

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
    // Make a set of humanWords
    set<string> humanWords;

    // Make a set of compWords
    set<string> compWords;
    
    // get human player words
    string humanPlayerWord;
    while( console.readNextMove(humanPlayerWord) ){

      makeLowerCase(humanPlayerWord);
      // check to see whether the string is the correct length
      // if not, ask for another
      if(humanPlayerWord.length() < minLetters || humanPlayerWord.length() > (boardSize * boardSize))
      {
	cout << "Error: Word is not the correct size.\n";
      }	


      // check to see whether the string is actually a word
      // if not, ask for another
      else if(lexicon.wordStatus(humanPlayerWord) != Lexicon::WORD)
      {
	cout << "Error: Word is not a word.\n";
      }

      // check to see whether it is on the board
      // if not, ask for another
      else if (!board.isWordOnBoard(humanPlayerWord))
      {
        cout << "Error: Word is not on board.\n";
      }

      // check to see whether it has been played before
      // if so, ask for another
      else if (humanWords.find(humanPlayerWord) != humanWords.end())
      {
        cout << "Error: Word already played.\n";
      }
      
      else
      {
	// TODO: Make uppercase
        //makeUpperCase(humanPlayerWord);
	humanWords.insert(humanPlayerWord);
      }

    }

    int humanScore = humanWords.size();

    // log the human player's words
    console.logWords(humanWords.begin(), humanWords.end(), humanFilePrefix, playCount);


       
    // TODO: This section...
    // ask computer player for words
    cout << endl << "Thinking..." << endl << endl;;
    computer.playBoggle(board, lexicon, minLetters, humanWords, compWords);
    int computerScore = compWords.size();

    // output words to screen
    for (set<string>::iterator iter = compWords.begin();
      iter != compWords.end(); ++iter)
    {
      cout << *iter << endl;
    }


    // log the computer player's words
    console.logWords(compWords.begin(), compWords.end(), computerFilePrefix, playCount);

    // print score
    console.printScore(humanScore, computerScore);

    // END STUDENT SECTION 
 

    wannaPlay = console.playAnotherGame();
  }
}
