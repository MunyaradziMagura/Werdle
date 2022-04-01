#include "check.h"
#include <iostream>
#include <string>
using namespace std;
void check::checkWord(string answer, string word)
{
	Answer = answer;
	Word = word;
}

map<bool, string> check::getCheckWord()
{	

	// if the word is a match
	if (Answer == Word) {
		Checked.insert(make_pair(true, correct(Word)));
		return Checked;
	}
	else {
		string result = "";
		for (int character = 0; character < Word.length(); character++) {
			// loop through answer
			for (int ans = character; ans < Answer.length(); ans++) {
				// if the char is in the right index 
				if (character == ans && Word[character] == Answer[ans]) {
					result += openSquare + Word[character] + closeSquare;
				}
				// the character is correct but not in the right place
				else if (character + 1 != ans && Word[character] == Answer[ans]) {
					result += bar + Word[character] + bar;
				}
			}
		}
		Checked.insert(make_pair(true, result));
		return Checked;
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

void check::mapDelete()
{
	Checked.clear();
}
