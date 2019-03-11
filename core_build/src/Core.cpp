/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade core class methods
*/

#include "Core.hpp"

Core::Core(const std::string &path):
	_screen(path),
	_games({}),
	_currentGame(_games.begin())
{
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

void	Core::run()
{
	using arcadeClock = std::chrono::high_resolution_clock;
	using timePoint = std::chrono::time_point<arcadeClock>;
	bool		running = true;
	timePoint	last = arcadeClock::now();
	while (running) {
		timePoint	now = arcadeClock::now();
		running = getCurrentGame()->update(now - last);
		last = now;
	}
}

Core::GameHandler		&Core::getCurrentGame()
{
	return *_currentGame;
}

// const Core::GameHandler	&Core::getCurrentGame() const
// {
// 	return *_currentGame;
// }
