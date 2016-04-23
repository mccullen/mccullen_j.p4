/**
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description:
*/

#include "BogglePieceGenerator.h"
#include "BoggleBoard.h"
#include "LCExceptions.h"
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
BoggleBoard::Tile** BoggleBoard::
	allocateAndCopy(BoggleBoard::Tile** board, int width) const
{
	Tile** copy = new Tile*[width];
	for (int row = 0; row < width; ++row)
	{
		copy[row] = new Tile[width];
		for (int column = 0; column < width; ++column)
		{
			copy[row][column] = board[row][column];
		}
	}
	return copy;
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
			board[row][column].Row = row;
			board[row][column].Column = column;
		}
	}
	return board;
}


void BoggleBoard::destroyBoard()
{
	for (int iRow = 0; iRow < _width; ++iRow)
	{
		delete[] _board[iRow];
	}
	delete[] _board;
}

BoggleBoard::BoggleBoard(const BoggleBoard& original) :
	_width(original._width), 
	_board(allocateAndCopy(original._board, original._width))
{
}

BoggleBoard& BoggleBoard::operator=(const BoggleBoard& rhs)
{
	if (this != &rhs)
	{
		destroyBoard();
		_width = rhs._width;
		_board = allocateAndCopy(rhs._board, rhs._width);
	}
	return *this;
}


/*
 * returns the character found on the board at this location
 */
char BoggleBoard::getLetter(int row,int column)
	throw (OutOfBoundsException)
{
	if (row < 0 || row >= _width ||
		column < 0 || column >= _width)
	{
		throw OutOfBoundsException();
	}
	return _board[row][column].Letter;
}

int BoggleBoard::getWidth() const
{
	return _width;
}

/*
 * returns true if this word is found on the board
 */
bool BoggleBoard::isWordOnBoard(string word)
{
	resetVisitedStatusOfTilesToFalse();

	int row = 0;
	bool isOnBoard = false;
	while (row < _width && !isOnBoard)
	{
		int column = 0;
		while (column < _width && !isOnBoard)
		{
			isOnBoard = 
				isWordOnBoardAux(word, _board[row][column],0);
			++column;
		}
		++row;
	}
	return isOnBoard;

}

bool BoggleBoard::isWordOnBoardAux(const std::string& word, 
	const Tile& tile,
	int indexIntoWord)
{
	if (indexIntoWord == word.size())
	{
		return true;
	}
	// Go through all successors
	for (int row = tile.Row - 1; row <= tile.Row + 1; ++row)
	{
		if (validRow(row, tile))
		{
			for (int column = tile.Column - 1;
				column <= tile.Column + 1; ++column)
			{
				if (validColumn(column, tile))
				{
					// If in range and promising
					if (!(row == tile.Row && column == tile.Column) &&
						promising(row, column, word, indexIntoWord))
					{
						// Try choice
						_board[row][column].Visited = true;
						if (isWordOnBoardAux(word,
							_board[row][column],
							indexIntoWord + 1))
						{
							return true;
						}
						_board[row][column].Visited = false;
					}
				}
			}
		}
	}
	return false;
}
bool BoggleBoard::validRow(int row, const Tile& tile) const
{
	return row >= 0 && row < _width && row <= tile.Row + 1;
}

bool BoggleBoard::validColumn(int column, const Tile& tile) const
{
	return column >= 0 && column < _width && column <= tile.Column + 1;
}

bool BoggleBoard::promising(int row, int column, 
	const std::string& word, int indexIntoWord) const
{
	return _board[row][column].Letter == word[indexIntoWord] &&
		_board[row][column].Visited == false;
}

bool BoggleBoard::inRange(int row, int column) const
{
	return row >= 0 && column >= 0 &&
		row < _width && column < _width;
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

BoggleBoard::~BoggleBoard(void)
{
	destroyBoard();
}
