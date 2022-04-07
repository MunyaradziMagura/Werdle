#pragma once
#include <string>
#include <map>
#include <vector>
using namespace std;

class check
{
private:
    vector<string> guessResults = {"","","","",""};
    vector<bool> guessCorrect = { true, true, true, true, true };
    map<char, int> answer_frequency;
    string Answer;
    string Word;
    string openSquare = "[";
    string closeSquare = "]";
    string bar = "|";
    string result = "";
    string tempWord = "";
    string correct(string guess);
    
    void findCorrect();
    void findIncorrect();
    void returnString();
public:
    void checkWord(string answer, string word);
    void wordDelete();
    string getCheckWord();
    void frequency();
};

