/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** pacman
*/

#include <iostream>
#include <fstream>
#include <iostream>
#include <thread>
#include "pacman.hpp"


void Pacman::fillMap(std::string s)
{
    std::ifstream   file(s);
    std::string     buf;
    while (std::getline(file, buf, '\n'))
        _map.push_back(buf);
}

Pacman::Pacman():
    _screen(nullptr)
{
    _pacman.DIR = NONE;
    _pacman.x = 15;
    _pacman.y = 9;
    _powerUp = false;
    _life = 3;

    for (int i = 0; i < 4; i++)
        _ghost.push_back({8.0f + i, 8.0f + i, NONE, nullptr});
    _ghost[0].DIR = UP;
    _ghost[1].DIR = RIGHT;
    _ghost[2].DIR = DOWN;
    _ghost[3].DIR = LEFT;

    fillMap("./ressources/games/pacman/map/map.txt");
    _score = 0;
}

void Pacman::setGraphic(IGraphic &handler)
{
    if (_screen) {
        delete _pacman.disp;
        delete _wall;
        delete _pacBall;
        delete _pacTicTac;
        for (unsigned int i = 0; _ghost.size(); i++)
            delete _ghost[i].disp;
    }
    _screen = &handler;
    _pacman.disp = _screen->createDisplayable("./ressources/games/pacman/entity/pacman.entity");
    _ghost[0].disp = _screen->createDisplayable("./ressources/games/pacman/entity/ghost.entity");
    _ghost[1].disp = _screen->createDisplayable("./ressources/games/pacman/entity/ghost.entity");
    _ghost[2].disp = _screen->createDisplayable("./ressources/games/pacman/entity/ghost.entity");
    _ghost[3].disp = _screen->createDisplayable("./ressources/games/pacman/entity/ghost.entity");
    _wall = _screen->createDisplayable("./ressources/games/pacman/entity/wall.entity");
    _pacBall = _screen->createDisplayable("./ressources/games/pacman/entity/pacBall.entity");
    _pacTicTac = _screen->createDisplayable("./ressources/games/pacman/entity/pacTicTac.entity");}

void Pacman::onEnable()
{
    _screen->clear();
    _screen->setSize(19, 22);
}

void Pacman::onDisable()
{
}

void Pacman::handleKey(int32_t key)
{
    switch (key) {
        case arrowUp:
            _pacman.DIR = LEFT;
            break;
        case arrowRight:
            _pacman.DIR = DOWN;
            break;
        case arrowDown:
            _pacman.DIR = RIGHT;
            break;
        case arrowLeft:
            _pacman.DIR = UP;
            break;
        default:
            break;
    }
}

void Pacman::moovement(position current)
{
    (void)current;
    if ((_pacman.DIR == UP)
    && ((_map[_pacman.x][_pacman.y - 1] == ' ')
    || (_map[_pacman.x][_pacman.y - 1] == '.')
    || (_map[_pacman.x][_pacman.y - 1] == '0')))
        _pacman.y -= 1;
    else if ((_pacman.DIR == RIGHT)
    && ((_map[_pacman.x + 1][_pacman.y] == ' ')
    || (_map[_pacman.x + 1][_pacman.y] == '.')
    || (_map[_pacman.x + 1][_pacman.y] == '0')))
        _pacman.x += 1;
    else if ((_pacman.DIR == DOWN)
    && ((_map[_pacman.x][_pacman.y + 1] == ' ')
    || (_map[_pacman.x][_pacman.y + 1] == '.')
    || (_map[_pacman.x][_pacman.y + 1] == '0')))
        _pacman.y += 1;
    else if ((_pacman.DIR == LEFT)
    && ((_map[_pacman.x - 1][_pacman.y] == ' ')
    || (_map[_pacman.x - 1][_pacman.y] == '.')
    || (_map[_pacman.x - 1][_pacman.y] == '0')))
        _pacman.x -= 1;
}

void Pacman::resetPosition()
{
    _pacman.x = 15;
    _pacman.y = 9;
    _pacman.DIR = NONE;

    for (unsigned int i = 0; i < _ghost.size(); i++) {
        _ghost[i].x = 8 + i;
        _ghost[i].y = 7;
        _ghost[i].DIR = NONE;
    }
    _ghost[0].DIR = UP;
    _ghost[1].DIR = RIGHT;
    _ghost[2].DIR = DOWN;
    _ghost[3].DIR = LEFT;
}

void Pacman::ghostCollision()
{
    for (unsigned int i = 0; i < _ghost.size(); i++) {
        if ((_powerUp == true) && (_pacman.x + 1 == _ghost[i].x)
        && (_pacman.y == _ghost[i].y)) {
            _score += 200;
            _ghost[i].y = 7;
            _ghost[i].x = 10;
        }
        if ((_powerUp == false) && (_pacman.x + 1 == _ghost[i].x)
        && (_pacman.y == _ghost[i].y)) {
            _life -= 1;
            Pacman::resetPosition();
        }
    }
}

void Pacman::scoring()
{
    if (_map[_pacman.x][_pacman.y] == '.') {
        _score += 10;
        _map[_pacman.x][_pacman.y] = ' ';
    }
    if (_map[_pacman.x][_pacman.y] == '0') {
        _score += 100;
        _powerUp = true;
        _map[_pacman.x][_pacman.y] = ' ';
        _timePowerUp = std::chrono::nanoseconds(0);
    }
}

bool Pacman::wallCollision(position current)
{
    switch (current.DIR) {
        case UP :
            return (_map[current.y - 1][current.x] != '*');
            break;
        case RIGHT :
            return (_map[current.y][current.x + 1] != '*');
            break;
        case DOWN :
            return (_map[current.y + 1][current.x] != '*');
            break;
        case LEFT :
            return (_map[current.y - 1][current.x] != '*');
            break;
        default :
            return true;
            break;
    }
}

bool Pacman::moovementFav(position current, eDirection DIR)
{
    switch (DIR) {
        case UP :
            if (_map[current.y - 1][current.x] != '*') {
                current.DIR = UP;
                current.y -= 1;
                return true;
            } else
                return false;
            break;
        case RIGHT :
            if (_map[current.y][current.x + 1] != '*') {
                current.DIR = RIGHT;
                current.x += 1;
                return true;
            } else
                return false;
            break;
        case DOWN :
            if (_map[current.y + 1][current.x] != '*') {
                current.DIR = DOWN;
                current.y += 1;
                return true;
            } else
                return false;
            break;
        case LEFT :
            if (_map[current.y][current.x - 1] != '*') {
                current.DIR = LEFT;
                current.x -= 1;
                return true;
            } else
                return false;
            break;
        default :
            break;
    }
    return true;
}

void Pacman::anotherDir(position current)
{
    if ((_map[current.y - 1][current.x] != '*') && (current.DIR != DOWN)) {
        current.DIR = UP;
        current.y -= 1;
    } else if ((_map[current.y][current.x + 1] != '*') && (current.DIR != LEFT)){
        current.DIR = RIGHT;
        current.x += 1;
    } else if ((_map[current.y + 1][current.x] != '*') && (current.DIR != UP)) {
        current.DIR = DOWN;
        current.y += 1;
    } else {
        current.DIR = LEFT;
        current.x -= 1;
    }
}

void Pacman::continueDIR(position current)
{
    switch (current.DIR) {
        case UP :
            current.y -= 1;
            break;
        case RIGHT :
            current.x += 1;
            break;
        case DOWN :
            current.y += 1;
            break;
        case LEFT :
            current.x -= 1;
            break;
        default :
            break;
    }
}

void Pacman::ghostMoovement()
{
    if (Pacman::wallCollision(_ghost[0]) == false) {
        if (moovementFav(_ghost[0], UP) == false)
            Pacman::anotherDir(_ghost[0]);
    } else
        Pacman::continueDIR(_ghost[0]);
    if (Pacman::wallCollision(_ghost[1]) == false) {
        if (moovementFav(_ghost[1], RIGHT) == false)
            Pacman::anotherDir(_ghost[1]);
    } else
        Pacman::continueDIR(_ghost[1]);
    if (Pacman::wallCollision(_ghost[2]) == false) {
        if (moovementFav(_ghost[2], DOWN) == false)
            Pacman::anotherDir(_ghost[2]);
    } else
        Pacman::continueDIR(_ghost[2]);
    if (Pacman::wallCollision(_ghost[3]) == false) {
        if (moovementFav(_ghost[3], LEFT) == false)
            Pacman::anotherDir(_ghost[3]);
    } else
        Pacman::continueDIR(_ghost[3]);
}

void Pacman::printMap(std::string s, unsigned int y)
{
    for (unsigned int i = 0; s[i]; i++) {
        if (s[i] == '*')
            _screen->setEntity(i, y, *_wall);
        if (s[i] == '.')
            _screen->setEntity(i, y, *_pacBall);
        if (s[i] == '0')
            _screen->setEntity(i, y, *_pacTicTac);
    }
}

void Pacman::display()
{
    for (unsigned int i = 0; i < _map.size(); i++)
        Pacman::printMap(_map[i], i);
    for (unsigned int i = 0; i < _ghost.size(); i++)
        _screen->setEntity(_ghost[i].x, _ghost[i].y, *_ghost[i].disp);
    _screen->setEntity(_pacman.y, _pacman.x, *_pacman.disp);
    _screen->write(0, 22, "Score : ");
    _screen->write(9, 22, std::to_string(_score));
}

void Pacman::timePower(std::chrono::nanoseconds deltaT)
{
    if (_powerUp) {
        _timePowerUp += deltaT;
        if (_timePowerUp > std::chrono::nanoseconds(15000000000))
            _powerUp = false;
    }
}

bool Pacman::update(std::chrono::nanoseconds deltaT, std::chrono::seconds upTime)
{
    (void)upTime;
    Pacman::timePower(deltaT);
    if (_pacman.DIR != NONE) {
        Pacman::moovement(_pacman);
        Pacman::ghostMoovement();
        Pacman::scoring();
        Pacman::ghostCollision();
    }
    if (_life == 0)
        return false;
    std::this_thread::sleep_for(std::chrono::milliseconds(120));
    Pacman::display();
    return true;
}

extern "C" {
    IGame *CreateHandler()
    {
        return new Pacman;
    }
}
