#include <string>
#include <cctype>
#include "utility.h"

using namespace std;
/**
Make the given word all uppercase.

@param word The word to make uppercase.
*/
void makeUpperCase(std::string& word)
{
	for (size_t i = 0; i < word.size(); ++i)
	{
		word[i] = toupper(word[i]);
	}
}
