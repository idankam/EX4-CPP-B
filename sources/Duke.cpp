#include "Player.hpp"
#include "Game.hpp"
#include "Duke.hpp"
#include "string"


namespace coup {

    Duke::Duke(Game &game, const string &playerName) : Player{game, playerName} {}
    string Duke::role() const { return "Duke"; }
    void Duke::tax() {
        this->checkCanMove();
        this->checkNeedToCoup();
        this->_numOfCoins = this->_numOfCoins + 3;
        this->_game.nextPlayerTurn();
    }
    void Duke::block(Player &player) {}   

}
