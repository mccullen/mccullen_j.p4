/**
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description:
*/
#ifndef BOGGLE_BOARD_H
#define BOGGLE_BOARD_H

#include "BogglePieceGenerator.h"
#include <vector>
#include <utility>

using namespace std;

class BoggleBoard
{
public:

	// methods

	/*
	 * Creates a board of the given size.  Fills the board 
	 * with characters from the RandomCharacterGenerator.
	 * The board should be filled from left to right and top 
	 * to bottom, e.g, 
	 *   1  2  3  4
	 *   5  6  7  8
	 *   9 10 11 12
	 *  13 14 15 16
	 */
	BoggleBoard(int width, BogglePieceGenerator& gen);
	virtual ~BoggleBoard(void);
	BoggleBoard(const BoggleBoard&);
	BoggleBoard& operator =(const BoggleBoard&);


	/*
	 * returns the character found on the board at this location
	 */
	char getLetter(int row,int column);
	int getWidth();

	/*
	 * returns true if this word is found on the board
	 */
	bool isWordOnBoard(string word);
};

#endif
