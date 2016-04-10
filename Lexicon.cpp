/**
Name: Jeff McCullen and Emma Elliott
Date: April 10, 2016
Description:
*/
#include <string>
#include <vector>
#include <fstream>
#include "Lexicon.h"
using namespace std;


Lexicon::Lexicon(string lexFile)
{
	ifstream in(lexFile.c_str());

	string word;
	while (getline(in, word))
	{
		_words.push_back(word);
	}
	in.close();
}

Lexicon::Status Lexicon::wordStatus(string word)
{
	// Assume word is NOT_WORD
	Status status = NOT_WORD;

	// - While the status is not WORD && there are still words
	//   left to check
	list<string>::iterator iter = _words.begin();
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
}

bool Lexicon::isPrefix(const std::string& prefix, 
	const std::string& word)
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

