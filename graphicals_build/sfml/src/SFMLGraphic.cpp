/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML implementation of IGraphic interface, methods
*/

#include "SFMLGraphic.hpp"
#include "SFMLSpriteDisplayable.hpp"
#include "SFMLTextDisplayable.hpp"

extern "C" {
	SFMLGraphic	LibObject(1920, 1080);
}

sf::Font		SFMLGraphic::_font;

SFMLGraphic::SFMLGraphic(unsigned width, unsigned height):
	_windowDimensions(width, height),
	_window(sf::VideoMode(width, height), "Arcade")
{
	if (!_font.loadFromFile("ressources/libs/sfml/fonts/arial.ttf"))
		throw std::runtime_error("SFML font loading failure : ressources/libs/sfml/fonts/arial.ttf");
}

void            SFMLGraphic::setEntity(float x, float y, IDisplayable &entity)
{
	sf::Drawable		&asDrawable = dynamic_cast<sf::Drawable &>(entity);
	sf::Transformable	&asTransformable = dynamic_cast<sf::Transformable &>(entity);
	asTransformable.setPosition({x * _cellDimensions.x, y * _cellDimensions.y});
	_window.draw(asDrawable);
}

void            SFMLGraphic::write(int x, int y, const std::string &text)
{
	sf::Text	textEntity(text, _font);
	textEntity.setScale({_cellDimensions.x, _cellDimensions.y * text.length()});
	textEntity.setPosition({x * _cellDimensions.x, y * _cellDimensions.y});
	_window.draw(textEntity);
}

void            SFMLGraphic::setSize(int x, int y)
{
	unsigned	ux = static_cast<unsigned>(x);
	unsigned	uy = static_cast<unsigned>(y);
	_cellDimensions = {static_cast<float>(_windowDimensions.x / ux),
					   static_cast<float>(_windowDimensions.y / uy)};
	_boardDimensions = {ux, uy};
}

void            SFMLGraphic::update()
{
	_window.display();
}

void            SFMLGraphic::clear()
{
	_window.clear();
}

IDisplayable    *SFMLGraphic::createDisplayable(const std::string &name)
{
	try {
		return new SFMLSpriteDisplayable(name);
	} catch(const SFMLSpriteDisplayable::SFMLSpriteError& e) {
		return new SFMLTextDisplayable(name);
	}
}

const sf::Font	&SFMLGraphic::getFont()
{
	return _font;
}