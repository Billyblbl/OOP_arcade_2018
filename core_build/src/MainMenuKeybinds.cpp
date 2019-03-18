/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade main menu keybinds
*/

#include "MainMenu.hpp"

void	MainMenu::incGameCursor(bool reverse)
{
	_gameCursor.select(false);
	_screen->setEntity(0.0, _gameCursor.getPos().y, *_emptyEntity);
	if (reverse && _gameCursor != _gameList.begin())
		--_gameCursor;
	else if (_gameCursor != _gameList.end() - 1)
		++_gameCursor;
	_screen->setEntity(0.0, _gameCursor.getPos().y, _gameCursor);
}

void	MainMenu::incGlibCursor(bool reverse)
{
	_glibCursor.select(false);
	_screen->setEntity(0.0, _glibCursor.getPos().y, *_emptyEntity);
	if (reverse && _glibCursor != _glibList.begin())
		--_glibCursor;
	else if (_glibCursor != _glibList.end() - 1)
		++_glibCursor;
	_screen->setEntity(0.0, _glibCursor.getPos().y, _glibCursor);
}
