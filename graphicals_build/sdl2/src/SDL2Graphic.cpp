/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDL2 Graphic handler method
*/

#include <stdexcept>
#include "IGame.hpp"
#include "SDL2Graphic.hpp"
#include "SDL2Sprite.hpp"
#include "SDL2Character.hpp"
#include "SDL2Sprite.hpp"

extern "C" {
	IGraphic	*CreateHandler()
	{
		return new SDL2Graphic(1920, 1080);
	}
}

TTF_Font	*SDL2Graphic::_font = nullptr;

const SDL2Graphic::Translations	SDL2Graphic::Translator = {
	{SDLK_UP, IGame::arrowUp},
	{SDLK_DOWN, IGame::arrowDown},
	{SDLK_LEFT, IGame::arrowLeft},
	{SDLK_RIGHT, IGame::arrowRight},
	{SDLK_PAGEUP, IGame::pageUp},
	{SDLK_PAGEDOWN, IGame::pageDown},
	{SDLK_HOME, IGame::home},
	{SDLK_END, IGame::end},
	{SDLK_RETURN, '\n'},
	{SDLK_a, 'a'},
	{SDLK_b, 'b'},
	{SDLK_c, 'c'},
	{SDLK_d, 'd'},
	{SDLK_e, 'e'},
	{SDLK_f, 'f'},
	{SDLK_g, 'g'},
	{SDLK_h, 'h'},
	{SDLK_i, 'i'},
	{SDLK_j, 'j'},
	{SDLK_k, 'k'},
	{SDLK_l, 'l'},
	{SDLK_m, 'm'},
	{SDLK_n, 'n'},
	{SDLK_o, 'o'},
	{SDLK_p, 'p'},
	{SDLK_q, 'q'},
	{SDLK_r, 'r'},
	{SDLK_s, 's'},
	{SDLK_t, 't'},
	{SDLK_u, 'u'},
	{SDLK_v, 'v'},
	{SDLK_w, 'w'},
	{SDLK_x, 'x'},
	{SDLK_y, 'y'},
	{SDLK_z, 'z'}
};

const SDL2Graphic::Translations	SDL2Graphic::MajTranslator = {
	{SDLK_a, 'A'},
	{SDLK_b, 'B'},
	{SDLK_c, 'C'},
	{SDLK_e, 'D'},
	{SDLK_f, 'E'},
	{SDLK_g, 'F'},
	{SDLK_h, 'G'},
	{SDLK_i, 'H'},
	{SDLK_j, 'I'},
	{SDLK_k, 'J'},
	{SDLK_l, 'K'},
	{SDLK_m, 'L'},
	{SDLK_n, 'M'},
	{SDLK_o, 'N'},
	{SDLK_p, 'O'},
	{SDLK_q, 'P'},
	{SDLK_r, 'Q'},
	{SDLK_s, 'R'},
	{SDLK_t, 'S'},
	{SDLK_u, 'T'},
	{SDLK_v, 'U'},
	{SDLK_v, 'V'},
	{SDLK_w, 'W'},
	{SDLK_x, 'X'},
	{SDLK_y, 'Y'},
	{SDLK_z, 'Z'}
};

SDL_Renderer	*SDL2Graphic::_renderer = nullptr;

SDL2Graphic::SDL2Graphic(unsigned width, unsigned height):
	_continue(true),
	_hasInput(false),
	_majInput(false),
	_win(nullptr)
{
	bool	inits[3] = {0};
	if ((inits[2] = (SDL_Init(SDL_INIT_VIDEO) < 0))
		|| (inits[1] = (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != (IMG_INIT_JPG | IMG_INIT_PNG)))
		|| (inits[0] = (TTF_Init() < 0)))
		cancel(inits, __func__);
	if (!(_win = SDL_CreateWindow("Arcade", 0, 0,
							static_cast<int>(width),
							static_cast<int>(height),
							SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI))
		|| !(_renderer = SDL_CreateRenderer(_win, -1, SDL_RENDERER_ACCELERATED))
		|| !(_font = TTF_OpenFont("./ressources/libs/sdl2/fonts/arial.ttf", 20)))
		cancel(true, true, true, __func__);
}

SDL2Graphic::~SDL2Graphic()
{
	SDL_DestroyWindow(_win);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void	SDL2Graphic::setEntity(float x, float y, IDisplayable &entity)
{
	SDL2Sprite		*asSprite = dynamic_cast<SDL2Sprite *>(&entity);
	SDL2Character	*asChar = dynamic_cast<SDL2Character *>(&entity);
	SDL_Rect	target = {
		static_cast<int>(x * _cellDimensions.x),
		static_cast<int>(y * _cellDimensions.y),
		static_cast<int>(_cellDimensions.x),
		static_cast<int>(_cellDimensions.y)
	};
	SDL_RenderCopy(_renderer,
				   (asSprite ? &asSprite->getTexture() : &asChar->getTexture()),
				   (asSprite ? &asSprite->getStateData().rect : nullptr),
				   &target);
}

void	SDL2Graphic::write(int x, int y, const std::string &text)
{
	SDL_Color	white = {0xff, 0xff, 0xff, 0xff};
	SDL_Surface	*surfaceText = TTF_RenderText_Solid(_font, text.c_str(), white);
	if (!surfaceText)
		throw std::runtime_error(std::string(__func__) + " : " + TTF_GetError());
	SDL_Texture	*textureText = SDL_CreateTextureFromSurface(_renderer, surfaceText);
	if (!textureText)
		throw std::runtime_error(std::string(__func__) + " : " + SDL_GetError());
	SDL_Rect	target = {
		static_cast<int>(x * _cellDimensions.x * text.size()),
		static_cast<int>(y * _cellDimensions.y),
		static_cast<int>(_cellDimensions.x),
		static_cast<int>(_cellDimensions.y)
	};
	SDL_RenderCopy(_renderer, textureText, NULL, &target);
	SDL_DestroyTexture(textureText);
	SDL_FreeSurface(surfaceText);
}

void	SDL2Graphic::setSize(int x, int y)
{
	_boardDimensions.x = static_cast<unsigned>(x);
	_boardDimensions.y = static_cast<unsigned>(y);
	_cellDimensions.x = static_cast<float>(_windowDimensions.x / _boardDimensions.x);
	_cellDimensions.y = static_cast<float>(_windowDimensions.y / _boardDimensions.y);
}

bool	SDL2Graphic::update()
{
	// SDL_Surface	*zbeb = SDL_CreateRGBSurface(0, 10, 10, 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);
	// SDL_BlitScaled(zbeb,
	// 				nullptr,
	// 			   _surface,
	// 			   nullptr);
	// SDL_UpdateWindowSurface(_win);
	SDL_RenderPresent(_renderer);
	// SDL_FreeSurface(zbeb);
	return _continue;
}

void	SDL2Graphic::clear()
{
	SDL_RenderClear(_renderer);
}

IDisplayable    *SDL2Graphic::createDisplayable(const std::string &path)
{
	try {
		return new SDL2Sprite(path);
	} catch(const SDL2Sprite::SDL2Error& e) {
		return new SDL2Character(path);
	}
}

bool			SDL2Graphic::hasInput()
{
	bool	frameInput = false;
	SDL_Event	ev;
	while (SDL_PollEvent(&ev)) {
		if (ev.type == SDL_KEYDOWN) {
			frameInput = true;
			_input = ev.key.keysym.sym;
			_majInput = ev.key.keysym.mod & KMOD_LSHIFT;
		} else if (ev.type == SDL_KEYUP && ev.key.keysym.sym == _input)
			_hasInput = frameInput;
		else if (ev.type == SDL_QUIT)
			_continue = false;
	}
	return (_hasInput = (_hasInput || frameInput));
}

int32_t         SDL2Graphic::getInput()
{
	if (_majInput && MajTranslator.find(_input) != MajTranslator.end())
		return MajTranslator.at(_input);
	else if (Translator.find(_input) != Translator.end())
		return Translator.at(_input);
	else
		return 0;
}

TTF_Font		&SDL2Graphic::getFont()
{
	return *_font;
}

SDL_Renderer	&SDL2Graphic::getRenderer()
{
	return *_renderer;
}

void			SDL2Graphic::cancel(bool cancels[3], const std::string &func)
{
	std::function<void ()>	cancelers[] = {TTF_Quit, IMG_Quit, SDL_Quit};
	std::string	err(SDL_GetError());
	for (int i = 0; i < 3; i++) {
		if (cancels[i])
			cancelers[i]();
	}
	if (_win)
		SDL_DestroyWindow(_win);
	if (_renderer)
		SDL_DestroyRenderer(_renderer);
	throw std::runtime_error(func + " : " + err);
}

void			SDL2Graphic::cancel(bool cancel1, bool cancel2, bool cancel3, const std::string &func)
{
	bool	cancels[] = {cancel1, cancel2, cancel3};
	cancel(cancels, func);
}
