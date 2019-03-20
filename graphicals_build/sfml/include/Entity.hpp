/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Entity file to object class
*/

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_

	#include <string>
	#include <vector>

class Entity {
	public:
		Entity(const std::string &path);
		~Entity() = default;

		struct CoordinatesI {
			public:
			CoordinatesI() = default;
			CoordinatesI(const std::string &format);

			int	x;
			int	y;
		};

		union Color {
			uint8_t		r;
			uint8_t		g;
			uint8_t		b;
			uint32_t	value;
		};

		struct State {
			public:
			State() = default;
			State(const std::string &format);

			std::string		name;
			CoordinatesI	upLeft;
			CoordinatesI	downRight;
			Color			color;
			Color			backColor;
			char			ascii;
		};

		typedef std::vector<State>::iterator iterator;

		iterator			begin();
		iterator			end();
		const std::string	&getSpritePath() const;

	protected:
	private:
		std::string			_spritePath;
		std::vector<State>	_states;
};

#endif /* !ENTITY_HPP_ */
