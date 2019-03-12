/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** core main
*/

#include <iostream>
#include "Core.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "USAGE: " << av[0] << " [glib]" << std::endl
		<< "glib\tArcade compatible graphic library" << std::endl;
		return 84;
	}
	try {
		Core  arcade(av[1]);
		arcade.run();
		return 0;
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
		return 84;
	}
}
