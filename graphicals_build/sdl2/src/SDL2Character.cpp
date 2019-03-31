/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDL2 Fallback displayable entity object
*/

#include "SDL2Character.hpp"
#include "SDL2Graphic.hpp"

SDL2Character::SDL2Character(const std::string &path):
	Anima<SDL2CharState>(path),
	_texture(nullptr)
{
	setState(0);
}

SDL2Character::~SDL2Character()
{
	if (_texture)
		SDL_DestroyTexture(_texture);
}

void	SDL2Character::onStateChange(const SDL2CharState &state)
{
	if (_texture)
		SDL_DestroyTexture(_texture);
	_texture = SDL_CreateTextureFromSurface(&SDL2Graphic::getRenderer(), state.characterSurface);
}

SDL_Texture	&SDL2Character::getTexture()
{
	return *_texture;
}
