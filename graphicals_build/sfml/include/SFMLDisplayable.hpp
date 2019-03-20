/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML Graphic implementation displayable object class
*/

#ifndef SFMLDISPLAYABLE_HPP_
    #define SFMLDISPLAYABLE_HPP_

	#include <string>
	#include <SFML/Graphics.hpp>
	#include "IDisplayable.hpp"
	#include "Cache.hpp"
	#include "Entity.hpp"

class SFMLDisplayable : public sf::Sprite, public IDisplayable {
	public:
		SFMLDisplayable(const std::string &name);
		~SFMLDisplayable() = default;

		class LoadableTexture : public sf::Texture {
			public:
			LoadableTexture(const std::string &path) {
				if (!loadFromFile(path))
					throw std::runtime_error("SFML texture load : " + path);
			}
		};

		struct State {
			public:
			State(const Entity::State &data);

			const std::string	name;
			sf::IntRect			rect;
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
		std::string			_name;
		KeyList				_keys;
		StateMap			_states;
		KeyList::iterator	_currentState;

		static	Cache<LoadableTexture>	TextureCache;
		static	Cache<Entity>			EntityCache;
};

#endif /* !SFMLDISPLAYABLE_HPP_ */
