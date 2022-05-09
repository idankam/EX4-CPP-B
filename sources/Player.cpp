#include "Player.hpp"
#include "Game.hpp"
#include "exception"

namespace coup {

    Player::Player(Game &game, const string& playerName)
            : _game(game), _name(playerName), _numOfCoins(0), _is_foreign_aid(false), _is_in_game(true), _is_kill(false), _player_ID(game.objectCount), _killed_player_ID(-1), _is_steal(false), _stole_from_ID(-1), _steal_coins(0) {
        this->_game.addPlayerName(playerName, this->_player_ID);
        this->_game.addPlayer(this);
        game.objectCount++;
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
        this->_is_foreign_aid = true;
        this->_game.nextPlayerTurn();
    }

    void Player::coup(Player &other_player) {
        this->checkCanMove();
        if (this->needToCoup > this->_numOfCoins) {
            throw invalid_argument( "You need more coins!");
        }
        this->_numOfCoins -= this->needToCoup;
        this->_game.removePlayer(&other_player);
        other_player._is_in_game = false;
        // this->_game.nextPlayerTurn();
    }

    void Player::checkCanMove() {
        if (this->_game.turnID() != this->_player_ID) {
            throw invalid_argument( "Wait to your turn!");
        }
        this->resetParametersFromLastRound();
        // if (this->_game.turn() != this->_name) {
        //     cout << this->_game.turn();
        //     cout << this->_name;
        //     throw invalid_argument( "Wait to your turn!");
        // }
    }

    void Player::checkNeedToCoup(){
        if(this->_numOfCoins >= 10){
            throw invalid_argument( "You must coup!");
        }
    }

    int Player::stolen() { 
        if (this->_numOfCoins >= 2){
            this->_numOfCoins -= 2;
            return 2;
        }
        else if(this->_numOfCoins == 1){
            this->_numOfCoins -= 1;
            return 1;
        }
        return 0;
    }

    void Player::cancelSteal(){
        this->_numOfCoins -= this->_steal_coins;
        Player *p = this->_game.getPlayerByID(this->_stole_from_ID);
        p->_numOfCoins += this->_steal_coins;
        
        this->_steal_coins = 0;
        this->_stole_from_ID = -1;
        this->_is_steal = false;
    }

    void Player::resetParametersFromLastRound(){
        _is_foreign_aid = false;
        _is_kill = false;
        _killed_player_ID = -1;
        _is_steal = false;
        _stole_from_ID = -1;
        _steal_coins = 0;
    }
}
