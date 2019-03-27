/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade graphic handler draw request object
*/

#include "SFMLGraphic.hpp"

SFMLGraphic::DrawRequest::DrawRequest(const sf::Drawable &_drawable,
									  sf::Transformable &_transformable,
									  sf::Vector2f &&_scale,
									  sf::Vector2f &&_position):
	drawable(&_drawable),
	transformable(&_transformable),
	scale(_scale),
	position(_position)
{}


void	SFMLGraphic::DrawRequest::draw(sf::RenderWindow &window)
{
	transformable->setScale(scale);
	transformable->setPosition(position);
	window.draw(*drawable);
}