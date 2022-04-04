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
    gameStats gameStats;
    while(true) {
        view.Home();
        cin >> werdle.selection;
        // Play screen
        if (werdle.selection == 1) {
            // begin game 
            werdle.gamestats = gameInstance.play(werdle.session);

            // the game has been lost
            if (werdle.gamestats.empty()) {
                gameStats.setStreak(false);
                gameStats.winPercentage(0);
            } else {
                // the game has been won

            }

            gameStats.setPlayed(1);
            // increase session
            werdle.session++;
            
        }
        // Statistics screen
        else if (werdle.selection == 2) {
            cout << gameStats.getGameStats() << endl;
        }
        // Help screen
        else if (werdle.selection == 3) {
            view.Help();
        }
    }  
}
