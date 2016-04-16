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
	class Vertex
	{
	public:
		Vertex(int row, int column, char letter);

		int Row;
		int Column;
		char Letter;
		bool Visited;
		std::list<Vertex*> Successors;
	};

	/*
	class Edge
	{
	public:
		Edge(Vertex* start, Vertex* end);

		Vertex* Start;
		Vertex* End;
	};

	class Graph
	{
	public:
		void addVertex(Vertex* vertex);
		void addEdge(Vertex* v1, Vertex* v2);

		std::set<Vertex*> Vertices;
		std::set<Edge*> Edges;
	};
	*/
	std::set<Vertex*>  _graph;
	int _width;

	virtual void addSuccessors(Vertex* vertex);
	virtual bool isAdj(Vertex* v1, Vertex* v2);
	virtual bool isWordOnBoardAux(Vertex* vertex, std::string& word,
		int indexIntoWord);
	virtual void reset();
};

#endif
