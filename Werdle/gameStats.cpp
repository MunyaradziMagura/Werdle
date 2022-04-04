#include "gameStats.h"
#include <string>
string gameStats::getGameStats()
{
	return string();
}

void gameStats::setPlayed(int played)
{
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
