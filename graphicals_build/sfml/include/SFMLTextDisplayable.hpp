/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
**
*/

#ifndef SFMLTEXTDISPLAYABLE_HPP_
    #define SFMLTEXTDISPLAYABLE_HPP_

	#include <unordered_map>
	#include "SFML/Graphics.hpp"
	#include "IDisplayable.hpp"
	#include "Entity.hpp"

class SFMLTextDisplayable : public sf::Text, public IDisplayable {
	public:
		SFMLTextDisplayable(const std::string &name);
		~SFMLTextDisplayable();

		struct State {
			public:
			State(const Entity::State &data);

			const std::string	name;
			char				asciiImg;
			sf::Color			color;
		};

		void				setState(const std::string &stateName) override;
		void				setState(std::size_t stateId) override;
		const std::string	&getState() const override;

		IDisplayable		&operator++() override;
		IDisplayable		&operator--() override;

		typedef std::vector<std::string>				KeyList;
		typedef	std::unordered_map<std::string, State>	StateMap;

	protected:
	private:
		KeyList				_keys;
		StateMap			_states;
		KeyList::iterator	_currentState;
};

#endif /* !SFMLTEXTDISPLAYABLE_HPP_ */
