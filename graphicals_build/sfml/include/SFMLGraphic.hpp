/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML implementation of IGraphic interface for graphical handler object
*/

#ifndef SFMLGRAPHIC_HPP_
    #define SFMLGRAPHIC_HPP_

	#include <queue>
	#include <SFML/Graphics.hpp>
	#include "IGraphic.hpp"
	#include "Cache.hpp"

class SFMLGraphic : public IGraphic {
	public:
		SFMLGraphic(unsigned width, unsigned height);
		~SFMLGraphic() = default;

    	void            setEntity(float x, float y, IDisplayable &entity) override;
    	void            write(int x, int y, const std::string &text) override;
    	void            setSize(int x, int y) override;
    	bool            update() override;
    	void            clear() override;
    	IDisplayable    *createDisplayable(const std::string &name) override;
		bool			hasInput() override;
		int32_t			getInput() override;

		static const sf::Font	&getFont();

		typedef	std::unordered_map<sf::Keyboard::Key, int32_t>	Translations;
		typedef std::queue<const sf::Drawable *>				RenderQueue;
		typedef	std::vector<sf::Text>							TextList;

	protected:
	private:
		sf::Vector2u		_windowDimensions;
		sf::RenderWindow	_window;
		static sf::Font		_font;

		bool				_hasInput;
		sf::Keyboard::Key	_input;
		bool				_majInput;

		sf::Vector2f		_cellDimensions;
		sf::Vector2u		_boardDimensions;

		RenderQueue			_toDraw;
		TextList			_texts;

		static const Translations	Translator;
		static const Translations	MajTranslator;

};

#endif /* !SFMLGRAPHIC_HPP_ */
