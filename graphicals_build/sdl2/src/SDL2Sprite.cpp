/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDL2 garphic dispalyable object methods
*/

#include "SDL2Sprite.hpp"

Cache<SDL2Sprite::LoadableTexture>	SDL2Sprite::TextureCache;

SDL2Sprite::SDL2Sprite(const std::string &name):
	Anima<SDL2State>(name)
{
	if (_spritePath == "undefined")
		throw SDL2Error("Can't build SDL surface without texture file");
	_texture = &TextureCache.get(_spritePath);
	setState(0);
}

SDL_Texture	&SDL2Sprite::getTexture()
{
	return *_texture;
}