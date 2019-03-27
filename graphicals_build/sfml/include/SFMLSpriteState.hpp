/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML sprite displayable state object
*/

#ifndef SFMLSPRITESTATE_HPP_
    #define SFMLSPRITESTATE_HPP_

	#include <string>
	#include <SFML/Graphics.hpp>
	#include "Types.hpp"

struct SFMLSpriteState {
	public:
		SFMLSpriteState() = default;
		SFMLSpriteState(const std::string &dataName,
					   Vector2<int> &dataUpLeft,
					   Vector2<int> &dataDownRight,
					   Color dataColor,
					   Color dataBackColor,
					   char dataAscii);

		SFMLSpriteState	&operator=(const SFMLSpriteState &toCopy);

		std::string	name;
		sf::IntRect	rect;

	protected:
	private:
};

#endif /* !SFMLSPRITESTATE_HPP_ */
