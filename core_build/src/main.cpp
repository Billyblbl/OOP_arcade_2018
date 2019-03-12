/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** core main
*/

#include <termios.h>


#include <iostream>
#include "Core.hpp"

int main(int ac, char **av)
{
    // std::cin.sync_with_stdio();
   	// struct termios t;
    // tcgetattr(0, &t);
    // t.c_lflag &= (~ICANON & ~ECHO);
    // tcsetattr(0, TCSANOW, &t);
    // setbuf(stdin, nullptr);


    // std::cout << "Enter a character: ";
    // int c,d,e = '\0';
    // c = std::cin.get();
    // d = std::cin.get();
    // e = std::cin.get();
    // std::cout << "\nYour character was ";
    //     std::cout << c << d << e <<std::endl;
    // if ((c==27)&&(d=91)) {
    //     if (e==65) { std::cout << "UP";}
    //     if (e==66) { std::cout << "DOWN";}
    //     if (e==67) { std::cout << "RIGHT";}
    //     if (e==68) { std::cout << "LEFT";}
    //     std::cout << c << d << e <<std::endl;
	//     int keyStroke = c | (d << 8) | (e << 16);
    //     std::printf("|0x%x|\n", c);
    //     std::printf("|0x%x|\n", d);
    //     std::printf("|0x%x|\n", e);
    //     std::printf("|0x%x|\n", keyStroke);
    // }
    // else
    //     std::cout << c << d << e <<std::endl;
    // return 0;


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
    (void)ac;
}
