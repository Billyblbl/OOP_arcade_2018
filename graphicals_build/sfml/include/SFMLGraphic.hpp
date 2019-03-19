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

class SFMLGraphic : public IGraphic {
	public:
		SFMLGraphic(unsigned width, unsigned height);
		~SFMLGraphic() = default;

    	void            setEntity(float x, float y, IDisplayable &entity);
    	void            write(int x, int y, const std::string &text);
    	void            setSize(int x, int y);
    	void            update();
    	void            clear();
    	IDisplayable    *createDisplayable(const std::string &name);

	protected:
	private:
		sf::Vector2f		_cellDimensions;
		sf::Vector2u		_boardDimensions;

		sf::Vector2u		_windowDimensions;
		sf::RenderWindow	_window;
		sf::Font			_font;

};

extern "C" {
	SFMLGraphic	LibObject(1920, 1080);
}

#endif /* !SFMLGRAPHIC_HPP_ */
