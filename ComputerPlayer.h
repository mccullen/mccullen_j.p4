/**
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description:
*/
#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "Lexicon.h"
#include "BoggleBoard.h"
#include <set>

class ComputerPlayer
{
private:
	/**
	 * Recursive helper function for playing boggle.
	 */
	virtual void playBoggleAux(
		int row, 
		int column,
		std::string& word, 
		BoggleBoard& board,
		const Lexicon& lexicon,
		int minLetters,
		const std::set<std::string>& humanWords,
		std::set<std::string>& compwords) const;
public:
	/**
	 * Construct a default ComputerPlayer.
	 */
	ComputerPlayer();

	/**
	 * Play a game of boggle and store all the words in compWords.
	 *
	 * @param board The boggle board.
	 * @param lexicon The lexicon which contains valid words.
	 * @param minLetters The minimum length of a valid word.
	 * @param humanWords Set of words the human has already played.
	 * @param compWords Set of words the computer will play.
	 */
	virtual void playBoggle(
		BoggleBoard& board, 
		const Lexicon& lexicon,
		int minLetters,
		const std::set<std::string>& humanWords,
		std::set<std::string>& compWords) const;

	/**
	 * Destruct a ComputerPlayer.
	 */
	virtual ~ComputerPlayer(void);
};

#endif
