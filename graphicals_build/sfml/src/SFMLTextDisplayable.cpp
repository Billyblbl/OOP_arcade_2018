/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Displayable text entity, fallback for unbuildable displayable sprite entity
*/

#include "SFMLTextDisplayable.hpp"
#include "SFMLGraphic.hpp"

SFMLTextDisplayable::SFMLTextDisplayable(const std::string &name):
	sf::Text("", SFMLGraphic::getFont())
{
	Entity	&entity = SFMLGraphic::EntityCache.get(name);
	for (auto &state : entity) {
		_keys.emplace_back(state.name);
		_states.emplace(state.name, state);
	}
	setState(0);
}

SFMLTextDisplayable::State::State(const Entity::State &data):
	name(data.name),
	asciiImg(data.ascii),
	color(sf::Color(data.color.value))
{}

void	SFMLTextDisplayable::setState(const std::string &stateName)
{
	State	&state = _states.at(stateName);
	_currentState = std::find(_keys.begin(), _keys.end(), stateName);
	setString(state.asciiImg);
	setFillColor(state.color);
}

void	SFMLTextDisplayable::setState(std::size_t stateId)
{
	State	&state = _states.at(_keys[stateId]);
	_currentState = _keys.begin() + static_cast<long int>(stateId);
	setString(state.asciiImg);
	setFillColor(state.color);
}

const std::string	&SFMLTextDisplayable::getState() const
{
	return *_currentState;
}

IDisplayable		&SFMLTextDisplayable::operator++()
{
	_currentState++;
	if (_currentState == _keys.end())
		_currentState = _keys.begin();
	State	&state = _states.at(*_currentState);
	setString(state.asciiImg);
	setFillColor(state.color);
	return *this;
}

IDisplayable		&SFMLTextDisplayable::operator--()
{
	if (_currentState == _keys.begin())
		_currentState = _keys.end() - 1;
	else
		_currentState--;
	State	&state = _states.at(*_currentState);
	setString(state.asciiImg);
	setFillColor(state.color);
	return *this;
}

