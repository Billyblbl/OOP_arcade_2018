/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade core class
*/

#ifndef ARCADE_HPP_
	#define ARCADE_HPP_

	#include <string>
	#include <memory>
	#include <vector>
	#include "IGraphic.hpp"
	#include "IGame.hpp"
	#include "LibHandler.hpp"

class Core {
	public:
		Core(const std::string &path);
		~Core() = default;

		void	addGame(const std::string &path);
		void	setGraphic(const std::string &path);
		void	run();

		typedef	LibHandler<IGame> GameHandler;
		typedef	LibHandler<IGraphic> GraphicHandler;
		typedef std::vector<GameHandler> GameVector;

	protected:
	private:

		GameHandler			&getCurrentGame();

		GraphicHandler			_screen;
		GameVector              _games;
		GameVector::iterator    _currentGame;
};

#endif /* !ARCADE_HPP_ */
