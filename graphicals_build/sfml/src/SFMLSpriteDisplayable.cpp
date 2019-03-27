/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML Graphic implementation displayable object methods
*/

#include "SFMLSpriteDisplayable.hpp"
#include "SFMLGraphic.hpp"

Cache<SFMLSpriteDisplayable::LoadableTexture>	SFMLSpriteDisplayable::TextureCache;

SFMLSpriteDisplayable::SFMLSpriteDisplayable(const std::string &name):
	Anima<SFMLSpriteState>(name)
{
	if (_spritePath == "undefined")
		throw SFMLSpriteError("Can't build Sprite Displayable without a texture");
	sf::Texture	&texture = TextureCache.get(_spritePath);
	_sprite.setTexture(texture);
	setState(0);
}

void	SFMLSpriteDisplayable::onStateChange(const SFMLSpriteState &newState)
{
	_sprite.setTextureRect(newState.rect);
}

const sf::Drawable	&SFMLSpriteDisplayable::getDrawable() const
{
	return _sprite;
}

sf::Transformable		&SFMLSpriteDisplayable::getTransformable()
{
	return _sprite;
}

sf::Vector2u			SFMLSpriteDisplayable::getDimensions() const
{
	const sf::FloatRect	&rect = _sprite.getLocalBounds();
	return sf::Vector2u(rect.width, rect.height);
}