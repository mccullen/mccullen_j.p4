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
private:
	class Tile
	{
	public:
		char Letter;
		bool Visited;
		int Row;
		int Column;
	};

	int _width;
	Tile** _board;

	virtual Tile** allocateBoard(int width, 
		BogglePieceGenerator& gen) const;
	virtual void resetVisitedStatusOfTilesToFalse();
	virtual bool isWordOnBoardAux(const std::string& word,
		const Tile& tile, int indexIntoWord);
	virtual bool promising(int row, int column,
		const std::string& word, int indexIntoWord) const;
	virtual bool inRange(int row, int column) const;
	virtual bool validRow(int row, const Tile& tile) const;
	virtual bool validColumn(int column, const Tile& tile) const;
};

#endif
