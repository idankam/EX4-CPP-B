#include "Player.hpp"
#include "Game.hpp"
#include "exception"

namespace coup {

    Player::Player(Game &game, const std::string& playerName)
            : _game(game), _name(playerName), _numOfCoins(0) {
        this->_game.addPlayer(playerName);
    }

    int Player::coins() const {
        return this->_numOfCoins;
    }

    void Player::income() {
        this->checkCanMove();
        this->checkNeedToCoup();
        ++this->_numOfCoins;
        this->_game.nextPlayerTurn();
    }

    void Player::foreign_aid() {
        this->checkCanMove();
        this->checkNeedToCoup();
        this->_numOfCoins = 2+this->_numOfCoins;
        this->_game.nextPlayerTurn();
    }

    void Player::coup(Player &other_player) {
        this->checkCanMove();
        if (this->needToCoup > this->_numOfCoins) {
            throw invalid_argument( "You need more coins!");
        }
        this->_numOfCoins -= this->needToCoup;
        this->_game.nextPlayerTurn();
    }

    void Player::checkCanMove() {
        if (this->_game.turn() != this->_name) {
            cout << this->_game.turn();
            cout << this->_name;
            throw invalid_argument( "Wait to your turn!");
        }
    }

    void Player::checkNeedToCoup(){
        if(this->_numOfCoins >= 10){
            throw invalid_argument( "You must coup!");
        }
    }
}
