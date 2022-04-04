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
            gameInstance.play(werdle.session);

            // 



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
