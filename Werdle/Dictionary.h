#pragma once
#include <string>
class Dictionary {
public:
	static const int WORD_COUNT = 39;
	static const std::string words[];
	// get word from dictionary
	std::string getWord(int index);
};
