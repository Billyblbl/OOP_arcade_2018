/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Animation capable displayable entity abstract template
*/

#ifndef ANIMA_HPP_
    #define ANIMA_HPP_

	#include <string>
	#include <unordered_map>
	#include <vector>
	#include <fstream>
	#include <sstream>
	#include <algorithm>
	#include "IDisplayable.hpp"
	#include "Types.hpp"

	#include <iostream>

template<class State>
class Anima : public IDisplayable {
	public:

		Anima(const std::string &path);
		virtual ~Anima() = default;

		class StateData {
			public:
			StateData() = default;
			StateData(const std::string &format);
			operator State &();

			std::string		name;
			Vector2<int>	upLeft;
			Vector2<int>	downRight;
			Color			color;
			Color			backColor;
			char			ascii;

			private:
			State			_buf;
		};

		void				setState(const std::string &stateName) override final;
		void				setState(std::size_t stateId) override final;
		const std::string	&getState() const override final;

		IDisplayable		&operator++() override final;
		IDisplayable		&operator--() override final;


		typedef std::vector<std::string>				KeyList;
		typedef	std::unordered_map<std::string, State>	StateMap;

		const State			&getStateData() const;

	protected:
		virtual void		onStateChange(const State &newState);
		std::string			_spritePath;
	private:

		std::string					_path;
		KeyList						_keys;
		StateMap					_states;
		KeyList::iterator			_currentStateName;
		typename StateMap::iterator	_currentState;

};

template<class State>
Anima<State>::Anima(const std::string &path):
	_spritePath(""),
	_path(path)
{
	std::ifstream	file(path);
	if (!file.is_open())
		throw std::runtime_error(std::string(__func__) + "Can't open entity file : " + path);
	std::string		buf;
	while (std::getline(file, buf, '\n')) {
		if (buf.length() == 0 || buf[0] == '#')
			continue;
		if (_spritePath.size() == 0)
			_spritePath = buf;
		else {
			StateData	data(buf);
			_keys.emplace_back(data.name);
			_states[data.name] = data;
		}
	}
	_currentState = _states.begin();
}

template<class State>
Anima<State>::StateData::StateData(const std::string &format)
{
	std::stringstream			stream(format);
	std::string					buf;
	std::vector<std::string>	split;
	while(std::getline(stream, buf, ':'))
		split.emplace_back(buf);
	if (split.size() != 6)
		throw std::runtime_error(std::string(__func__) + " parse error : " + format);
	name = split[0];
	upLeft = split[1];
	downRight = split[2];
	color.value = static_cast<unsigned>(std::stoul(split[3], nullptr, 16));
	backColor.value = static_cast<unsigned>(std::stoul(split[4], nullptr, 16));
	ascii = split[5][0];
	_buf = State(name, upLeft, downRight, color, backColor, ascii);
}


template<class State>
Anima<State>::StateData::operator State &()
{
	return _buf;
}


template<class State>
void	Anima<State>::setState(const std::string &stateName)
{
	_currentState = _states.find(stateName);
	if (_currentState == _states.end())
		throw std::runtime_error(std::string(__func__) + " : unknown state : " + stateName);
	_currentStateName = std::find(_keys.begin(), _keys.end(), stateName);
	onStateChange(_currentState->second);
}

template<class State>
void	Anima<State>::setState(std::size_t stateId)
{
	if (stateId >= _keys.size())
		throw std::runtime_error(std::string(__func__) + " : unknown state n°" + std::to_string(stateId));
	setState(_keys[stateId]);
}

template<class State>
const std::string	&Anima<State>::getState() const
{
	return *_currentStateName;
}

template<class State>
IDisplayable	&Anima<State>::operator++()
{
	_currentStateName++;
	if (_currentStateName == _keys.end())
		_currentStateName = _keys.begin();
	_currentState = _states.find(*_currentStateName);
	onStateChange(_currentState->second);
	return *this;
}

template<class State>
IDisplayable	&Anima<State>::operator--()
{
	if (_currentStateName == _keys.begin())
		_currentStateName = _keys.end() - 1;
	else
		_currentStateName--;
	_currentState = _states.find(*_currentStateName);
	onStateChange(_currentState->second);
	return *this;
}

template<class State>
const State			&Anima<State>::getStateData() const
{
	return _currentState->second;
}

template<class State>
void				Anima<State>::onStateChange(const State &newState)
{
	(void)newState;
}

#endif /* !ANIMA_HPP_ */
