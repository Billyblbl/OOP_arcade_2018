/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade main menu pseudo-game
*/

#include "MainMenu.hpp"

MainMenu::MainMenu():
	_gameList("./games", "lib_arcade_", ".so"),
	_glibList("./lib", "lib_arcade_", ".so"),
	_gameCursor(_gameList.begin()),
	_glibCursor(_glibList.begin()),
	_handler(nullptr),
	_gameCursorEntity(nullptr),
	_glibCursorEntity(nullptr)
{
	_keyBinds[KeyCode::arrowUp] = [this](){this->incGameCursor(true);};
	_keyBinds[KeyCode::arrowDown] = [this](){this->incGameCursor();};
	_keyBinds[KeyCode::pageUp] = [this](){this->incGlibCursor(true);};
	_keyBinds[KeyCode::pageDown] = [this](){this->incGlibCursor();};
	_keyBinds['r'] = [this](){this->refresh();};
	_keyBinds['\n'] = [this](){this->_selectedGame = true;};
	_keyBinds['g'] = [this](){this->_selectedGlib = true;};
}

bool	MainMenu::update(std::chrono::nanoseconds deltaT, std::chrono::seconds upTime)
{
	return true;
	(void)deltaT;
	(void)upTime;
}

//(current interface signature may not be relevant soon TM)
void	MainMenu::handleKey(int32_t key)
{
	if (_keyBinds.find(key) != _keyBinds.end())
		_keyBinds.at(key)();
}

void	MainMenu::setGraphic(IGraphic &handler)
{
	_handler = &handler;
	_handler->setSize(100, 100);
	_handler->clear();
	_gameCursorEntity.reset(_handler->createDisplayable("menu.cursor"));
	_glibCursorEntity.reset(_handler->createDisplayable("menu.cursor"));
}

void	MainMenu::refresh()
{
	_selectedGame = false;
	_selectedGlib = false;
	_gameList.refresh();
	_glibList.refresh();
	_gameCursor = _gameList.begin();
	_glibCursor = _glibList.begin();
	int	i = 0;
	for (auto &game : _gameList) {
		if (&game == &(*_gameCursor))
			_handler->setEntity(0.0, i, *_gameCursorEntity);
		_handler->write(1, i++, game.name);
	}
	int i = 0;
	for (auto &lib : _glibList) {
		if (&lib == &(*_glibCursor))
			_handler->setEntity(50.0, i, *_glibCursorEntity);
		_handler->write(51, i++, lib.name);
	}
}

void	MainMenu::onEnable()
{
	refresh();
}

void	MainMenu::onDisable()
{}

const std::string	&MainMenu::getGame() const
{
	return _gameCursor->path;
}

const std::string	&MainMenu::getGlib() const
{
	return _glibCursor->path;
}

bool	MainMenu::hasSelectedGame() const
{
	return _selectedGame;
}

bool	MainMenu::hasSelectedGlib() const
{
	return _selectedGlib;
}

