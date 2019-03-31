/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDL2 Graphic handler class
*/

#ifndef SDL2GRAPHIC_HPP_
    #define SDL2GRAPHIC_HPP_

	#include <unordered_map>
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_ttf.h>
	#include "Types.hpp"
	#include "IGraphic.hpp"

class SDL2Graphic : public IGraphic {
	public:
		SDL2Graphic(unsigned width, unsigned height);
		~SDL2Graphic();

	void            setEntity(float x, float y, IDisplayable &entity) override;
	void            write(int x, int y, const std::string &text) override;
	void            setSize(int x, int y) override;
	bool            update() override;
	void            clear() override;
	IDisplayable    *createDisplayable(const std::string &path) override;
	bool            hasInput() override;
	int32_t         getInput() override;

	typedef	std::unordered_map<SDL_Keycode, int32_t>	Translations;


	static TTF_Font		&getFont();
	static SDL_Renderer	&getRenderer();

	protected:
	private:

	//will throw by design
	void	cancel(bool cancels[3], const std::string &func);
	void	cancel(bool cancel1, bool cancel2, bool cancel3, const std::string &func);

	bool				_continue;
	bool				_hasInput;
	bool				_majInput;

	static TTF_Font		*_font;

	SDL_Keycode		_input;

	SDL_Window			*_win;
	static SDL_Renderer	*_renderer;

	Vector2<unsigned>	_windowDimensions;
	Vector2<unsigned>	_boardDimensions;
	Vector2<float>		_cellDimensions;

	static const Translations	Translator;
	static const Translations	MajTranslator;

};

#endif /* !SDL2GRAPHIC_HPP_ */
