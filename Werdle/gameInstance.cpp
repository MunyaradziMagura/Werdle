#include "gameInstance.h"
#include "check.h"
#include <iostream>
#include <string>
using namespace std;
int gameInstance::play(int sessionNumber)
{
	cout << "PLAYING: " << sessionNumber << endl;
	check game; 
	dictionary_word = "speed";

	game.checkWord(dictionary_word, "speed");
	auto nutbar = game.getCheckWord();
	cout << nutbar << endl;
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
