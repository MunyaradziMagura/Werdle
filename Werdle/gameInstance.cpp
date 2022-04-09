#include <iostream>
#include <string>
#include <memory>
#include <algorithm> 
#include "gameInstance.h"
#include "check.h"
#include "Dictionary.h"

using namespace std;
map<string, int> gameInstance::play(int sessionNumber)
{
	
	//get word from dictionary;
	std::unique_ptr<Dictionary> dictionary = std::make_unique<Dictionary>();
	dictionary_word = dictionary->getWord(sessionNumber);
	game_guess = getGuess();
	for (auto itr = 0; itr < 6; itr++) {
		auto game = std::make_shared<check>();
		// make sure the guess is less than 6 characters 
		if (game_guess.size() == 5) {
			game->checkWord(dictionary_word, game_guess);
			previousGuesses.push_back(game->getCheckWord());
			
			if (game_guess == dictionary_word) {
				previousWords();
				// what text should outputted 
				switch (itr) {
				case 0:
					gameDetails.insert({ to_string(itr + 1), 1 });
					cout << "Impossible!" << endl;
					break;
				case 1:
					gameDetails.insert({ to_string(itr + 1), 1 });
					cout << "Amazing!" << endl;
					break;
				case 2:
					gameDetails.insert({ to_string(itr + 1), 1 });
					cout << "Outstanding!" << endl;
					break;
				case 3:
					gameDetails.insert({ to_string(itr + 1), 1 });
					cout << "Great!" << endl;
					break;
				case 4:
					gameDetails.insert({ to_string(itr + 1), 1 });
					cout << "Nice one!" << endl;
					break;
				default:
					gameDetails.insert({ to_string(itr + 1), 1 });
					cout << "You got there!" << endl;
					break;
				}
				break;
			}
		}else {
			itr -= 1;
			cout << "Enter a valid word length..." << endl;	
		}
		if (itr < 5 ) {
			previousWords();
			game->wordDelete();
			game_guess = getGuess();
			// clear previous game result
			game->wordDelete();
		} else {
			break;
		}

	}
	if (gameDetails.empty()) {
		previousWords();
		cout << "\nCorrect answer: " << dictionary_word << "\n";

	}
	return gameDetails;
}

void gameInstance::deleteGameDetails()
{
	previousGuesses = {};
	gameDetails.clear();
}

string gameInstance::getGuess()
{
	std::cout << "guess >";
	cin >> myGuess;
	while (isLetter(myGuess) == false) {
		std::cout << "Enter valid characters a-z\nguess >";
		cin >> myGuess;
		isLetter(myGuess);
	}
	std::transform(myGuess.begin(), myGuess.end(), myGuess.begin(), ::tolower);
	return myGuess;
}
void gameInstance::previousWords()
{
	for (vector<string>::iterator it = previousGuesses.begin(); it != previousGuesses.end(); it++)
	{
		cout << *it << "\n";
	}
}

bool gameInstance::isLetter(const string checkguess)// return true if there are no non-alpha characters
{
	for (unsigned char c : checkguess) if (!std::isalpha(c)) return false;
	return true;
}
