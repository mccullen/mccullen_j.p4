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
	_width(width), _board(allocateBoard(width, gen))
{
}

BoggleBoard::Tile** BoggleBoard::allocateBoard(int width,
	BogglePieceGenerator& gen) const
{
	Tile** board;
	// Allocate rows.
	board = new Tile*[width];


	// For every row
	for (int row = 0; row < width; ++row)
	{
		// allocate columns
		board[row] = new Tile[width];
		// For every column in row
		for (int column = 0; column < width; ++column)
		{
			// set the letter and visited properties
			board[row][column].Letter = gen.getNextChar();
			board[row][column].Visited = false;
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
	if (row < 0 || row >= _width ||
		column < 0 || column >= _width)
	{
		// TODO: throw exception
		cerr << "Exception thrown!\n";
	}
	return _board[row][column].Letter;
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
	resetVisitedStatusOfTilesToFalse();

	// TODO: finish this function...
}

void BoggleBoard::resetVisitedStatusOfTilesToFalse()
{
	for (int row = 0; row < _width; ++row)
	{
		for (int column = 0; column < _width; ++column)
		{
			_board[row][column].Visited = false;
		}
	}
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

