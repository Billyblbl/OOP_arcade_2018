/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML text displayable entity state object
*/

#ifndef SFMLTEXTSTATE_HPP_
    #define SFMLTEXTSTATE_HPP_

	#include <string>
	#include <SFML/Graphics.hpp>
	#include "Types.hpp"

struct SFMLTextState {
	public:
	SFMLTextState() = default;
	SFMLTextState(const std::string &dataName,
				  Vector2<int> &dataUpLeft,
				  Vector2<int> &dataDownRight,
				  Color dataColor,
				  Color dataBackColor,
				  char dataAscii);

	SFMLTextState	&operator=(const SFMLTextState &toCopy);

	std::string			name;
	char				asciiImg;
	sf::Color			color;
};

#endif /* !SFMLTEXTSTATE_HPP_ */
