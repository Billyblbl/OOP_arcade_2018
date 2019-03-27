/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** pacman
*/

#ifndef PACMAN_HPP_
    #define PACMAN_HPP_

#include "IGame.hpp"
#include <iostream>
#include <vector>
#include <chrono>

class Pacman : public IGame
{
    public:

        enum eDirection{
            LEFT,
            RIGHT,
            UP,
            DOWN,
            NONE
        };

        struct position {
            float x;
            float y;
            eDirection DIR;
            IDisplayable *disp;
        };

        Pacman::Pacman();

        virtual bool update(std::chrono::nanoseconds deltaT, std::chrono::seconds upTime);
        virtual void handleKey(int32_t key);
        virtual void setGraphic(IGraphic &handler);
        virtual void onEnable();
        virtual void onDisable();

        void display();

        void printMap(std::string s, int y);

        void timePower(std::chrono::nanoseconds deltaT);
        void fillMap(std::string s);
        void moovement(position current);
        bool wallCollision(position current);
        void ghostMoovement();
        bool moovementFav(position curren, eDirection DIR);
        void anotherDir(position current);
        void continueDIR(position current);
        void scoring();
        void ghostCollision();
        void resetPosition();

    private:

        position _pacman;
        bool _powerUp;
        std::chrono::nanoseconds _timePowerUp;
        int _life;

        std::vector<position> _ghost;

        IDisplayable *_wall;
        IDisplayable *_pacBall;
        IDisplayable *_pacTicTac;

        std::vector<std::string> _map;
        int _score;

        IGraphic *_screen;
};

#endif /* !PACMAN_HPP_ */
