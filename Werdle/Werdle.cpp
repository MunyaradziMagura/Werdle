#include <iostream>
using namespace std;
#include <cstdio>
#include "Dictionary.h"
#include "view.h"

int main()
{
    view view;
    int selection = 0;
    while(true) {
        view.Home();
        cin >> selection;
        // Play screen
        if (selection == 1) {
            cout << selection << endl;
        }
        // Statistics screen
        else if (selection == 2) {
            cout << selection << endl;
        }
        // Help screen
        else if (selection == 3) {
            view.Help();
        }
    }
    
}
