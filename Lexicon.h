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

	enum Status{NOT_WORD, WORD, WORD_PREFIX};

	Lexicon(const std::string& lexFile);
	virtual ~Lexicon();

	Status wordStatus(const std::string& word) const;

private:
	std::set<std::string> _words;
};

#endif
