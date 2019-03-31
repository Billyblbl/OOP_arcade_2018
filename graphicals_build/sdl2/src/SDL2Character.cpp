/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDL2 Fallback displayable entity object
*/

#include "SDL2Character.hpp"

SDL2Character::SDL2Character(const std::string &path):
	Anima<SDL2CharState>(path)
{
	setState(0);
}

// SDL2Character::~SDL2Character()
// {
// }

SDL_Surface	&SDL2Character::getSurface()
{
	return *_surface;
}