/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** SFML implementation of IGraphic interface, methods
*/

#include "SFMLGraphic.hpp"
#include "IGame.hpp"
#include "SFMLSpriteDisplayable.hpp"
#include "SFMLTextDisplayable.hpp"

extern "C" {
	// SFMLGraphic	LibObject(1920, 1080);
	SFMLGraphic	*CreateHandler()
	{
		return new SFMLGraphic(1920, 1080);
	}
}

sf::Font		SFMLGraphic::_font;

//f*ck sfml and their non-translated keystroke

const SFMLGraphic::Translations	SFMLGraphic::Translator = {
	{sf::Keyboard::Up, IGame::arrowUp},
	{sf::Keyboard::Down, IGame::arrowDown},
	{sf::Keyboard::Left, IGame::arrowLeft},
	{sf::Keyboard::Right, IGame::arrowRight},
	{sf::Keyboard::PageUp, IGame::pageUp},
	{sf::Keyboard::PageDown, IGame::pageDown},
	{sf::Keyboard::Home, IGame::home},
	{sf::Keyboard::End, IGame::end},
	{sf::Keyboard::Enter, '\n'},
	{sf::Keyboard::A, 'a'},
	{sf::Keyboard::B, 'b'},
	{sf::Keyboard::C, 'c'},
	{sf::Keyboard::D, 'd'},
	{sf::Keyboard::E, 'e'},
	{sf::Keyboard::F, 'f'},
	{sf::Keyboard::G, 'g'},
	{sf::Keyboard::H, 'h'},
	{sf::Keyboard::I, 'i'},
	{sf::Keyboard::J, 'j'},
	{sf::Keyboard::K, 'k'},
	{sf::Keyboard::L, 'l'},
	{sf::Keyboard::M, 'm'},
	{sf::Keyboard::N, 'n'},
	{sf::Keyboard::O, 'o'},
	{sf::Keyboard::P, 'p'},
	{sf::Keyboard::Q, 'q'},
	{sf::Keyboard::R, 'r'},
	{sf::Keyboard::S, 's'},
	{sf::Keyboard::T, 't'},
	{sf::Keyboard::U, 'u'},
	{sf::Keyboard::V, 'v'},
	{sf::Keyboard::W, 'w'},
	{sf::Keyboard::X, 'x'},
	{sf::Keyboard::Y, 'y'},
	{sf::Keyboard::Z, 'z'},
};

const SFMLGraphic::Translations	SFMLGraphic::MajTranslator = {
	{sf::Keyboard::A, 'A'},
	{sf::Keyboard::B, 'B'},
	{sf::Keyboard::C, 'C'},
	{sf::Keyboard::D, 'D'},
	{sf::Keyboard::E, 'E'},
	{sf::Keyboard::F, 'F'},
	{sf::Keyboard::G, 'G'},
	{sf::Keyboard::H, 'H'},
	{sf::Keyboard::I, 'I'},
	{sf::Keyboard::J, 'J'},
	{sf::Keyboard::K, 'K'},
	{sf::Keyboard::L, 'L'},
	{sf::Keyboard::M, 'M'},
	{sf::Keyboard::N, 'N'},
	{sf::Keyboard::O, 'O'},
	{sf::Keyboard::P, 'P'},
	{sf::Keyboard::Q, 'Q'},
	{sf::Keyboard::R, 'R'},
	{sf::Keyboard::S, 'S'},
	{sf::Keyboard::T, 'T'},
	{sf::Keyboard::U, 'U'},
	{sf::Keyboard::V, 'V'},
	{sf::Keyboard::W, 'W'},
	{sf::Keyboard::X, 'X'},
	{sf::Keyboard::Y, 'Y'},
	{sf::Keyboard::Z, 'Z'}
};

SFMLGraphic::SFMLGraphic(unsigned width, unsigned height):
	_windowDimensions(width, height),
	_window(sf::VideoMode(width, height), "Arcade"),
	_hasInput(false)
{
	if (!_font.loadFromFile("ressources/libs/sfml/fonts/arial.ttf"))
		throw std::runtime_error("SFML font loading failure : ressources/libs/sfml/fonts/arial.ttf");
}

void            SFMLGraphic::setEntity(float x, float y, IDisplayable &entity)
{
	SFMLArcadeEntity	&asEntity = dynamic_cast<SFMLArcadeEntity &>(entity);
	sf::Vector2u	dimensions = asEntity.getDimensions();
	asEntity.getTransformable().setScale(_cellDimensions.x / dimensions.x, _cellDimensions.y / dimensions.y);
	asEntity.getTransformable().setPosition(x * _cellDimensions.x, y * _cellDimensions.y);
	_window.draw(asEntity.getDrawable());
}

void            SFMLGraphic::write(int x, int y, const std::string &text)
{
	sf::Text	textEntity(text, _font);
	textEntity.setFillColor(sf::Color::White);
	sf::Vector2u	dimensions(textEntity.getLocalBounds().width, textEntity.getLocalBounds().height);
	textEntity.setScale(_cellDimensions.x * text.length() / dimensions.x, _cellDimensions.y / dimensions.y);
	textEntity.setPosition(x * _cellDimensions.x, y * _cellDimensions.y);
	_window.draw(textEntity);
}

void            SFMLGraphic::setSize(int x, int y)
{
	unsigned	ux = static_cast<unsigned>(x);
	unsigned	uy = static_cast<unsigned>(y);
	_cellDimensions = {static_cast<float>(_windowDimensions.x / ux),
					   static_cast<float>(_windowDimensions.y / uy)};
	_boardDimensions = {ux, uy};
}

bool            SFMLGraphic::update()
{
	_hasInput = false;
	sf::Event	ev;
	while(_window.pollEvent(ev)){
		if (ev.type == sf::Event::Closed)
			_window.close();
		else if (ev.type == sf::Event::KeyPressed) {
			_hasInput = true;
			_input = ev.key.code;
			_majInput = ev.key.shift;
		}
	}
	_window.display();
	return _window.isOpen();
}

void            SFMLGraphic::clear()
{
	_window.clear();
}

IDisplayable    *SFMLGraphic::createDisplayable(const std::string &name)
{
	try {
		return new SFMLSpriteDisplayable(name);
	} catch (const SFMLSpriteDisplayable::SFMLSpriteError &e) {
		return new SFMLTextDisplayable(name);
	}
}

bool			SFMLGraphic::hasInput()
{
	return _hasInput;
}

int32_t			SFMLGraphic::getInput()
{
	if (_majInput && MajTranslator.find(_input) != MajTranslator.end())
		return MajTranslator.at(_input);
	else if (Translator.find(_input) != Translator.end())
		return Translator.at(_input);
	else
		return 0;
}

const sf::Font	&SFMLGraphic::getFont()
{
	return _font;
}
