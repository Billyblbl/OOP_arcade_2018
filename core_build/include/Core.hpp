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
	#include "MainMenu.hpp"

class Core {
	public:
		Core(const std::string &path);
		~Core() = default;

		typedef std::chrono::high_resolution_clock Clock;

		typedef	std::chrono::nanoseconds	Nano;
		typedef std::chrono::seconds		Second;

		template<typename T>
		using TimePoint = std::chrono::time_point<Clock, T>;

		void	addGame(const std::string &path);
		void	setGraphic(const std::string &path);
		bool	update(const TimePoint<Second> &start, TimePoint<Nano> &last);
		void	run();

		typedef	LibHandler<IGame> GameHandler;
		typedef	LibHandler<IGraphic> GraphicHandler;
		typedef std::vector<GameHandler> GameVector;
		typedef std::unique_ptr<GraphicHandler>	GHandlerPtr;



	protected:
	private:

		IGame		&getCurrentGame();
		GameHandler	&getCurrentHandler();
		IGraphic	&getScreen();

		GHandlerPtr				_screen;
		GameVector              _games;
		GameVector::iterator    _currentGame;
		MainMenu				_mainMenu;

};

#endif /* !ARCADE_HPP_ */
