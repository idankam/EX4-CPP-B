#include "exception"
#include "Assassin.hpp"

namespace coup {

    Assassin::Assassin(Game &game, const string &playerName)
            : Player{game, playerName} {
        this->needToCoup = 3;
    }

    string Assassin::role() const { return "Assassin"; }

    void Assassin::coup(Player &player) {
        this->checkCanMove();
        this->checkNeedToCoup();
        if (this->needToCoup > this->_numOfCoins) {
            throw invalid_argument("not enough coins!");   
        }
        this->_game.nextPlayerTurn();
    }

    
}