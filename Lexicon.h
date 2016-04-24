/**
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description:
*/
#ifndef LEXICON_H
#define LEXICON_H

#include <string>
#include <vector>
#include <list>
#include <set>

class Lexicon
{
public:

	// The status of a given word.
	enum Status{NOT_WORD, WORD, WORD_PREFIX};

	/**
	 * Construct a Lexicon from a file.
	 *
	 * @param lexFile The url path to the lexicon file.
	 */
	Lexicon(const std::string& lexFile);

	/**
	 * Get the status (NOT_WORD, WORD, or WORD_PREFIX) of a given
	 * word.
	 *
	 * @param word The word to get the status of.
	 * @return The status of the word.
	 */
	Status wordStatus(const std::string& word) const;

	/**
	 * Destruct the lexicon.
	 */
	virtual ~Lexicon();

private:
	std::set<std::string> _words;

};

#endif
