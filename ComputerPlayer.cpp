/**
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description:
*/

#include <string>
#include <iostream>
#include "Lexicon.h"
#include "ComputerPlayer.h"
#include "BoggleBoard.h"
#include "utility.h"

using namespace std;

/**
 * Construct a default ComputerPlayer.
 */
ComputerPlayer::ComputerPlayer()
{
}

/**
 * Play a game of boggle and store all the words in compWords.
 *
 * @param board The boggle board.
 * @param lexicon The lexicon which contains valid words.
 * @param minLetters The minimum length of a valid word.
 * @param humanWords Set of words the human has already played.
 * @param compWords Set of words the computer will play.
 */
void ComputerPlayer::playBoggle(
	BoggleBoard& board, 
	const Lexicon& lexicon,
	int minLetters,
	const std::set<std::string>& humanWords,
	std::set<std::string>& compWords) const
{
	string word = "";
	// For every tile
	for (int row = 0; row < board.getWidth(); ++row)
	{
		for (int column = 0; column < board.getWidth(); ++column)
		{
			// store all the words that can be found that
			// are not in humanWords into compWords.
			playBoggleAux(row, column, word, board, lexicon,
				minLetters, humanWords, compWords);
		}
	}
}

/**
 * Recursive helper function for playBoggle().
 */
void ComputerPlayer::playBoggleAux(
	int row,
	int column,
	std::string& word, 
	BoggleBoard& board, 
	const Lexicon& lexicon,
	int minLetters,
	const std::set<std::string>& humanWords,
	std::set<std::string>& compWords) const
{
	// Push on the current letter (you will need to push on 
	// the next letters as you go through the successors). 
	word.push_back(board.getLetter(row, column));

	// Get status of word
	Lexicon::Status status = lexicon.wordStatus(word);

	// If status is promising (could possibly lead to a compWord)
	if (status != Lexicon::NOT_WORD)
	{
		// If the word is in board in not in human words
		if (word.size() >= static_cast<size_t>(minLetters) &&
			status == Lexicon::WORD &&
			humanWords.find(word) == humanWords.end() &&
			board.isWordOnBoard(word))
		{
			// add it to compWords
			compWords.insert(word);
		}
		// Note: No Else condition here b/c you want to go through
		// children even if the word is in the solution b/c
		// it may be both a word and a prefix to another word.

		// Go through all the children
		int iRow = row-1;
		while (iRow <= row+1 && iRow < board.getWidth())
		{
			int iColumn = column-1;
			while (iColumn <= column+1 && iColumn < board.getWidth())
			{
				if (iRow >= 0 && iColumn >= 0)
				{
					playBoggleAux(iRow, iColumn, word, 
						board, lexicon, minLetters, 
						humanWords, compWords);
				}
				++iColumn;
			}
			++iRow;
		}
	}
	word.erase(word.size()-1); // backtrack

	/*
	Note: this is an alternative way to implement the backtracking
	algorithm.

	// Push on the current letter (you will need to push on 
	// the next letters as you go through the successors). 
	word.push_back(board.getLetter(row, column));
	// If the word is in board in not in human words
	if (word.size() >= static_cast<size_t>(minLetters) &&
		humanWords.find(word) == humanWords.end() &&
		lexicon.wordStatus(word) == Lexicon::WORD &&
		board.isWordOnBoard(word))
	{
		// add it to compWords
		compWords.insert(word);
	}
	// checking for valid row and column.
	int iRow = row-1;
	while (iRow <= row+1 && iRow < board.getWidth())
	{
		int iColumn = column-1;
		while (iColumn <= column+1 && iColumn < board.getWidth())
		{
			if (iRow >= 0 && iColumn >= 0 && 
				lexicon.wordStatus(
				word) != 
				Lexicon::NOT_WORD)
			{
				playBoggleAux(iRow, iColumn, word, 
					board, lexicon, minLetters, 
					humanWords, compWords);
			}
			++iColumn;
		}
		++iRow;
	}
	word.erase(word.size()-1); // backtrack
	*/
}

/**
 * Destruct a ComputerPlayer.
 */
ComputerPlayer::~ComputerPlayer(void)
{
}

