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
	
	check game;
	Dictionary dictionary;
	dictionary_word = dictionary.getWord(sessionNumber);
	//cout << "PLAYING: " << sessionNumber << " || Word: " << dictionary.getWord(sessionNumber) << endl;
	game_guess = getGuess();
	for (auto itr = 0; itr < 6; itr++) {
		// make sure the guess is less than 6 characters 
		if (game_guess.size() == 5) {
			game.checkWord(dictionary_word, game_guess);
			previousGuesses.push_back(game.getCheckWord());
			previousWords();

			if (game_guess == dictionary_word) {
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
		game.wordDelete();
		game_guess = getGuess();
		// clear previous game result
		game.wordDelete();
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
	std::transform(game_guess.begin(), game_guess.end(), game_guess.begin(), ::tolower);
	return myGuess;
}

void gameInstance::previousWords()
{
	for (vector<string>::iterator it = previousGuesses.begin(); it != previousGuesses.end(); it++)
	{
		cout << *it << "\n";
	}
}
