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
	_name(name)
{
	Entity		&entity = SFMLGraphic::EntityCache.get(name);
	if (entity.getSpritePath() == "undefined")
		throw SFMLSpriteError("Can't build Sprite Displayable without a texture");
	for (auto &state : entity) {
		_keys.emplace_back(state.name);
		_states.emplace(state.name, state);
	}
	sf::Texture	&texture = TextureCache.get(entity.getSpritePath());
	setTexture(texture);
	setState(0);
}

SFMLSpriteDisplayable::State::State(const Entity::State &data):
	name(data.name),
	rect(data.upLeft.x,
		 data.upLeft.y,
		 data.downRight.x - data.upLeft.x,
		 data.downRight.y - data.upLeft.y)
{}

void			SFMLSpriteDisplayable::setState(const std::string &stateName)
{
	State	&state = _states.at(stateName);
	_currentState = std::find(_keys.begin(), _keys.end(), stateName);
	setTextureRect(state.rect);
}

void			SFMLSpriteDisplayable::setState(std::size_t stateId)
{
	State	&state = _states.at(_keys[stateId]);
	_currentState = _keys.begin() + static_cast<long int>(stateId);
	setTextureRect(state.rect);
}

const std::string	&SFMLSpriteDisplayable::getState() const
{
	return *_currentState;
}

IDisplayable		&SFMLSpriteDisplayable::operator++()
{
	_currentState++;
	if (_currentState == _keys.end())
		_currentState = _keys.begin();
	State	&state = _states.at(*_currentState);
	setTextureRect(state.rect);
	return *this;
}

IDisplayable		&SFMLSpriteDisplayable::operator--()
{
	if (_currentState == _keys.begin())
		_currentState = _keys.end() - 1;
	else
		_currentState--;
	State	&state = _states.at(*_currentState);
	setTextureRect(state.rect);
	return *this;
}
