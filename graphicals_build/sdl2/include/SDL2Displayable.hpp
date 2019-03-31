/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDL2 displayable entity common behavior conecpt interface
*/

#ifndef SDL2DISPLAYABLE_HPP_
    #define SDL2DISPLAYABLE_HPP_

	#include <SDL2/SDL.h>

class SDL2Displayable {
	public:

		virtual ~SDL2Displayable();

		virtual SDL_Surface	&getSurface() = 0;

	protected:
	private:
};

#endif /* !SDL2DISPLAYABLE_HPP_ */
