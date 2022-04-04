#pragma once
#include <string>
#include <map>
using namespace std;
class gameStats
{
private:
	int played;
	int win;
	int currentStreak;
	int maxStreak;
	map<string, int> guessDistribution;
public:
	virtual string getGameStats();
	 void setPlayed(int played);
	 void setWin(int win);
	 void setCurrentStreak(int currentStreak);
	 void setMaxStreak(int maxStreak);
	 void setGuessDistribution(map<string, int> guessDistribution);
};

