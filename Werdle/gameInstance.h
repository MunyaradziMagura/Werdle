#pragma once
#include <string>
#include <map>
#include <vector>
using namespace std;
class gameInstance
{
private:
	map<string, int> gameDetails;
	vector<string> previousGuesses = {};
	string dictionary_word;
	string game_guess;
	string myGuess;
	int endState;
public:
	// play game
	map<string, int> play(int sessionNumber);
	// delete gameDetails map
	void deleteGameDetails();
	void previousWords();
	bool isLetter(string checkguess);
	string getGuess();
};

