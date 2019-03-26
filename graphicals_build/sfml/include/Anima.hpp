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
	#include "IDisplayable.hpp"
	#include "Entity.hpp"

template<class State>
class Anima : public IDisplayable {
	public:

		Anima(const std::string &path):
			_path(path)
		{
			Entity	&entity = Entity::ArcadeCache.get(path);
			_spritePath = entity.getSpritePath();
			for (auto &state : entity) {
				_keys.emplace_back(state.name);
				_states.emplace(state.name, state);
			}
		}

		virtual ~Anima()
		{
			Entity::ArcadeCache.letGo(_path);
		}

		void				setState(const std::string &stateName) override final;
		void				setState(std::size_t stateId) override final;
		const std::string	&getState() const override final;

		IDisplayable		&operator++() override final;
		IDisplayable		&operator--() override final;


		typedef std::vector<std::string>				KeyList;
		typedef	std::unordered_map<std::string, State>	StateMap;

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
void	Anima<State>::setState(const std::string &stateName)
{
	_currentState = _states.find(stateName);
	_currentStateName = std::find(_keys.begin(), _keys.end(), stateName);
	onStateChange(_currentState->second);
}

template<class State>
void	Anima<State>::setState(std::size_t stateId)
{
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
void			Anima<State>::onStateChange(const State &newState)
{
	(void)newState;
}

#endif /* !ANIMA_HPP_ */
