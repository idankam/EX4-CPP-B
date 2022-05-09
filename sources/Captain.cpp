#include "Captain.hpp"

namespace coup {
    Captain::Captain(Game &game, const string& playerName) :
            Player{game, playerName} {}

    void Captain::block(Player &player) {
        if(!this->isAlive() || !player.isAlive()){
            throw invalid_argument("player not in the game!");
        }
        if(player.role() != "Captain"){
            throw invalid_argument("can't block!");   
        }
        if(!player.isSteal()){
            throw invalid_argument("player didn't steal!");
        }
        player.cancelSteal();
    }

    void Captain::steal(Player &player) {
        this->checkCanMove();
        this->checkNeedToCoup();

        int coins = player.stolen();
        this->_numOfCoins += coins;

        this->_is_steal = true;
        this->_stole_from_ID = player.getID();
        this->_steal_coins = coins;
        
        this->_game.nextPlayerTurn();
    }
    string Captain::role() const { return "Captain"; }
}