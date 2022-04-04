#include "gameStats.h"
#include <string>
#include <iostream>
string gameStats::getGameStats()
{
	return "\n Played: " + to_string(played) + " Win%: " + to_string(winPercent) + "  Current streak: "+ to_string(currentStreak)+ " Max streak: " + to_string(maxStreak) +"\n \nGUESS DISTRIBUTION\n"+"1: " + to_string(guessDistribution["1"]) + "2: " + to_string(guessDistribution["2"]) + "3: " + to_string(guessDistribution["3"]) + "4: " + to_string(guessDistribution["4"]) + "5: " + to_string(guessDistribution["5"]) + "6: " + to_string(guessDistribution["6"]);
}

void gameStats::setPlayed(int game)
{
	played += game;
}

void gameStats::winPercentage(int wins)
{
	win += wins;
	// calculate win percentage
	winPercent = (played / win) * 100;
}

void gameStats::setStreak(bool going)
{
	if (going == true) {
		currentStreak += 1;
	}
	else {
		// update current streak
		if (maxStreak < currentStreak) {
			maxStreak = currentStreak;
		}
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
