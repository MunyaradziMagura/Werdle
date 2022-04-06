#pragma once
#include <string>
#include <map>
using namespace std;
class gameStats
{
private:
	int played = 0;
	int win = 0;
	int winPercent = 0;
	int currentStreak = 0;
	int maxStreak = 0;
	map<string, int> guessDistribution{
			{"1", 0},
			{"2", 0},
			{"3", 0},
			{"4", 0},
			{"5", 0},
			{"6", 0},
	};
public:
	virtual string getGameStats();
	 void setPlayed();
	 void winCounter();
	 void setStreak(bool going);
	 void setGuessDistribution(map<string, int> guessDistributionMap);
};

