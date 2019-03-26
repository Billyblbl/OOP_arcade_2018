/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Displayable text entity, fallback for unbuildable displayable sprite entity
*/

#include "SFMLTextDisplayable.hpp"
#include "SFMLGraphic.hpp"

SFMLAsciiData::SFMLAsciiData(const Entity::State &data):
	name(data.name),
	asciiImg(data.ascii),
	color(sf::Color(data.color.value))
{}

SFMLTextDisplayable::SFMLTextDisplayable(const std::string &name):
	Anima<SFMLAsciiData>(name),
	_text("", SFMLGraphic::getFont())
{
	setState(0);
}

void	SFMLTextDisplayable::onStateChange(const SFMLAsciiData &newState)
{
	_text.setString(newState.asciiImg);
	_text.setFillColor(newState.color);
}

//I should be able to define all that once and "alias" them all to one or smth

const sf::Drawable	&SFMLTextDisplayable::getDrawable() const
{
	return _text;
}

sf::Transformable		&SFMLTextDisplayable::getTransformable()
{
	return _text;
}

sf::Vector2u			SFMLTextDisplayable::getDimensions() const
{
	const sf::FloatRect	&rect = _text.getLocalBounds();
	return sf::Vector2u(rect.width, rect.height);
}