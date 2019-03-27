/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML Sprite displayable state object methods
*/

#include "SFMLSpriteState.hpp"

SFMLSpriteState::SFMLSpriteState(const std::string &dataName,
							   Vector2<int> &dataUpLeft,
							   Vector2<int> &dataDownRight,
							   Color dataColor,
							   Color dataBackColor,
							   char dataAscii):
	name(dataName),
	rect(dataUpLeft.x,
		 dataUpLeft.y,
		 dataDownRight.x - dataUpLeft.x,
		 dataDownRight.y - dataUpLeft.y)
{
	(void)dataColor;
	(void)dataBackColor;
	(void)dataAscii;
}

SFMLSpriteState &SFMLSpriteState::operator=(const SFMLSpriteState &toCopy)
{
	name = toCopy.name;
	rect = toCopy.rect;
	return *this;
}
