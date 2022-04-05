#pragma once
#include <string>
#include <map>
using namespace std;

class check
{
private:
    map<string, string> Checked;
    map<char, int> answer_frequency;
    string Answer;
    string Word;
    string openSquare = "[";
    string closeSquare = "]";
    string bar = "|";
    string correct(string guess);
    bool insertion = false;
    string result = "";
public:
    void checkWord(string answer, string word);
    string getCheckWord();
    void wordDelete();
    void frequency(string word);
};

