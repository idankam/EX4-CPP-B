#include "Ambassador.hpp"

namespace coup {

    Ambassador::Ambassador(Game &game, const std::string &playerName) : Player{game, playerName} {}
    std::string Ambassador::role() const { return "Ambassador";}

    void Ambassador::transfer(Player &player1, Player &player2) {

        if(!this->isAlive() || !player1.isAlive() || !player2.isAlive()){
            throw invalid_argument("player not in the game!");
        }
        this->checkCanMove();
        this->checkNeedToCoup();
        if(player1.coins() < 1){
            throw invalid_argument("player 1 doesn't have coins at all!");
        }
        else{
            player1.takeCoin();
            player2.addCoin();
        }
        this->_game.nextPlayerTurn();
    }
    void Ambassador::block(Player &player) {
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
}