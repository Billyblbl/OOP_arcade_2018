/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML Graphic implementation displayable object class
*/

#ifndef SFMLDISPLAYABLE_HPP_
    #define SFMLDISPLAYABLE_HPP_

	#include <string>
	#include <SFML/Graphics.hpp>
	#include "IDisplayable.hpp"
	#include "Cache.hpp"

class SFMLDisplayable : public sf::Sprite, public IDisplayable {
	public:
		SFMLDisplayable(const std::string &name);
		~SFMLDisplayable();

		class LoadableTexture : public sf::Texture {
			public:
			LoadableTexture(const std::string &path) {
				if (!loadFromFile(path))
					throw std::runtime_error("SFML texture load : " + path);
			}
		};

	protected:
	private:
		std::string	_name;
		std::string	_texturePath;


		static	Cache<LoadableTexture>	TextureCache;
};

#endif /* !SFMLDISPLAYABLE_HPP_ */
