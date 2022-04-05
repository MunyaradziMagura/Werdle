#include "check.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;
void check::checkWord(string answer, string word)
{
	Answer = answer;
	Word = word;
	frequency(answer);
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
			// check if the character exsists in the dictionary
			if (answer_frequency.find(Word.at(character)) == answer_frequency.end()) {
				// character not found 
				result += Word[character];
			
			} else {
				// check if character can be added 
				if (answer_frequency.find(Word.at(character))->second > 0) {
					// check if character is in the right index
					if (Word.at(character) == Answer.at(character)) {
						result += openSquare + Word[character] + closeSquare;
						answer_frequency.find(Word.at(character))->second = answer_frequency.find(Word.at(character))->second - 1;
					}
					else {
						result += bar + Word[character] + bar;
						answer_frequency.find(Word.at(character))->second = answer_frequency.find(Word.at(character))->second - 1;
					}
				}
				else {
					result += Word[character];
				}
			}
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
		} else {
			answer_frequency[word.at(characters)] = answer_frequency[word.at(characters)] + 1;
		}
	}

}


