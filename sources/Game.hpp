#ifndef GAME
#define GAME

#include "string"
#include "vector"
#include <iostream>

using namespace std;

namespace coup {
    class Game {

    private:

        vector<string> _players;
        size_t playerTurn = 0;

    public:
        
        vector<string> players();
        string turn();
        void nextPlayerTurn();
        string winner();
        void addPlayer(const string& playerName);
 
    };
}
#endif
