/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML implementation of IGraphic interface for graphical handler object
*/

#ifndef SFMLGRAPHIC_HPP_
    #define SFMLGRAPHIC_HPP_

	#include <SFML/Graphics.hpp>
	#include "IGraphic.hpp"
	#include "Cache.hpp"
	#include "Entity.hpp"

class SFMLGraphic : public IGraphic {
	public:
		SFMLGraphic(unsigned width, unsigned height);
		~SFMLGraphic() = default;

    	void            setEntity(float x, float y, IDisplayable &entity) override;
    	void            write(int x, int y, const std::string &text) override;
    	void            setSize(int x, int y) override;
    	void            update() override;
    	void            clear() override;
    	IDisplayable    *createDisplayable(const std::string &name) override;

		static const sf::Font	&getFont();

		static	Cache<Entity>			EntityCache;

	protected:
	private:
		sf::Vector2f		_cellDimensions;
		sf::Vector2u		_boardDimensions;

		sf::Vector2u		_windowDimensions;
		sf::RenderWindow	_window;
		static sf::Font		_font;

};

#endif /* !SFMLGRAPHIC_HPP_ */
