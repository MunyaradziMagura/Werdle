#include <iostream>
using namespace std;
#include <cstdio>
#include "Dictionary.h"

class view{
public:
    void help() {
        printf("\nGuess the WERDLE in six tries.\n\nEach guess must be a five-letter word. Hit the enter button to submit.\n\nExamples\n[A] P P L E\nThe letter A is in the correct position.\nD | E | A L T\nThe letter E is in the word but in the wrong position");
    }
    void show() {
        printf("\nWelcome to Werdle.\n\nSelect an option :\n1. Play a game.\n2. View statistic.\n3. View help.\n");
    }
};

int main()
{
    view view;
    int selection = 0;
    view.show();
    cin >> selection;
    cout << selection << endl;
}
