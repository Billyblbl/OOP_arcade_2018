/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade main menu keybinds
*/

#include "MainMenu.hpp"

void	MainMenu::incGameCursor(bool reverse)
{
	_selectedGame = false;
	if (reverse && _gameCursor != _gameList.begin())
		_gameCursor--;
	else if (_gameCursor != _gameList.end() - 1)
		_gameCursor++;
}

void	MainMenu::incGlibCursor(bool reverse)
{
	_selectedGlib = false;
	if (reverse && _glibCursor != _glibList.begin())
		_glibCursor--;
	else if (_glibCursor != _glibList.end() - 1)
		_glibCursor++;
}
