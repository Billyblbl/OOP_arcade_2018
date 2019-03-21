/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** core control functions
*/

#include <poll.h>
#include <iostream>
#include "Core.hpp"

void	Core::run()
{
	bool				running = true;
	TimePoint<Second>	start(std::chrono::time_point_cast<Second>(Clock::now()));
	TimePoint<Nano>		last(start);
	IGame				&game = getCurrentGame();
	IGraphic			&screen = getScreen();
	while (running) {
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

