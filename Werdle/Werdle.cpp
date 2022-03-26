#include <iostream>
using namespace std;
#include <cstdio>
#include "view.h"
#include "gameInstance.h"
int main()

{
    
    view view;
    gameInstance play;
    
    int selection = 0;
    int session = 0;
    while(true) {
        view.Home();
        cin >> selection;
        // Play screen
        if (selection == 1) {
            play.play(session);
            // increase session
            session++;
            
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
