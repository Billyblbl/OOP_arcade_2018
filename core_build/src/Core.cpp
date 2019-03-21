/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade core class methods
*/

#include <iostream>
#include <string.h>
#include "Core.hpp"

//the small bit of code in the constructor about the termios thingy
//is a bit of black magic to prevent input buffering

Core::Core(const std::string &path):
	_screen(new GraphicHandler(path)),
	_games({}),
	_currentGame(_games.begin())
{
    std::cin.sync_with_stdio();
    if (tcgetattr(0, &_oldSettings))
		throw std::runtime_error(std::string(__func__) + " : tcgetattr : " + strerror(errno));
   	struct termios t = _oldSettings;
    t.c_lflag &= (~(unsigned)ICANON & ~(unsigned)ECHO);
    if (tcsetattr(0, TCSANOW, &t))
		throw std::runtime_error(std::string(__func__) + " : tcsetattr : " + strerror(errno));
    setbuf(stdin, nullptr);
		_mainMenu.setGraphic(getScreen());
}

Core::~Core()
{
	if (tcsetattr(0, TCSANOW, &_oldSettings)) {
		std::cerr << __func__ << " : tcsetattr : " << strerror(errno) << std::endl;
		std::cerr << "This error might cause weird behavior on your terminal" << std::endl;
	}
}

void	Core::addGame(const std::string &path)
{
	if (_games.size() > 0)
		getCurrentGame().onDisable();
	else
		_mainMenu.onDisable();
	_games.emplace_back(path);
	_currentGame = _games.end() - 1;
	getCurrentGame().setGraphic(getScreen());
	getCurrentGame().onEnable();
}

void	Core::setGraphic(const std::string &path)
{
	if (_games.size() > 0)
		getCurrentGame().onDisable();
	else
		_mainMenu.onDisable();
	GraphicHandler	*newHandler = new GraphicHandler(path);
	_mainMenu.setGraphic(*newHandler);
	for (auto game : _games)
		game->setGraphic(*newHandler);
	_screen.reset(newHandler);
	if (_games.size() > 0)
		getCurrentGame().onEnable();
	else
		_mainMenu.onEnable();
}

Core::GameHandler		&Core::getCurrentHandler()
{
	return *_currentGame;
}

IGame					&Core::getCurrentGame()
{
	if (_games.size() == 0)
		return _mainMenu;
	return _currentGame->operator IGame &();
}

IGraphic	&Core::getScreen()
{
	return *_screen;
}
