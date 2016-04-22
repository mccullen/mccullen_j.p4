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
	ComputerPlayer();

	virtual void playBoggle(
		BoggleBoard& board, 
		const Lexicon& lexicon,
		int minLetters,
		const std::set<std::string>& humanWords,
		std::set<std::string>& compWords) const;

	virtual ~ComputerPlayer(void);
};

#endif
