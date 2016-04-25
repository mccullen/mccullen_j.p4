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
	// [jrm] why does this need to be here and erase at the 
	// end rather than in the if statement?
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
				// Try next choice.
				//word.push_back(board.getLetter(iRow, iColumn));
				playBoggleAux(iRow, iColumn, word, board, lexicon, minLetters, humanWords, compWords);
				// untry choice.
				//word.erase(word.size()-1);
			}
			++iColumn;
		}
		++iRow;
	}
	word.erase(word.size()-1);
}

/**
 * Destruct a ComputerPlayer.
 */
ComputerPlayer::~ComputerPlayer(void)
{
}

