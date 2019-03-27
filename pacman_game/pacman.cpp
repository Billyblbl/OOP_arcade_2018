/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** pacman
*/

#include <iostream>
#include "pacman.hpp"


void Pacman::fillMap(std::string s)
{
    for (int i = 0; i < 22; i++)
        _map.push_back;
    _map[0] = "*******************";
    _map[1] = "*........*........*";
    _map[2] = "*0**.***.*.***.**0*";
    _map[3] = "*.................*";
    _map[4] = "*.**.*.*****.*.**.*";
    _map[5] = "*....*...*...*....*";
    _map[6] = "****.*** * ***.****";
    _map[7] = "****.*** * ***.****";
    _map[8] = "   *.*       *.*";
    _map[9] = "   *.* ***** *.*";
    _map[10] = "   *.  *   *  .*";
    _map[11] = "   *.* ***** *.*";
    _map[12] = "   *.*       *.*";
    _map[13] = "****.* ***** *.****";
    _map[14] = "*........*........*";
    _map[15] = "*.**.***.*.***.**.*";
    _map[16] = "*0.*...........*.0*";
    _map[17] = "**.*.*.*****.*.*.**";
    _map[18] = "*....*...*...*....*";
    _map[19] = "*.******.*.******.*";
    _map[20] = "*.................*";
    _map[21] = "*******************";
}

Pacman::Pacman()
{
    _pacman.DIR = NONE;
    _pacman.x = 10;
    _pacman.y = 16;
    _pacman.disp = _screen->createDisplayable("pacman.txt");
    _powerUp = false;
    _life = 3;

    for (int i = 0; i < 4; i++) {
        _ghost.push_back;
        _ghost[i].x = 8 + i;
        _ghost[i].y = 8;
        _ghost[i].disp = _screen->createDisplayable("pacman.txt");
    }
    _ghost[0].DIR = UP;
    _ghost[1].DIR = RIGHT;
    _ghost[2].DIR = DOWN;
    _ghost[3].DIR = LEFT;

    IDisplayable *_wall = _screen->createDisplayable("wall.txt");
    IDisplayable *_pacBall = _screen->createDisplayable("pacBall.txt");
    IDisplayable *_pacTicTac = _screen->createDisplayable("pacTicTac.txt");

    fillMap("map.txt");
    _score = 0;
}

void Pacman::setGraphic(IGraphic &handler)
{
    _screen = &handler;
}

void Pacman::onEnable()
{
    _screen->clear();
    _screen->setSize(23, 20);
}

void Pacman::onDisable()
{
}

void Pacman::handleKey(int32_t key)
{
    switch (key) {
        case arrowUp:
            _pacman.DIR = UP;
            break;
        case arrowRight:
            _pacman.DIR = RIGHT;
            break;
        case arrowDown:
            _pacman.DIR = DOWN;
            break;
        case arrowLeft:
            _pacman.DIR = LEFT;
            break;
        default:
            break;
    }
}

void Pacman::moovement(position current)
{
    if ((current.DIR == UP)
    && (_map[current.y - 1][current.x] != '*'))
        current.y -= 1;
    else if ((current.DIR == RIGHT)
    && (_map[current.y][current.x + 1] != '*'))
        current.x += 1;
    else if ((current.DIR == DOWN)
    && (_map[current.y + 1][current.x] != '*'))
        current.y += 1;
    else
        current.y -= 1;
}

void Pacman::resetPosition()
{
    _pacman.x = 10;
    _pacman.y = 16;
    _pacman.DIR = NONE;

    for (int i = 0; i < _ghost.size(); i++) {
        _ghost[i].x = 8 + i;
        _ghost[i].y = 8;
        _ghost[i].DIR = NONE;
    }
}

void Pacman::ghostCollision()
{
    for (int i = 0; i < _ghost.size(); i++) {
        if ((_powerUp == true) && (_pacman.x == _ghost[i].x)
        && (_pacman.y == _ghost[i].y)) {
            _score += 200;
            _ghost[i].y = 8;
            _ghost[i].x = 10;
        }
        if ((_powerUp == false) && (_pacman.x == _ghost[i].x)
        && (_pacman.y == _ghost[i].y)) {
            _life -= 1;
            Pacman::resetPosition();
        }
    }
}

void Pacman::scoring()
{
    if (_map[_pacman.y][_pacman.x] == '.')
        _score += 10;
    if (_map[_pacman.y][_pacman.x] == '0') {
        _score += 100;
        _powerUp = true;
        _timePowerUp = std::chrono::nanoseconds(0);
    }
}

bool Pacman::wallCollision(position current)
{
    switch (current.DIR) {
        case UP :
            if (_map[current.y - 1][current.x] == '*')
                return false;
            else
                return true;
            break;
        case RIGHT :
            if (_map[current.y][current.x + 1] == '*')
                return false;
            else
                return true;
            break;
        case DOWN :
            if (_map[current.y + 1][current.x] == '*')
                return false;
            else
                return true;
            break;
        case LEFT :
            if (_map[current.y - 1][current.x] == '*')
                return false;
            else
                return true;
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
}

void Pacman::anotherDir(position current)
{
    if (_map[current.y - 1][current.x] != '*') {
        current.DIR = UP;
        current.y -= 1;
        return;
    } else if (_map[current.y][current.x + 1] != '*') {
        current.DIR = RIGHT;
        current.x += 1;
        return;
    } else if (_map[current.y + 1][current.x] != '*') {
        current.DIR = DOWN;
        current.y += 1;
        return;
    } else {
        current.DIR = LEFT;
        current.x -= 1;
        return;
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

void Pacman::printMap(std::string s, int y)
{
    for (int i = 0; s[i]; i++) {
        if (s[i] == '*')
            _screen->setEntity(y, i, *_wall);
        if (s[i] == '.')
            _screen->setEntity(y, i, *_pacBall);
        if (s[i] == '0')
            _screen->setEntity(y, i, *_pacTicTac);
    }
}

void Pacman::display()
{
    for (int i = 0; i < _map.size(); i++)
        Pacman::printMap(_map[i], i);
    for (int i = 0; i < _ghost.size(); i++)
        _screen->setEntity(_ghost[i].y, _ghost[i].x, *_ghost[i].disp);
    _screen->setEntity(_pacman.y, _pacman.x, *_pacman.disp);
}

void Pacman::timePower(std::chrono::nanoseconds deltaT)
{
    if (_powerUp) {
        _timePowerUp += deltaT;
        if (_timePowerUp > std::chrono::nanoseconds(5))
            _powerUp = false;
    }
}

bool Pacman::update(std::chrono::nanoseconds deltaT, std::chrono::seconds upTime)
{
    Pacman::timePower(deltaT);
    if (_pacman.DIR != NONE) {
        Pacman::moovement(_pacman);
        Pacman::ghostMoovement();
        Pacman::scoring();
        Pacman::ghostCollision();
    }
    if (_life == 0)
        return false;
    Pacman::display();
    return true;
}