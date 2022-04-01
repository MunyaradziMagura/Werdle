#include "gameInstance.h"
#include <iostream>
#include <string>
using namespace std;
int gameInstance::play(int sessionNumber)
{
	cout << "PLAYING: " << sessionNumber << endl;
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
