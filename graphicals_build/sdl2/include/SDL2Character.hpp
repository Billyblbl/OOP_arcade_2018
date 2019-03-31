/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDL2 fallback displayable entitiy class
*/

#ifndef SDL2CHARACTER_HPP_
    #define SDL2CHARACTER_HPP_

	#include <SDL2/SDL_image.h>
	#include "Anima.hpp"
	#include "Cache.hpp"
	#include "SDL2CharState.hpp"

class SDL2Character : public Anima<SDL2CharState>/*  , public SDL2Displayable   */{
	public:
		SDL2Character(const std::string &path);
		~SDL2Character();

		void	onStateChange(const SDL2CharState &state) override;

		SDL_Texture	&getTexture();

	protected:
	private:

		SDL_Texture	*_texture;

};

#endif /* !SDL2CHARACTER_HPP_ */
