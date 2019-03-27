/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML Graphic implementation displayable object class
*/

#ifndef SFMLSPRITEDISPLAYABLE_HPP_
    #define SFMLSPRITEDISPLAYABLE_HPP_

	#include <string>
	#include <SFML/Graphics.hpp>
	#include "IDisplayable.hpp"
	#include "Cache.hpp"
	#include "Anima.hpp"
	#include "SFMLArcadeEntity.hpp"
	#include "SFMLSpriteState.hpp"

class SFMLSpriteDisplayable : public Anima<SFMLSpriteState>, public SFMLArcadeEntity {
	public:
		SFMLSpriteDisplayable(const std::string &name);
		~SFMLSpriteDisplayable() = default;

		class LoadableTexture {
			public:
			LoadableTexture(const std::string &path) {
				if (!_texture.loadFromFile(path))
					throw std::runtime_error("SFML texture load : " + path);
			}

			operator sf::Texture &()
			{
				return _texture;
			}

			private:
				sf::Texture	_texture;
		};

		class SFMLSpriteError : std::runtime_error {
			public:
			SFMLSpriteError(const std::string &what): std::runtime_error(what){}
		};

		void	onStateChange(const SFMLSpriteState &newState) override;

		const sf::Drawable		&getDrawable() const override;
		sf::Transformable		&getTransformable() override;
		sf::Vector2u			getDimensions() const override;

	protected:
	private:

		sf::Sprite						_sprite;

		static	Cache<LoadableTexture>	TextureCache;
};

#endif /* !SFMLSPRITEDISPLAYABLE_HPP_ */
