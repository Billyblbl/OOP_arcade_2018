/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include "IGame.hpp"
#include <iostream>
#include <vector>

class Snake : public IGame
{
    public:

        struct position {
            float x;
            float y;
        };

        enum eDirecton{
            LEFT,
            RIGHT,
            UP,
            DOWN,
            NONE
        };

        Snake::Snake();

        virtual bool update();
        virtual void handleKey(int32_t key);
        virtual void setGraphic(IGraphic &handler);
        virtual void onEnable();
        virtual void onDisable();

        void place_food();
        bool checkPosFood();
        void collision_food();

        bool collision_wall();
        bool collision_himself();

        void movement(position &prev);

        void display();

    private:

        std::vector<position> _snake;
        position _food;
        position _map;
        eDirecton _dir;
        int _score;

        IGraphic *_screen;
};

#endif /* !SNAKE_HPP_ */

    /*
    Basic exemple (begining of a game):
    _ | : border of widow
    * : border in game
    o : tail snake
    x : head snake
    f : fruit

    x -> augmente sur la droite
    y -> augmente en decendant
    ____________________________
    |                           |
    |                           |
    |                           |
    |    ooox           f       |
    |                           |
    |                           |
    |                           |
    |***************************|
    |score : X__________________|
    */