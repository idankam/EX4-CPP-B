#include "Captain.hpp"

namespace coup {
    Captain::Captain(Game &game, const string& playerName) :
            Player{game, playerName} {}

    void Captain::block(Player &player) {
        if(player.role() != "Captain"){
            throw invalid_argument("can't block!");   
        }
    }

    void Captain::steal(Player &player) {
        this->checkCanMove();
        this->checkNeedToCoup();
        this->_game.nextPlayerTurn();
    }
    string Captain::role() const { return "Captain"; }
}