#include "Contessa.hpp"
#include "Player.hpp"

namespace coup {
    Contessa::Contessa(Game &game, const string& playerName) : Player{game, playerName} {}
    string Contessa::role() const { return "Contessa"; }
    
    void Contessa::block(Player &player){
        if(!this->isAlive()){
            throw invalid_argument("player not in the game!");
        }
        if(player.role() != "Assassin"){
            throw invalid_argument("player is not Assassin!");
        }
        if(!player.isKill()){
            throw invalid_argument("player didnt kill!");
        }
        int deadPlayerID = player.getKilledPlayerID();
        this->_game.backToGame(deadPlayerID);
        Player *deadPlayer = this->_game.getPlayerByID(deadPlayerID);
        deadPlayer->setAlive();

        player.resetKillParameters();
    }
}