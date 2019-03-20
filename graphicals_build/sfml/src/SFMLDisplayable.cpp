/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML Graphic implementation displayable object methods
*/

#include "SFMLDisplayable.hpp"

//temporary loader, only looks for sprites, no .entity file
SFMLDisplayable::SFMLDisplayable(const std::string &name):
	_name(name)
{
	Entity		&entity = EntityCache.get(name);
	for (auto &state : entity) {
		_keys.emplace_back(state.name);
		_states.emplace(state.name, state);
	}
	_currentState = _keys.begin();
	sf::Texture	&texture = TextureCache.get(entity.getSpritePath());
	setTexture(texture);
}

SFMLDisplayable::State::State(const Entity::State &data):
	name(data.name),
	rect(data.upLeft.x,
		 data.upLeft.y,
		 data.downRight.x - data.upLeft.x,
		 data.downRight.y - data.upLeft.y)
{}

void			SFMLDisplayable::setState(const std::string &stateName)
{
	State	&state = _states.at(stateName);
	_currentState = std::find(_keys.begin(), _keys.end(), stateName);
	setTextureRect(state.rect);
}

void			SFMLDisplayable::setState(std::size_t stateId)
{
	State	&state = _states.at(_keys[stateId]);
	_currentState = _keys.begin() + static_cast<long int>(stateId);
	setTextureRect(state.rect);
}

const std::string	&SFMLDisplayable::getState() const
{
	return *_currentState;
}

IDisplayable		&SFMLDisplayable::operator++()
{
	_currentState++;
	if (_currentState == _keys.end())
		_currentState = _keys.begin();
	State	&state = _states.at(*_currentState);
	setTextureRect(state.rect);
	return *this;
}

IDisplayable		&SFMLDisplayable::operator--()
{
	if (_currentState == _keys.begin())
		_currentState = _keys.end() - 1;
	else
		_currentState--;
	State	&state = _states.at(*_currentState);
	setTextureRect(state.rect);
	return *this;
}