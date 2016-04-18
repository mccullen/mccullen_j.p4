/**
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description:
*/

#include "BogglePieceGenerator.h"
#include "BoggleBoard.h"
#include <vector>
#include <utility>
#include <iostream>

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
BoggleBoard::BoggleBoard(int width, BogglePieceGenerator& gen) : 
	_width(width), _board(allocateBoard(width))
{
}

BoggleBoard::Tile** BoggleBoard::allocateBoard(int width) const
{
	Tile** board;

	// For every row
	for (int row = 0; row < width; ++row)
	{
		// allocate row of length width
		board = new Tile*[width];
		// For every column in row
		for (int column = 0; column < width; ++column)
		{
			// allocate column of length width
			board[row] = new Tile[width];
		}
	}
	return board;
}


BoggleBoard::~BoggleBoard(void)
{
	// TODO: deallocate board
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
}

int BoggleBoard::getWidth()
{
	return _width;
}

/*
 * returns true if this word is found on the board
 */
bool BoggleBoard::isWordOnBoard(string word)
{
}

/*
bool BoggleBoard::isWordOnBoardAux(
	Vertex* vertex, string& word, int indexIntoWord)
{
	if (indexIntoWord == word.size())
	{
		return true;
	}
	// Go through all successors
	for (list<Vertex*>::iterator iter = vertex->Successors.begin();
		iter != vertex->Successors.end(); ++iter)
	{
		// If promising
		if ((*iter)->Letter == word[indexIntoWord] && !(*iter)->Visited)
		{
			// Try choice
			(*iter)->Visited = true;
			if (isWordOnBoardAux(*iter, word, indexIntoWord + 1))
			{
				return true;
			}

		}
	}

	return false;
}
*/

