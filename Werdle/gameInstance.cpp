#include "gameInstance.h"
#include "check.h"
#include <iostream>
#include <string>
using namespace std;
int gameInstance::play(int sessionNumber)
{
	cout << "PLAYING: " << sessionNumber << endl;
	
	dictionary_word = "speed";
	check game;
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
					cout << "Impossible!" << endl;
					break;
				case 1:
					cout << "Amazing!" << endl;
					break;
				case 2:
					cout << "Outstanding!" << endl;
					break;
				case 3:
					cout << "Great!" << endl;
					break;
				case 4:
					cout << "Nice one!" << endl;
					break;
				default:
					cout << "You got there!" << endl;
					break;
				}
				break;
			}
		}else {
			itr -= 1;
			cout << "enter a valid word" << endl;	
		}
		game_guess = getGuess();
	}
	

	game.mapDelete();
	return 0;
}

void gameInstance::deleteGameDetails()
{
	gameDetails.clear();
}

string gameInstance::getWord(int index)
{
	return string();
}

string gameInstance::getGuess()
{
	string myGuess;
	std::cout << "guess >";
	cin >> myGuess;
	return myGuess;
}
