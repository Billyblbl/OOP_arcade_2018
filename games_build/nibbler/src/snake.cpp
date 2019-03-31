/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** snake
*/

#include "snake.hpp"
#include "IGraphic.hpp"
#include "IDisplayable.hpp"

#include <functional>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>

Snake::Snake()
{
    _snake.push_back({3,15});
    _snake.push_back({2,15});
    _snake.push_back({1,15});
    _snake.push_back({0,15});

    _food.x = 25;
    _food.y = 15;

    _map.x = 30;
    _map.y = 30;

    _dir = NONE;

    _score = 0;
}

bool Snake::checkPosFood()
{
    for (unsigned int i = 0; i < _snake.size(); i++) {
        if ((_snake[i].x == _food.x) && (_snake[i].y == _food.y))
            return false;
    }
    return true;
}

void Snake::place_food()
{
    int mapX = static_cast<int>(_map.x);
    int mapY = static_cast<int>(_map.y);

    while (Snake::checkPosFood() == false) {
        srand(time(0));
        _food.x = (rand() % mapX) + 1;
        _food.y = (rand() % mapY) + 1;
    }
}

void Snake::handleKey(int32_t key)
{
    switch (key) {
        case arrowUp:
            if (_dir != DOWN)
                _dir = UP;
            break;
        case arrowRight:
            if (_dir != LEFT)
                _dir = RIGHT;
            break;
        case arrowDown:
            if (_dir != UP)
                _dir = DOWN;
            break;
        case arrowLeft:
            if (_dir != RIGHT)
                _dir = LEFT;
            break;
        default:
            break;
    }
}

void Snake::movement(Snake::position &prev)
{
    position buf;

    for (unsigned int i = 1; i < _snake.size(); i++) {
            buf = _snake[i];
            _snake[i] = prev;
            prev = buf;
    }
}

void Snake::collision_food()
{
    unsigned int _end = _snake.size();

    if ((_snake[0].x == _food.x) && (_snake[0].y == _food.y)) {
        Snake::place_food();
        if (_snake[_end].x == (_snake[_end - 1].x - 1))
            _snake.push_back({_snake[_end].x + 1, _snake[_end].y});
        if (_snake[_end].x == (_snake[_end - 1].x + 1))
            _snake.push_back({_snake[_end].x - 1, _snake[_end].y});
        if (_snake[_end].x == (_snake[_end - 1].y - 1))
            _snake.push_back({_snake[_end].y - 1, _snake[_end].y});
        if (_snake[_end].x == (_snake[_end + 1].y - 1))
            _snake.push_back({_snake[_end].y + 1, _snake[_end].y});
    }
}

bool Snake::collision_wall()
{
    if ((_snake[0].x == -1) || (_snake[0].x == (_map.x + 1)))
        return false;
    else if ((_snake[0].y == -1) || (_snake[0].y == (_map.y + 1)))
        return false;
    else
        return true;
}

bool Snake::collision_himself()
{
    for (unsigned int i = 1; i < _snake.size(); i++) {
        if ((_snake[0].x == _snake[i].x)
        && (_snake[0].y == _snake[i].y))
            return false;
        else
            return true;
    }
    return (true);
}

void Snake::display()
{
    IDisplayable *snake_head = _screen->createDisplayable("./ressources/games/nibbler/entity/snakeHead.entity");
    std::vector<IDisplayable *> snake_tail;
    IDisplayable *fruit = _screen->createDisplayable("./ressources/games/nibbler/entity/fruit.entity");

    for (unsigned int i = 0; i < _snake.size() - 1; i++)
        snake_tail.push_back(_screen->createDisplayable("./ressources/games/nibbler/entity/snakeTail.entity"));
    _screen->write(0, _map.y + 2, "Score : ");
    _screen->write(9, _map.y + 2, std::to_string(_score));
    for (int i = 0; i < 30; i++)
        _screen->write(_map.x + 1, i, "*");

    _screen->setEntity(_food.x, _food.y, *fruit);
    _screen->setEntity(_snake[0].x, _snake[0].y, *snake_head);

    for (unsigned int i = 0; i < snake_tail.size(); i++)
        _screen->setEntity(_snake[i + 1].x, _snake[i + 1].y, *snake_tail[i]);
}

bool Snake::update(std::chrono::nanoseconds deltaT, std::chrono::seconds upTime)
{
    (void)deltaT;
    (void)upTime;
    position prev = _snake[0];

    if (_dir == NONE) {
        _score = _snake.size() - 4;
        Snake::display();
        return true;
    }
    switch (_dir) {
        case UP:
            _snake[0].y -= 1;
            Snake::movement(prev);
            break;
        case RIGHT:
            _snake[0].x += 1;
            Snake::movement(prev);
            break;
        case DOWN:
            _snake[0].y += 1;
            Snake::movement(prev);
            break;
        case LEFT:
            _snake[0].x -= 1;
            Snake::movement(prev);
            break;
        default:
            break;
    }
    Snake::collision_food();
    if (Snake::collision_wall() == false)
        return false;
    if (Snake::collision_himself() == false)
        return false;
    _score = _snake.size() - 4;
    Snake::display();
    return true;
}

void Snake::setGraphic(IGraphic &handler)
{
    _screen = &handler;
}

void Snake::onEnable()
{
    _screen->clear();
    _screen->setSize(_map.x, _map.y + 2);
}

void Snake::onDisable()
{
}