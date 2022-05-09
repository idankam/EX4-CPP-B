#include "Ambassador.hpp"

namespace coup {

    Ambassador::Ambassador(Game &game, const std::string &playerName) : Player{game, playerName} {}
    std::string Ambassador::role() const { return "Ambassador";}

    void Ambassador::transfer(const Player &player1, const Player &player2) {
        this->checkCanMove();
        this->checkNeedToCoup();
        this->_game.nextPlayerTurn();
    }
    void Ambassador::block(const Player &player) {}    
}