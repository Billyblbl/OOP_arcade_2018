/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** ncurses state object
*/

#ifndef NCURSESSTATE_HPP_
    #define NCURSESSTATE_HPP_

    #include "Types.hpp"

struct ncursesState {
public:
    ncursesState() = default;
    ncursesState(const std::string &dataName,
					   Vector2<int> &dataUpLeft,
					   Vector2<int> &dataDownRight,
					   Color dataColor,
					   Color dataBackColor,
					   char dataAscii);
    ~ncursesState() = default;
    ncursesState &operator=(const ncursesState &tocopy);
    struct nColor {
    short   r;
    short   g;
    short   b;
    };
nColor   foreground;
nColor   background;
char    ascii;
};

#endif /* !NCURSESSTATE_HPP_ */
