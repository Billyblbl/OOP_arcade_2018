/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML Graphic implementation displayable object methods
*/

#include "SFMLDisplayable.hpp"

//temporary loader, only looks for sprites, no .entity file
SFMLDisplayable::SFMLDisplayable(const std::string &name):
	_name(name),
	_texturePath("./ressources/sfml/sprite/" + name + ".png")
{
	sf::Texture	&texture = TextureCache.get(_texturePath);
	setTexture(texture);
}

SFMLDisplayable::~SFMLDisplayable()
{
	TextureCache.letGo(_texturePath);
}