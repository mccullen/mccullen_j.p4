/** 
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description: BoggleBoard class interface which represents
the physical boggle board.
*/
#ifndef BOGGLE_BOARD_H
#define BOGGLE_BOARD_H

#include "BogglePieceGenerator.h"
#include "LCExceptions.h"
#include <vector>
#include <utility>
#include <list>
#include <set>

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
	 *
	 * @param width The width of the board.
	 * @param gen A generator to generate random letters for 
	 * the board.
	 */
	BoggleBoard(int width, BogglePieceGenerator& gen);

	/**
	 * Create a copy of a BoggleBoard.
	 *
	 * @param original The BoggleBoard to copy.
	 */
	BoggleBoard(const BoggleBoard& original);

	/**
	 * Assign the BoggleBoard on the rhs to the BoggleBoard on the
	 * lhs.
	 *
	 * @param rhs The BoggleBoard on the right hand side.
	 * @return the newly assigned lhs BoggleBoard.
	 */
	BoggleBoard& operator=(const BoggleBoard& rhs);


	/*
	 * returns the character found on the board at this location
	 */
	char getLetter(int row,int column) 
		throw (OutOfBoundsException);
	/**
	 * Get the width of the board.
	 *
	 * @return The width of the board.
	 */
	int getWidth() const;

	/*
	 * returns true if this word is found on the board
	 */
	bool isWordOnBoard(string word);

	/**
	 * Destruct a BoggleBoard.
	 */
	virtual ~BoggleBoard(void);
private:
	// Define Tile class to hold information about the tiles
	// on the board.
	class Tile
	{
	public:
		char Letter;
		bool Visited;
		int Row;
		int Column;
	};

	// The width of the board.
	int _width;

	// The board of tiles.
	Tile** _board;

	/**
	 * Get an allocated board of a given width with random letters.
	 *
	 * @param width The width of the board to allocate.
	 * @param gen A generator for random letters.
	 * @return The allocated board.
	 */
	virtual Tile** allocateBoard(int width, 
		BogglePieceGenerator& gen) const;

	/**
	 * Reset every tile's visited status to false.
	 */
	virtual void resetVisitedStatusOfTilesToFalse();

	/**
	 * Recursive helper function for isWordOnBoard.
	 */
	virtual bool isWordOnBoardAux(const std::string& word,
		const Tile& tile, size_t indexIntoWord);

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
	virtual bool promising(int row, int column,
		const std::string& word, size_t indexIntoWord) const;

	/**
	 * Determine if the given row and column are in range.
	 *
	 * @param row The row to check.
	 * @param column The column to check.
	 * @return True if the row and column are in range.
	 */
	virtual bool inRange(int row, int column) const;

	/**
	 * Determin if a given row is valid for the tile.
	 *
	 * @param row The row to check.
	 * @param tile The tile.
	 * @return True if the row is valid.
	 */
	virtual bool validRow(int row, const Tile& tile) const;

	/**
	 * Determine if a given column is valid for the tile.
	 *
	 * @param column The column to check.
	 * @param tile The tile.
	 * @return True if the column is valid.
	 */
	virtual bool validColumn(int column, const Tile& tile) const;

	/**
	 * Get an allocated copy of the board.
	 *
	 * @param board The board that you are going to copy.
	 * @pardm width The width of the board you are going to copy.
	 * @return An allocated copy of board.
	 */
	virtual Tile** allocateAndCopy(Tile** board, int width) const;

	/**
	 * Destroy a board by deallocating all allocated memory.
	 */
	virtual void destroyBoard();

	/**
	 * Recursive helper function for isWordOnBoard() to recurse
	 * through successor nodes.
	 */
	virtual bool recurseThroughSuccessors(const std::string& word,
		const Tile& tile, size_t indexIntoWord);
};

#endif
