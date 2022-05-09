#pragma once

#include "string"
#include "Game.hpp"

namespace coup {

    class Game;
    // class Player;

    class Player {

    protected:

        int needToCoup = 7;
        
        std::string _name;
        int _numOfCoins;
        Game &_game;
        int _player_ID;

        bool _is_in_game;
        bool _is_kill;
        int _killed_player_ID;

        bool _is_foreign_aid;
        
        bool _is_steal;
        int _stole_from_ID;
        int _steal_coins;
        
        Player(Game &game, const std::string& playerName);
        void checkCanMove();


    public:

        // virtual ~Player() = default;
        virtual std::string role() const = 0;
        int coins() const;
        virtual void coup(Player &other_player);
        void income();
        void foreign_aid();
        void checkNeedToCoup() const;
        std::string getName() { return _name;}
        int getID() { return _player_ID;}
        bool isAlive() {return _is_in_game;}
        void setAlive() {_is_in_game = true;}
        int getKilledPlayerID() {return this->_killed_player_ID;}
        bool isForeignAid() {return _is_foreign_aid;}
        bool isKill() {return _is_kill;}
        void cancelForeignAid() {this->_numOfCoins -= 2;}
        int stolen();
        bool isSteal(){ return _is_steal;}
        void cancelSteal();
        void resetKillParameters(){
            this->_is_kill = false;
            this->_killed_player_ID = -1;
        }
        void kill(){this->_is_in_game = false;}
        void addCoin(){this->_numOfCoins++;}
        void takeCoin(){this->_numOfCoins--;}
        void resetParametersFromLastRound();
    };
}
