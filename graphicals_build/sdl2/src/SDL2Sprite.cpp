/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDL2 garphic dispalyable object methods
*/

#include "SDL2Sprite.hpp"

Cache<SDL2Sprite::LoadableSurface>	SDL2Sprite::SurfaceCache;

SDL2Sprite::SDL2Sprite(const std::string &name):
	Anima<SDL2State>(name)
{
	if (_spritePath == "undefined")
		throw SDL2Error("Can't build SDL surface without texture file");
	_surface = &SurfaceCache.get(_spritePath);
	setState(0);
}

SDL_Surface	&SDL2Sprite::getSurface()
{
	return *_surface;
}