/**
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description:
*/
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include "Lexicon.h"
using namespace std;


Lexicon::Lexicon(const std::string& lexFile)
{
	ifstream in(lexFile.c_str());

	string word;
	while (getline(in, word))
	{
		_words.insert(word);
	}
	in.close();
}

Lexicon::Status Lexicon::wordStatus(const string& word) const
{
	Status status = NOT_WORD;
	set<string>::const_iterator kiLow = _words.lower_bound(word);
	if (kiLow == _words.end())
	{
		status = NOT_WORD;
	}
	else if (*kiLow == word)
	{
		status = WORD;
	}
	else
	{
		const string& candidate = *kiLow;
		if (candidate.size() > word.size() &&
			candidate.substr(0, word.size()) == word)
		{
			status = WORD_PREFIX;
		}
		else
		{
			status = NOT_WORD;
		}
	}
	return status;

	/*
	// Assume word is NOT_WORD
	Status status = NOT_WORD;

	// - While the status is not WORD && there are still words
	//   left to check
	set<string>::const_iterator iter = _words.begin();
	while (status != WORD && iter != _words.end())
	{
		if (word == *iter)
		{
			status = WORD;
		}
		else if (isPrefix(word, *iter))
		{
			status = WORD_PREFIX;
		}
		++iter;
	}
	return status;
	*/
}

bool Lexicon::isPrefix(const std::string& prefix, 
	const std::string& word) const
{
	int index = 0;

	// Go through every character in prefix.
	// Break if any of the characters differ.

	// If the prefix is shorter than the word
	if (prefix.size() <= word.size())
	{
		// check to see if it is actually a prefix
		while (index < prefix.size() && 
			prefix[index] == word[index])
		{
			++index;
		}
	}
	// return true if prefix is a prefix of the word.
	return index >= prefix.size();
}


Lexicon::~Lexicon()
{
}

