/**
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description:
*/

#include "BogglePieceGenerator.h"
#include "BoggleBoard.h"
#include <vector>
#include <utility>

using namespace std;


/**
 * Creates a board of the given size.  Fills the board with 
 * characters from the RandomCharacterGenerator.
 * The board should be filled from left to right and top to bottom, e.g, 
 *   1  2  3  4
 *   5  6  7  8
 *   9 10 11 12
 *  13 14 15 16
 */
BoggleBoard::BoggleBoard(int width, BogglePieceGenerator& gen)
{
}

BoggleBoard::~BoggleBoard(void)
{
}

BoggleBoard::BoggleBoard(const BoggleBoard& original)
{
}

BoggleBoard& BoggleBoard::operator=(const BoggleBoard& rhs)
{
}


/*
 * returns the character found on the board at this location
 */
char BoggleBoard::getLetter(int row,int column)
{
	return 'a';
}

int BoggleBoard::getWidth()
{
	return 0;
}

/*
 * returns true if this word is found on the board
 */
bool BoggleBoard::isWordOnBoard(string word)
{
	return false;
}

