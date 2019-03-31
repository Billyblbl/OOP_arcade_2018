/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDL2 Fallback displayable state object
*/

#ifndef SDL2CHARSTATE_HPP_
    #define SDL2CHARSTATE_HPP_

	#include <string>
	#include <SDL2/SDL.h>
	#include "Types.hpp"

struct SDL2CharState {
	public:
		SDL2CharState() = default;
		SDL2CharState(const std::string &dataName,
					  Vector2<int> &dataUpLeft,
					  Vector2<int> &dataDownRight,
					  Color dataColor,
					  Color dataBackColor,
					  char dataAscii);

		~SDL2CharState();

		SDL2CharState	&operator=(const SDL2CharState &toCopy);

		std::string	name;
		SDL_Surface	*characterSurface;

};
#endif /* !SDL2CHARSTATE_HPP_ */
