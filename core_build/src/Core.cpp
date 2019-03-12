/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade core class methods
*/

#include <iostream>
#include "Core.hpp"

//the small bit of code in the constructor about the termios thingy
//is a bit of black magic to prevent input buffering

Core::Core(const std::string &path):
	_screen(path),
	_games({}),
	_currentGame(_games.begin())
{
    std::cin.sync_with_stdio();
    if (tcgetattr(0, &_oldSettings))
		throw std::runtime_error(std::string(__func__) + " : tcgetattr error");
   	struct termios t = _oldSettings;
    t.c_lflag &= (~ICANON & ~ECHO);
    if (tcsetattr(0, TCSANOW, &t))
		throw std::runtime_error(std::string(__func__) + " : tcsetattr error");
    setbuf(stdin, nullptr);
}

Core::~Core()
{
	if (tcsetattr(0, TCSANOW, &_oldSettings))
		std::cerr << __func__ << " : tcsetattr error";
}

void	Core::addGame(const std::string &path)
{
	_games.emplace_back(path);
	_currentGame = _games.end() - 1;
	getCurrentGame()->setGraphic(_screen);
}

void	Core::setGraphic(const std::string &path)
{
	_screen.reset(path);
}

Core::GameHandler		&Core::getCurrentGame()
{
	return *_currentGame;
}

