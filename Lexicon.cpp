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
}

Lexicon::~Lexicon()
{
}

