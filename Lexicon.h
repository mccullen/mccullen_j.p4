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

class Lexicon
{
public:

	enum Status{NOT_WORD, WORD, WORD_PREFIX};

	Lexicon(std::string lexFile);
	virtual ~Lexicon();

	Status wordStatus(std::string word);

private:
	virtual bool isPrefix(const std::string& prefix, 
		const std::string& word);
	std::list<std::string> _words;
};

#endif
