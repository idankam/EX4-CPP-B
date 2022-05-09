#ifndef GAME
#define GAME

#include <string>
#include <vector>
#include <iostream>
#include "Player.hpp"

using namespace std;

namespace coup {
    
    const int HIGH_BORDER_ASSASSIN = 6;
    const int PAYMENT_FOR_COUP = 7;
    const int MUST_COUP = 10;


    class Player;

    class Game {

    private:

        vector<Player*> _players_alive;
        vector<string> _players;
        vector<int> _players_ID;
        size_t playerTurn = 0;
        bool _is_game_started = false;

    public:
        int objectCount = 0;
        vector<string> players();
        string turn();
        void nextPlayerTurn();
        void firstPlayerTurn(){ this->playerTurn = 0;}
        string winner();
        void addPlayerName(const string& playerName, int playerID);
        void addPlayer(Player* player);
        void removePlayer(Player* player);
        int turnID(){return _players_ID[playerTurn];}
        void backToGame(int id);
        Player* getPlayerByID(int id);
        void gameStarted() {_is_game_started = true;}
        bool isGameStarted() {return _is_game_started;}
        int getLastInRoundPlayerID(){ return _players_ID[_players_ID.size()-1];}
    };
}
#endif
