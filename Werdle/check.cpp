#include "check.h"
#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
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
	
	for (int character = 0; character < guess.length(); character++) {
		// add [ ] for each character
		result += openSquare + guess[character] + closeSquare;
	}
	return result;
}

void check::frequency()
{
	// remove duplicates 
	std::unordered_set<char> exists;

	for (const auto& letter : Answer) {
		if (exists.insert(letter).second) tempWord += letter;
	}
	// add characters to map
	for (int i = 0; i < tempWord.length(); i++) {
		answer_frequency.insert(pair<char, int>(tempWord[i], 0));
	}

	// add character count
	for (int characters = 0; characters < Answer.length(); characters++) {
		answer_frequency[Answer.at(characters)]++;
	}

}


