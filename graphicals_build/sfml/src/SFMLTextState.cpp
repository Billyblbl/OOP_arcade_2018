/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML text displayable entity state object methods
*/

#include "SFMLTextState.hpp"

SFMLTextState::SFMLTextState(const std::string &dataName,
							 Vector2<int> &dataUpLeft,
							 Vector2<int> &dataDownRight,
							 Color dataColor,
							 Color dataBackColor,
							 char dataAscii):
	name(dataName),
	asciiImg(dataAscii),
	color(sf::Color(dataColor.value))
{
	(void)dataUpLeft;
	(void)dataDownRight;
	(void)dataBackColor;
}

SFMLTextState	&SFMLTextState::operator=(const SFMLTextState &toCopy)
{
	name = toCopy.name;
	asciiImg = toCopy.asciiImg;
	color = toCopy.color;
	return *this;
}
