#include "check.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;
void check::checkWord(string answer, string word)
{
	Answer = answer;
	Word = word;
}

string check::getCheckWord()
{	

	// if the word is a match
	if (Answer == Word) {
		return correct(Word);
	}
	else {
		//replace for loop with std::for_each()
		for (int character = 0; character < Word.length(); character++) {
			
			
		}
		return result;
	}
}

string check::correct(string guess)
{
	string result = "";
	for (int character = 0; character < guess.length(); character++) {
		// add [ ] for each character
		result += openSquare + guess[character] + closeSquare;
	}
	return result;
}

void check::wordDelete()
{
	result = "";
}

void check::frequency(string word)
{
	for (auto characters = 0; characters < word.length(); characters++) {
		auto it = answer_frequency.find(word.at(characters));
		// if the character could not be found
		if (it == answer_frequency.end()) {
			answer_frequency.insert(pair<char, int>(word.at(characters), 1));
		}
		else {
			answer_frequency[word.at(characters)] = answer_frequency[word.at(characters)] + 1;
		}
	}

}


