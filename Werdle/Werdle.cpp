#include <iostream>
using namespace std;
#include <cstdio>
#include <memory>
#include "view.h"
#include "gameInstance.h"
#include "gameStats.h"
#include "Werdle.h"
int main()
{
    
    //view view;
    //gameInstance gameInstance;
    Werdle werdle;
    //gameStats gameStats;
    auto currentGame = std::make_shared<gameStats>();
    
    while(true) {
        std::unique_ptr<view> myView = std::make_unique<view>();
        auto instanceGame = std::make_shared<gameInstance>();
        myView->Home();
        cout << ">";
        cin >> werdle.selection;
        // Play screen
        if (werdle.selection == 1) {
            // begin game 
            werdle.gamestats = instanceGame->play(werdle.session);
            // game was lost
            if (werdle.gamestats.empty()) {
                currentGame->setStreak(false);
                currentGame->setStreak(false);
            }
            else {
                currentGame->setStreak(true);
                currentGame->winCounter();
            }
            // set guess distribution 
            currentGame->setGuessDistribution(werdle.gamestats);
            // update games played
            currentGame->setPlayed();
            // increase session
            werdle.session++;
            instanceGame->deleteGameDetails();
        }
        // Statistics screen
        else if (werdle.selection == 2) {
            cout << currentGame->getGameStats() << endl;
        }
        // Help screen
        else if (werdle.selection == 3) {
            myView->Help();
        }
    }  
}
