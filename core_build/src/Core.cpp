/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade core class methods
*/

#include <iostream>
#include <string.h>
#include "Core.hpp"

//debug
#include <thread>

Core::Core(const std::string &path):
	_screen(new GraphicHandler(path)),
	_games({}),
	_currentGame(_games.begin()),
	_mainMenu(getScreen())
{}

void	Core::addGame(const std::string &path)
{
	getCurrentGame().onDisable();
	_games.emplace_back(path);
	_currentGame = _games.end() - 1;
	getCurrentGame().setGraphic(getScreen());
	getCurrentGame().onEnable();
}

void	Core::setGraphic(const std::string &path)
{
	getCurrentGame().onDisable();
	GraphicHandler	*newHandler = new GraphicHandler(path);
	_mainMenu.setGraphic(*newHandler);
	for (auto game : _games)
		game->setGraphic(*newHandler);
	_screen.reset(newHandler);
	getCurrentGame().onEnable();
}

void	Core::run()
{
	bool				running = true;
	TimePoint<Second>	start(std::chrono::time_point_cast<Second>(Clock::now()));
	TimePoint<Nano>		last(start);
	IGame				&game = getCurrentGame();
	IGraphic			&screen = getScreen();
	while (running) {
		screen.clear();
		if (screen.hasInput())
			game.handleKey(screen.getInput());
		TimePoint<Nano>		now(Clock::now());
		TimePoint<Second>	secNow(std::chrono::time_point_cast<Second>(now));
		running = game.update(now - last, secNow - start);
		screen.update();
		last = now;
		if (!running) {
			game.onDisable();
			_games.erase(_currentGame);
			_currentGame = _games.begin();
		}
	}
}

Core::GameHandler		&Core::getCurrentHandler()
{
	return *_currentGame;
}

IGame					&Core::getCurrentGame()
{
	if (_games.size() == 0)
		return _mainMenu;
	return *_currentGame;
}

IGraphic	&Core::getScreen()
{
	return *_screen;
}
