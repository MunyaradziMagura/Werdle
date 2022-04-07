#include "gameStats.h"
#include <string>
#include <iostream>
string gameStats::getGameStats()
{
	// return game stats formated correctly 
	return "\nPlayed: " + to_string(played) 
		+ " Win%: " + to_string(winPercent) 
		+ "  Current streak: " + to_string(currentStreak) 
		+ " Max streak: " + to_string(maxStreak) 
		+"\n \nGUESS DISTRIBUTION\n"
		+"\n1: " + to_string(guessDistribution["1"]) 
		+ "\n2: " + to_string(guessDistribution["2"]) 
		+ "\n3: " + to_string(guessDistribution["3"]) 
		+ "\n4: " + to_string(guessDistribution["4"]) 
		+ "\n5: " + to_string(guessDistribution["5"]) 
		+ "\n6: " + to_string(guessDistribution["6"]);
}

void gameStats::setPlayed()
{
	played = played + 1;
	winPercent = 100 * win / played;
	// update current streak
	if (maxStreak < currentStreak) {
		maxStreak = currentStreak;
	}
}

void gameStats::winCounter()
{
	win = win + 1;
}

void gameStats::setStreak(bool going)
{
	
	if (going == true) {
		currentStreak = currentStreak + 1;
	}
	else {
		currentStreak = 0;
	}
}

void gameStats::setGuessDistribution(map<string, int> guessDistributionMap)
{
	for (auto distribution : guessDistributionMap)
	{
		guessDistribution[distribution.first] += distribution.second;
	}
}
