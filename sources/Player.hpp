#pragma once

#include "string"
#include "Game.hpp"

namespace coup {

    class Player {

    protected:
        int needToCoup = 7;
        
        std::string _name;
        int _numOfCoins;
        Game &_game;
        
        Player(Game &game, const std::string& playerName);
        void checkCanMove();


    public:

        
        virtual std::string role() const = 0;
        int coins() const;
        virtual void coup(Player &other_player);
        void income();
        void foreign_aid();
        void checkNeedToCoup();
    };
}
