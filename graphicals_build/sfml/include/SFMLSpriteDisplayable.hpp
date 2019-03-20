/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML Graphic implementation displayable object class
*/

#ifndef SFMLSPRITEDISPLAYABLE_HPP_
    #define SFMLSPRITEDISPLAYABLE_HPP_

	#include <string>
	#include <SFML/Graphics.hpp>
	#include "IDisplayable.hpp"
	#include "Cache.hpp"
	#include "Entity.hpp"

class SFMLSpriteDisplayable : public sf::Sprite, public IDisplayable {
	public:
		SFMLSpriteDisplayable(const std::string &name);
		~SFMLSpriteDisplayable() = default;

		class LoadableTexture : public sf::Texture {
			public:
			LoadableTexture(const std::string &path) {
				if (!loadFromFile(path))
					throw std::runtime_error("SFML texture load : " + path);
			}
		};

		class SFMLSpriteError : std::runtime_error {
			public:
			SFMLSpriteError(const std::string &what): std::runtime_error(what){}
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
};

#endif /* !SFMLSPRITEDISPLAYABLE_HPP_ */
