/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade core class
*/

#ifndef ARCADE_HPP_
	#define ARCADE_HPP_

	#include <termios.h>
	#include <string>
	#include <memory>
	#include <vector>
	#include "IGraphic.hpp"
	#include "IGame.hpp"
	#include "LibHandler.hpp"

class Core {
	public:
		Core(const std::string &path);
		~Core();

		void	addGame(const std::string &path);
		void	setGraphic(const std::string &path);
		void	run();

		typedef	LibHandler<IGame> GameHandler;
		typedef	LibHandler<IGraphic> GraphicHandler;
		typedef std::vector<GameHandler> GameVector;

	protected:
	private:

		GameHandler			&getCurrentGame();
		bool				keyPressed() const;
		int32_t				getKeyStroke();

		GraphicHandler			_screen;
		GameVector              _games;
		GameVector::iterator    _currentGame;

		//term data

		struct termios			_oldSettings;
};

#endif /* !ARCADE_HPP_ */
