/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SDL2 displayable entitiy class
*/

#ifndef SDL2SPRITE_HPP_
    #define SDL2SPRITE_HPP_

	#include <SDL2/SDL_image.h>
	#include "Anima.hpp"
	#include "Cache.hpp"
	#include "SDL2State.hpp"
	#include "SDL2Displayable.hpp"

class SDL2Sprite : public Anima<SDL2State>/* , public SDL2Displayable */ {
	public:
		SDL2Sprite(const std::string &path);
		~SDL2Sprite() = default;

		class LoadableTexture {
			public:
			LoadableTexture(const std::string &path);

			~LoadableTexture();

			operator SDL_Texture &();

			private:
				SDL_Texture	*_texture;
		};

		class SDL2Error : public std::runtime_error {
			public:
			SDL2Error(const std::string &what): std::runtime_error(what) {}
		};

		SDL_Texture	&getTexture();

	// void	onStateChange(const SDL2State &newState) override;

	protected:
	private:

		LoadableTexture					*_texture;

		static	Cache<LoadableTexture>	TextureCache;
};

#endif /* !SDL2SPRITE_HPP_ */
