/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** ncurses State object method
*/

#include "ncursesState.hpp"

ncursesState::ncursesState(const std::string &dataName,
					   Vector2<int> &dataUpLeft,
					   Vector2<int> &dataDownRight,
					   Color dataColor,
					   Color dataBackColor,
					   char dataAscii):
    foreground{static_cast<short>(dataColor.r * 1000 / 256),
               static_cast<short>(dataColor.g * 1000 / 256),
               static_cast<short>(dataColor.b * 1000 / 256)
             },
    background{static_cast<short>(dataBackColor.r * 1000 / 256),
               static_cast<short>(dataBackColor.g * 1000 / 256),
               static_cast<short>(dataBackColor.b * 1000 / 256)
             },
    ascii(dataAscii)
{
    (void)dataName;
    (void)dataUpLeft;
    (void)dataDownRight;
}

ncursesState    &ncursesState::operator=(const ncursesState &tocopy) {
    this->ascii = tocopy.ascii;
    this->foreground = tocopy.foreground;
    this->background = tocopy.background;
    return *this;
}