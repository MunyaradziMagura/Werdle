#pragma once
#include <string>
using namespace std;
class view
{
private:
	string help = "\nGuess the WERDLE in six tries.\n\nEach guess must be a five-letter word. Hit the enter button to submit.\n\nExamples\n[A] P P L E\nThe letter A is in the correct position.\nD | E | A L T\nThe letter E is in the word but in the wrong position";
	string home = "\nWelcome to Werdle.\n\nSelect an option : \n1.Play a game.\n2.View statistic.\n3.View help.\n";
public:

	void Help();
	void Home();

};

