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

            for (auto const& pair : werdle.gamestats) {
                std::cout << "{" << pair.first << ": " << pair.second << "}\n";
            }


            gameStats.setPlayed(1);
            // increase session
            werdle.session++;
            gameInstance.deleteGameDetails();
            
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
