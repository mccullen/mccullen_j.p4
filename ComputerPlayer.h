/**
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description:
*/
#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

#include "Lexicon.h"

class ComputerPlayer
{
public:
	ComputerPlayer(const Lexicon& lexicon);
	virtual ~ComputerPlayer(void);
};

#endif
