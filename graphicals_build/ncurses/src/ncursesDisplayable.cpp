/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** ncurses displayable implementation method
*/

#include "ncursesDisplayable.hpp"

//debug
// #include <iostream>

ncurseDisplayable::ncurseDisplayable(const std::string &path):
    Anima<ncursesState>(path)
{
    setState(0);
}

ncurseDisplayable::~ncurseDisplayable() {}
