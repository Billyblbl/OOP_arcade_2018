/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDL2 displayable sprite object texture subobject methods
*/

#include "SDL2Sprite.hpp"
#include "SDL2Graphic.hpp"

SDL2Sprite::LoadableTexture::LoadableTexture(const std::string &path)
{
	SDL_Surface	*textureSurface;
	if (!(textureSurface = IMG_Load(path.c_str())))
		throw std::runtime_error(std::string(__func__) + " : " + IMG_GetError());
	if (!(_texture = SDL_CreateTextureFromSurface(&SDL2Graphic::getRenderer(), textureSurface))) {
		SDL_FreeSurface(textureSurface);
		throw std::runtime_error(std::string(__func__) + " : " + SDL_GetError());
	}
	SDL_FreeSurface(textureSurface);
}

SDL2Sprite::LoadableTexture::~LoadableTexture()
{
	SDL_DestroyTexture(_texture);
}

SDL2Sprite::LoadableTexture::operator SDL_Texture &()
{
	return *_texture;
}
