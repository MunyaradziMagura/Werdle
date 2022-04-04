#pragma once
#include <string>
#include <map>
using namespace std;
class gameStats
{
private:
	int played;
	int win;
	int winPercent;
	int currentStreak;
	int maxStreak;
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
	 void setPlayed(int played);
	 void winPercentage(int wins);
	 void setStreak(bool going);
	 void setGuessDistribution(map<string, int> guessDistributionMap);
};

