/**
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description:
*/
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include "utility.h"
#include "Lexicon.h"

using namespace std;


/**
 * Construct a Lexicon from a file.
 *
 * @param lexFile The url path to the lexicon file.
 */
Lexicon::Lexicon(const std::string& lexFile)
{
	// Open the file.
	ifstream in(lexFile.c_str());

	// Insert all the words into the set.
	string word;
	while (getline(in, word))
	{
		makeLowerCase(word);
		_words.insert(word);
	}
	in.close();
}


/**
 * Get the status (NOT_WORD, WORD, or WORD_PREFIX) of a given
 * word.
 *
 * @param word The word to get the status of.
 * @return The status of the word.
 */
Lexicon::Status Lexicon::wordStatus(const string& word) const
{
	Status status = NOT_WORD;

	// Get an interator that points to the word or, if it is not in
	// the set, the word that comes after it.
	set<string>::const_iterator kiLow = _words.lower_bound(word);

	// If the iterator points to the end, the status is NOT_WORD
	if (kiLow == _words.end())
	{
		status = NOT_WORD;
	}
	// If the iterator points to the word, the status is WORD.
	else if (*kiLow == word)
	{
		status = WORD;
	}
	else
	{
		const string& candidate = *kiLow;
		// If the iterator points to a prefix, return WORD_PREFIX.
		if (candidate.size() > word.size() &&
			candidate.substr(0, word.size()) == word)
		{
			status = WORD_PREFIX;
		}
		// Else it is not a word.
		else
		{
			status = NOT_WORD;
		}
	}
	return status;
}

/**
 * Destruct the lexicon.
 */
Lexicon::~Lexicon()
{
}

