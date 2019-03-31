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

		class LoadableSurface {
			public:
			LoadableSurface(const std::string &path) {
				if (!(_surface = IMG_Load(path.c_str())))
					throw std::runtime_error("SDL2 texture load : " + path);
			}

			~LoadableSurface() {
				SDL_FreeSurface(_surface);
			}

			operator SDL_Surface &()
			{
				return *_surface;
			}

			private:
				SDL_Surface	*_surface;
		};

		class SDL2Error : public std::runtime_error {
			public:
			SDL2Error(const std::string &what): std::runtime_error(what) {}
		};

		SDL_Surface	&getSurface()/* override */;

	// void	onStateChange(const SDL2State &newState) override;

	protected:
	private:

		LoadableSurface					*_surface;

		static	Cache<LoadableSurface>	SurfaceCache;
};

#endif /* !SDL2SPRITE_HPP_ */
