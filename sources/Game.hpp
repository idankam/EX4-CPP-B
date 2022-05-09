#ifndef GAME
#define GAME

#include <string>
#include <vector>
#include <iostream>
#include "Player.hpp"

using namespace std;

namespace coup {
    
    class Player;

    class Game {

    private:

        vector<Player*> _players_alive;
        vector<string> _players;
        vector<int> _players_ID;
        size_t playerTurn = 0;

    public:
        int objectCount = 0;
        vector<string> players();
        string turn();
        void nextPlayerTurn();
        string winner();
        void addPlayerName(const string& playerName, int playerID);
        void addPlayer(Player* player);
        void removePlayer(Player* player);
        int turnID(){return _players_ID[playerTurn];}
        void backToGame(int id);
        Player* getPlayerByID(int id);
    };
}
#endif
