/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
**
*/

#ifndef SFMLTEXTDISPLAYABLE_HPP_
    #define SFMLTEXTDISPLAYABLE_HPP_

	#include "SFML/Graphics.hpp"
	#include "Anima.hpp"
	#include "SFMLArcadeEntity.hpp"

struct SFMLAsciiData {
	public:
	SFMLAsciiData(const Entity::State &data);

	const std::string	name;
	char				asciiImg;
	sf::Color			color;
};

class SFMLTextDisplayable : public Anima<SFMLAsciiData>, public SFMLArcadeEntity {
	public:
		SFMLTextDisplayable(const std::string &name);
		~SFMLTextDisplayable() = default;

		void	onStateChange(const SFMLAsciiData &newState) override;

		const sf::Drawable		&getDrawable() const override;
		sf::Transformable		&getTransformable() override;
		sf::Vector2u			getDimensions() const override;

	protected:
	private:
		sf::Text	_text;
};

#endif /* !SFMLTEXTDISPLAYABLE_HPP_ */
