/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDL2 fallback displayable state object mùethod
*/

#include "SDL2CharState.hpp"
#include "SDL2Graphic.hpp"

SDL2CharState::SDL2CharState(const std::string &dataName,
							 Vector2<int> &dataUpLeft,
							 Vector2<int> &dataDownRight,
							 Color dataColor,
							 Color dataBackColor,
							 char dataAscii):
	name(dataName)
{
	SDL_Color	color = {dataColor.r, dataColor.g, dataColor.b, dataColor.a};
	char	text[2] = {dataAscii, '\0'};
	characterSurface = TTF_RenderText_Solid(&SDL2Graphic::getFont(), text, color);
	if (!characterSurface)
		throw std::runtime_error(std::string(__func__) + " : " + SDL_GetError());
	(void)dataUpLeft;
	(void)dataDownRight;
	(void)dataBackColor;
}

SDL2CharState::~SDL2CharState()
{
	if (characterSurface)
		SDL_FreeSurface(characterSurface);
}

SDL2CharState &SDL2CharState::operator=(const SDL2CharState &toCopy)
{
	name = toCopy.name;
	// characterSurface = toCopy.characterSurface;
	characterSurface = SDL_ConvertSurface(toCopy.characterSurface, toCopy.characterSurface->format, SDL_SWSURFACE);
	// toCopy.characterSurface = nullptr;
	return *this;
}
