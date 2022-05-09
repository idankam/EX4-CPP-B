#include "exception"
#include "Assassin.hpp"

namespace coup {

    Assassin::Assassin(Game &game, const string &playerName)
            : Player{game, playerName} {
        this->needToCoup = 3;
    }

    string Assassin::role() const { return "Assassin"; }

    void Assassin::coup(Player &player) {
        
        if(!this->isAlive() || !player.isAlive()){
            throw invalid_argument("player not in the game!");
        }

        this->checkCanMove();

        if (this->needToCoup > this->_numOfCoins) {
            throw invalid_argument("not enough coins!");   
        }
        
        if (this->_numOfCoins <= 6){
            this->_numOfCoins -= this->needToCoup;
            this->_game.removePlayer(&player);
            player.kill();
            this->_is_kill = true;
            this->_killed_player_ID = player.getID();
        }
        else{
            this->_numOfCoins -= 7;
            this->_game.removePlayer(&player);
        }
        
        // this->_game.nextPlayerTurn();
    }

}