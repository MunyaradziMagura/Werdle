#pragma once
#include <string>
#include <map>
using namespace std;
class gameInstance
{
private:
	map<string, int> gameDetails;
	string dictionary_word;
	string game_guess;
public:
	// play game
	map<string, int> play(int sessionNumber);
	// delete gameDetails map
	void deleteGameDetails();
	string getGuess();
};

