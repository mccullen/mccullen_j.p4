/**
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description: BoggleBoard class implementation which represents
the physical boggle board.
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
 *
 * @param width The width of the board.
 * @param gen A generator to generate random letters for 
 * the board.
 */
BoggleBoard::BoggleBoard(int width, BogglePieceGenerator& gen) : 
	_width(width), _board(allocateBoard(width, gen))
{
}

/**
 * Get an allocated copy of the board.
 *
 * @param board The board that you are going to copy.
 * @pardm width The width of the board you are going to copy.
 * @return An allocated copy of board.
 */
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

/**
 * Get an allocated board of a given width with random letters.
 *
 * @param width The width of the board to allocate.
 * @param gen A generator for random letters.
 * @return The allocated board.
 */
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


/**
 * Destroy a board by deallocating all allocated memory.
 */
void BoggleBoard::destroyBoard()
{
	for (int iRow = 0; iRow < _width; ++iRow)
	{
		delete[] _board[iRow];
	}
	delete[] _board;
}

/**
 * Create a copy of a BoggleBoard.
 *
 * @param original The BoggleBoard to copy.
 */
BoggleBoard::BoggleBoard(const BoggleBoard& original) :
	_width(original._width), 
	_board(allocateAndCopy(original._board, original._width))
{
}

/**
 * Assign the BoggleBoard on the rhs to the BoggleBoard on the
 * lhs.
 *
 * @param rhs The BoggleBoard on the right hand side.
 * @return the newly assigned lhs BoggleBoard.
 */
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

/**
 * Get the width of the board.
 *
 * @return The width of the board.
 */
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

/**
 * Recursive helper function for isWordOnBoard.
 */
bool BoggleBoard::isWordOnBoardAux(const std::string& word, 
	const Tile& tile,
	size_t indexIntoWord)
{
	bool retVal = false;
	if (indexIntoWord == word.size())
	{
		retVal = true;
	}
	else
	{
		retVal = recurseThroughSuccessors(word, tile, indexIntoWord);

	}
	return retVal;
}

/**
 * Recursive helper function for isWordOnBoard() to recurse
 * through successor nodes.
 */
bool BoggleBoard::recurseThroughSuccessors(const std::string& word,
	const Tile& tile, size_t indexIntoWord)
{
	
	// Go through all successors
	bool retVal = false;
	int row = tile.Row - 1;
	while (row <= tile.Row + 1 && !retVal)
	{
		if (validRow(row, tile))
		{
			int column = tile.Column - 1;
			while (column <= tile.Column + 1 && !retVal)
			{
				if (validColumn(column, tile))
				{
					// If in range and promising
					if (!(row == tile.Row && 
						column == tile.Column) &&
						promising(row, column, 
							word, indexIntoWord))
					{
						// Try choice
						_board[row][column].Visited = true;
						retVal = isWordOnBoardAux(word,_board[row][column], indexIntoWord+1);
						_board[row][column].Visited = false;
					}
				}
				++column;
			}
		}
		++row;
	}
	return retVal;
}

/**
 * Determin if a given row is valid for the tile.
 *
 * @param row The row to check.
 * @param tile The tile.
 * @return True if the row is valid.
 */
bool BoggleBoard::validRow(int row, const Tile& tile) const
{
	return row >= 0 && row < _width && row <= tile.Row + 1;
}

/**
 * Determine if a given column is valid for the tile.
 *
 * @param column The column to check.
 * @param tile The tile.
 * @return True if the column is valid.
 */
bool BoggleBoard::validColumn(int column, const Tile& tile) const
{
	return column >= 0 && column < _width && column <= tile.Column + 1;
}

/**
 * Determine wheather traversing the tree at this node could
 * possibly lead to a valid word on the board.
 *
 * @param row The row of the node.
 * @param column The column of the node.
 * @param word The word you are checking.
 * @param indexIntoWord The index into the word.
 * @return True if the node is promising.
 */
bool BoggleBoard::promising(int row, int column, 
	const std::string& word, size_t indexIntoWord) const
{
	return _board[row][column].Letter == word[indexIntoWord] &&
		_board[row][column].Visited == false;
}

/**
 * Determine if the given row and column are in range.
 *
 * @param row The row to check.
 * @param column The column to check.
 * @return True if the row and column are in range.
 */
bool BoggleBoard::inRange(int row, int column) const
{
	return row >= 0 && column >= 0 &&
		row < _width && column < _width;
}

/**
 * Reset every tile's visited status to false.
 */
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

/**
 * Destruct a BoggleBoard.
 */
BoggleBoard::~BoggleBoard(void)
{
	destroyBoard();
}
