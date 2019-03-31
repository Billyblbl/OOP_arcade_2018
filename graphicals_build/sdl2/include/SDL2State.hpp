/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDL2 graphic entity state struct
*/

#ifndef SDL2STATE_HPP_
    #define SDL2STATE_HPP_

	#include <string>
	#include <SDL2/SDL.h>
	#include "Types.hpp"

struct SDL2State {
	public:
		SDL2State() = default;
		SDL2State(const std::string &dataName,
				  Vector2<int> &dataUpLeft,
				  Vector2<int> &dataDownRight,
				  Color dataColor,
				  Color dataBackColor,
				  char dataAscii);

		SDL2State	&operator=(const SDL2State &toCopy);

		std::string	name;
		SDL_Rect	rect;

};

#endif /* !SDL2STATE_HPP_ */
