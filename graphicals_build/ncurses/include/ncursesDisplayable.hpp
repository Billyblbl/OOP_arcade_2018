/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** ncurses displayable implementation
*/

#ifndef NCURSESDISPLAYABLE_HPP_
    #define NCURSESDISPLAYABLE_HPP_
#include "Anima.hpp"
#include "ncursesState.hpp"

class   ncurseDisplayable : public Anima<ncursesState> {
public:
    ncurseDisplayable(const std::string &path);
    ~ncurseDisplayable();

};

#endif /* !NCURSESDISPLAYABLE_HPP_ */
