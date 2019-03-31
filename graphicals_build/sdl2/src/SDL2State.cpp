/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDL2 displayable state object mùethod
*/

#include "SDL2State.hpp"

SDL2State::SDL2State(const std::string &dataName,
					 Vector2<int> &dataUpLeft,
					 Vector2<int> &dataDownRight,
					 Color dataColor,
					 Color dataBackColor,
					 char dataAscii):
	name(dataName),
	rect({dataUpLeft.x,
		  dataUpLeft.y,
		  dataDownRight.x - dataUpLeft.x,
		  dataDownRight.y - dataUpLeft.y})
{
	(void)dataColor;
	(void)dataBackColor;
	(void)dataAscii;
}

SDL2State &SDL2State::operator=(const SDL2State &toCopy)
{
	name = toCopy.name;
	rect = toCopy.rect;
	return *this;
}
