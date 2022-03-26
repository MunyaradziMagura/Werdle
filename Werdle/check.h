#pragma once
#include <string>
#include <map>
using namespace std;

class check
{
private:
    map<bool, string> Checked;
    string Answer;
    string Word;
    string openSquare = "[";
    string closeSquare = "]";
    string bar = "|";
public:
    void checkWord(string answer, string word);
    map<bool, string> getCheckWord();
    string correct(string guess);
    void mapDelete();
};

