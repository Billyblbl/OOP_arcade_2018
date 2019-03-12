/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** core control functions
*/

#include <poll.h>
#include <iostream>
#include "Core.hpp"

bool	Core::keyPressed() const
{
	struct pollfd	pls[1];
	pls[0].fd = 0;
	pls[0].events = POLLIN | POLLPRI;
	return (poll(pls, 1, 500) > 0);
}

int32_t	Core::getKeyStroke()
{
	int32_t	code[3] = {0};
	code[0] = std::cin.get();
	if (code[0] != 0x1b)
		return code[0];
	code[1] = std::cin.get();
	code[2] = std::cin.get();
	int32_t	keyStroke = code[0] | (code[1] << 8) | (code[2] << 16);
	return keyStroke;
}

void	Core::run()
{
	using arcadeClock = std::chrono::high_resolution_clock;
	using timePoint = std::chrono::time_point<arcadeClock>;
	bool		running = true;
	timePoint	last = arcadeClock::now();
	while (running) {
		timePoint	now = arcadeClock::now();
		if (keyPressed())
			getCurrentGame()->getKeybind(getKeyStroke())();
		running = getCurrentGame()->update(now - last);
		last = now;
	}
}

