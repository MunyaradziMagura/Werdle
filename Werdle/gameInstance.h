#pragma once
#include <string>
#include <map>
using namespace std;
class gameInstance
{
private:
	map<int, int> gameDetails;
	string dictionary_word;
public:
	// play game
	int play(int sessionNumber);
	// get word from dictionary
	string getWord(int index);
	// delete gameDetails map
	void deleteGameDetails();
};

