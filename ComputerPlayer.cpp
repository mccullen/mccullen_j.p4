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
using namespace std;

ComputerPlayer::ComputerPlayer()
{
}

void ComputerPlayer::playBoggle(BoggleBoard& board, 
	const Lexicon& lexicon,
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
				humanWords, compWords);
		}
	}
}

/**
 * 
 */
void ComputerPlayer::playBoggleAux(
	int row,
	int column,
	std::string& word, 
	BoggleBoard& board, 
	const Lexicon& lexicon,
	const std::set<std::string>& humanWords,
	std::set<std::string>& compWords) const
{
	// [jrm] why does this need to be here and erase at the 
	// end rather than in the if statement?
	word.push_back(board.getLetter(row, column));
	// If the word is in board in not in human words
	// TODO: Change the last condition so it checks for whatever
	// the user inputs as the minimum size.
	if (humanWords.find(word) == humanWords.end() &&
		lexicon.wordStatus(word) == Lexicon::WORD &&
		board.isWordOnBoard(word) &&
		word.size() >= 3)
	{
		// add it to compWords
		compWords.insert(word);
	}
	// TODO: Make more efficient by short circuiting and 
	// checking for valid row and column.
	for (int iRow = row-1; iRow <= row+1 && iRow < board.getWidth(); ++iRow)
	{
		for (int iColumn = column-1; iColumn <= column+1 && iColumn < board.getWidth(); ++iColumn)
		{
			// TODO: Check for just PREFIX?
			if (iRow >= 0 && iColumn >= 0 && 
				lexicon.wordStatus(
				word) != 
				Lexicon::NOT_WORD)
			{
				// Try next choice.
				//word.push_back(board.getLetter(iRow, iColumn));
				playBoggleAux(iRow, iColumn, word, board, lexicon, humanWords, compWords);
				// untry choice.
				//word.erase(word.size()-1);
			}
		}
	}
	word.erase(word.size()-1);
}

ComputerPlayer::~ComputerPlayer(void)
{
}

