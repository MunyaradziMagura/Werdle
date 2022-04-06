#include <iostream>
#include <string>
#include <memory>
#include "gameInstance.h"
#include "check.h"
#include "Dictionary.h"

using namespace std;
map<string, int> gameInstance::play(int sessionNumber)
{
	
	check game;
	Dictionary dictionary;
	dictionary_word = dictionary.getWord(sessionNumber);
	cout << "PLAYING: " << sessionNumber << "|| Word: " << dictionary.getWord(sessionNumber) << endl;
	game_guess = getGuess();
	for (auto itr = 0; itr < 6; itr++) {
		cout << itr << endl;
		// make sure the guess is less than 6 characters 
		if (game_guess.size() == 5) {
			game.checkWord(dictionary_word, game_guess);
			cout << game.getCheckWord() << endl;
			if (game_guess == dictionary_word) {
				// what text should outputted 
				switch (itr) {
				case 0:
					gameDetails.insert({ to_string(itr), 1 });
					cout << "Impossible!" << endl;
					break;
				case 1:
					gameDetails.insert({ to_string(itr), 1 });
					cout << "Amazing!" << endl;
					break;
				case 2:
					gameDetails.insert({ to_string(itr), 1 });
					cout << "Outstanding!" << endl;
					break;
				case 3:
					gameDetails.insert({ to_string(itr), 1 });
					cout << "Great!" << endl;
					break;
				case 4:
					gameDetails.insert({ to_string(itr), 1 });
					cout << "Nice one!" << endl;
					break;
				default:
					gameDetails.insert({ to_string(itr), 1 });
					cout << "You got there!" << endl;
					break;
				}
				break;
			}
		}else {
			itr -= 1;
			cout << "Enter a valid word length..." << endl;	
		}
		

		game_guess = getGuess();
		// clear previous game result
		game.wordDelete();
	}
	return gameDetails;
}

void gameInstance::deleteGameDetails()
{
	gameDetails.clear();
}

string gameInstance::getGuess()
{
	string myGuess;
	std::cout << "guess >";
	cin >> myGuess;
	return myGuess;
}
