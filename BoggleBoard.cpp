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
BoggleBoard::BoggleBoard(int width, BogglePieceGenerator& gen)
{
	_width = width;

	// Add verticies
	for (int row = 0; row < width; ++row)
	{
		for (int column = 0; column < width; ++column)
		{
			Vertex* newVertex =
				new Vertex(row, column, gen.getNextChar());
			_graph.insert(newVertex);
		}
	}

	// Add successors for each vertex
	for (set<Vertex*>::iterator iter = _graph.begin();
		iter != _graph.end(); ++iter)
	{
		addSuccessors(*iter);

		/* 
		//Print successors
		cout << "Successors for vertex " << (*iter)->Letter
		     << ":\n";
		for (list<Vertex*>::iterator i = (*iter)->Successors.begin();
			i != (*iter)->Successors.end(); ++i)
		{
			cout << (*i)->Letter << endl;
		}
		*/
	}
}
// Add successors
void BoggleBoard::addSuccessors(Vertex* vertex)
{
	for (set<Vertex*>::iterator iter = _graph.begin();
		iter != _graph.end(); ++iter)
	{
		if (isAdj(*iter, vertex))
		{
			(vertex->Successors).push_back(*iter);
		}
	}
}

// is adj
bool BoggleBoard::isAdj(Vertex* v1, Vertex* v2)
{
	return 
		// Row is the same and column is one different
		(v1->Row == v2->Row && 
		(v1->Column == v2->Column - 1 || v1->Column == v2->Column + 1)) ||

		// Column is same and row is one different
		(v1->Column == v2->Column &&
		(v1->Row == v2->Row - 1 || v1->Row == v2->Row + 1)) ||

		// Row and column differ by 1
		((v1->Row == v2->Row - 1 || v1->Row == v2->Row + 1)
		
		&&
		 (v1->Column == v2->Column - 1 || v1->Column == v2->Column + 1));
}

/*
// Edge constructor
BoggleBoard::Edge::Edge(Vertex* start, Vertex* end) : 
	Start(start), End(end)
{
}

// Add vertex
void BoggleBoard::Graph::addVertex(Vertex* vertex)
{
	Vertices.insert(vertex);
}

// Add edge
void BoggleBoard::Graph::addEdge(Vertex* v1, Vertex* v2)
{
	Edge* edge = new Edge(v1, v2);
	Edges.insert(edge);
}
*/

// Vertex constructor
BoggleBoard::Vertex::Vertex(int row, int column, char letter) : 
	Row(row), Column(column),
	Letter(letter), Visited(false)
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
	set<Vertex*>::iterator iter = _graph.begin();
	while (iter != _graph.end() &&
		((*iter)->Row != row || (*iter)->Column != column))
	{
		++iter;
	}
	return (*iter)->Letter;
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
	for (set<Vertex*>::iterator iter = _graph.begin();
		iter != _graph.end(); ++iter)
	{
		if ((*iter)->Letter == word[0])
		{
			(*iter)->Visited = true;
			return isWordOnBoardAux(*iter, word, 1);
		}
	}
	reset();
	return false;
	
}

void BoggleBoard::reset()
{
	for (set<Vertex*>::iterator iter = _graph.begin();
		iter != _graph.end(); ++iter)
	{
		(*iter)->Visited = false;
	}
}

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

