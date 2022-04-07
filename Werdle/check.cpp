#include "check.h"
#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <algorithm>
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
		frequency();
		// find letters which are correct and in the right index	
		findCorrect();
		// find letters which are correct and in the wrong index	
		findIncorrect();
		returnString();
	}
	return result;
}
// memory management
void check::wordDelete()
{
	result = "";
	guessCorrect = { true, true, true, true, true };
	guessResults = { "","","","","" };
	answer_frequency = {};
	tempWord = "";
}

void check::findCorrect()
{
	for (auto character = 0; character < Word.length(); character++) {
		if (Word.at(character) == Answer.at(character)) {
			guessResults.at(character) = openSquare + Word[character] + closeSquare;
			guessCorrect.at(character) = false;
			answer_frequency.find(Answer.at(character))->second--;
		}
		else {
			guessResults.at(character) += ' ';
			guessResults.at(character) += Word.at(character);
			guessResults.at(character) += ' ';
		}
	}
}

void check::findIncorrect()
{
	for (int character = 0; character < 5; character++) {
		if (guessCorrect.at(character) == true ) {
			for (int letter = 0; letter < 5; letter++) {
				if (answer_frequency.find(Answer.at(letter))->second > 0) {
					if (Word.at(character) == Answer.at(letter) && guessCorrect[letter] == true) {
						answer_frequency.find(Answer.at(letter))->second--;
						guessCorrect.at(character) = false;
						guessResults.at(character) = bar + Word[character] + bar;
					}
				}
			}
		}
	}
}

void check::returnString()
{
	for (vector<string>::iterator it = guessResults.begin(); it != guessResults.end(); it++)
	{
		result += *it;
	}
}

string check::correct(string guess)
{
	std::for_each(guess.begin(), guess.end(), [&](char letter) {
		result += openSquare + letter + closeSquare;
		});
	return result;
}

void check::frequency()
{
	// remove duplicates 
	std::for_each(Answer.begin(), Answer.end(), [&](char letter) {
		std::unordered_set<char> exists;
		if (exists.insert(letter).second) tempWord += letter;
	});
	
	// add characters to map
	std::for_each(tempWord.begin(), tempWord.end(), [&](char letter) {
		answer_frequency.insert(pair<char, int>(letter, 0));
		});

	// add character count
	std::for_each(Answer.begin(), Answer.end(), [&](char letter) {
		answer_frequency[letter]++;
		});

}


