/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** ncurses displayable implementation method
*/

#include "ncursesDisplayable.hpp"

ncurseDisplayable::ncurseDisplayable(const std::string &path):
    Anima<ncursesState>(path)
{}

void    onStateChange(const ncursesState &newState) {
    (void)newState;
}