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
public:
	ComputerPlayer();

	virtual void playBoggle(const BoggleBoard& board, 
		const Lexicon& lexicon,
		const std::set<std::string>& humanWords,
		std::set<std::string>& compWords) const;

	virtual ~ComputerPlayer(void);
};

#endif
