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
		// get the frequency at which a word appers
		frequency();
		// find letters which are correct and in the right index	
		findCorrect();
		// find letters which are correct and in the wrong index	
		findIncorrect();
		// return the result of check 
		returnString();
	}
	return result;
}
// memory management
void check::wordDelete()
{
	// re-set all values
	result = "";
	guessCorrect = { true, true, true, true, true };
	guessResults = { "","","","","" };
	answer_frequency = {};
	tempWord = "";
}

void check::findCorrect()
{
	// check if the at index character is equal to the answers character at the same index 
	for (auto character = 0; character < Word.length(); character++) {
		if (Word.at(character) == Answer.at(character)) {
			guessResults.at(character) = openSquare + Word[character] + closeSquare;
			guessCorrect.at(character) = false;
			answer_frequency.find(Answer.at(character))->second--;
		}
		else {
			guessResults.at(character) += space + Word.at(character) + space;
		}
	}
}

void check::findIncorrect()
{
	// characters in guess 
	for (int character = 0; character < 5; character++) {
		// if the character at the guess hasnt been assigned |c| or [c]-- character is false
		if (guessCorrect.at(character) == true ) {
			// letters in answer 
			for (int letter = 0; letter < 5; letter++) {
				// check if the letter frequency is greater than 0, meaning the character is valid in the guess
				if (answer_frequency.find(Answer.at(letter))->second > 0) {
					// check if the characters index is equal to the answer index 
					if (Word.at(character) == Answer.at(letter) && guessCorrect[letter] == true) {
						// add bars & update the frequency & vector position of the character
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
	// get each value from the vector and add it to the result value
	for (vector<string>::iterator it = guessResults.begin(); it != guessResults.end(); it++)
	{
		result += *it;
	}
}

string check::correct(string guess)
{
	// if guess == answer, add squares to all letters
	std::for_each(guess.begin(), guess.end(), [&](char character) {
		result += openSquare + character + closeSquare; 
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


