/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML Arcade entity concept interface
*/

#ifndef SFMLARCADEENTITY_HPP_
    #define SFMLARCADEENTITY_HPP_

	#include <SFML/Graphics.hpp>

class SFMLArcadeEntity {
	public:
		virtual ~SFMLArcadeEntity() = default;

		virtual const sf::Drawable		&getDrawable() const = 0;
		virtual sf::Transformable		&getTransformable() = 0;
		virtual sf::Vector2u			getDimensions() const = 0;

	protected:
	private:
};

#endif /* !SFMLARCADEENTITY_HPP_ */
