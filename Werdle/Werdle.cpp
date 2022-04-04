#include <iostream>
using namespace std;
#include <cstdio>
#include "view.h"
#include "gameInstance.h"
#include "gameStats.h"
#include "Werdle.h"
int main()
{
    
    view view;
    gameInstance gameInstance;
    Werdle werdle;
    
    while(true) {
        view.Home();
        cin >> werdle.selection;
        // Play screen
        if (werdle.selection == 1) {
            // begin game 
            werdle.gamestats = gameInstance.play(werdle.session);
            
            // print contents of game stats 
            for (auto elem : werdle.gamestats)
            {
                std::cout << elem.first << " " << elem.second << "\n";
            }

            // update game stats


            // increase session
            werdle.session++;
            
        }
        // Statistics screen
        else if (werdle.selection == 2) {
            cout << werdle.selection << endl;
        }
        // Help screen
        else if (werdle.selection == 3) {
            view.Help();
        }
    }  
}
