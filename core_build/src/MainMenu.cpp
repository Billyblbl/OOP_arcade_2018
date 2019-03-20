/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade main menu pseudo-game
*/

#include "MainMenu.hpp"

MainMenu::MainMenu():
	_gameList("./games", "./games/lib_arcade_", ".so"),
	_glibList("./lib", "./lib/lib_arcade_", ".so"),
	_gameCursor(_gameList.begin(), nullptr, Position2F({0.0f, 0.0f})),
	_glibCursor(_glibList.begin(), nullptr, Position2F({50.0f, 0.0f})),
	_screen(nullptr)
{
	_keyBinds[KeyCode::arrowUp] = [this](){this->incGameCursor(true);};
	_keyBinds[KeyCode::arrowDown] = [this](){this->incGameCursor();};
	_keyBinds[KeyCode::pageUp] = [this](){this->incGlibCursor(true);};
	_keyBinds[KeyCode::pageDown] = [this](){this->incGlibCursor();};
	_keyBinds['r'] = [this](){this->refresh();};
	_keyBinds['\n'] = [this](){this->_gameCursor.select();};
	_keyBinds['g'] = [this](){this->_glibCursor.select();};
}

bool	MainMenu::update(std::chrono::nanoseconds deltaT, std::chrono::seconds upTime)
{
	return true;
	(void)deltaT;
	(void)upTime;
}

void	MainMenu::handleKey(int32_t key)
{
	if (_keyBinds.find(key) != _keyBinds.end())
		_keyBinds.at(key)();
}

void	MainMenu::setGraphic(IGraphic &handler)
{
	_screen = &handler;
	_screen->setSize(100, 100);
	_screen->clear();
	_gameCursor.reset(_screen->createDisplayable("./ressources/core/entities/menu.cursor.entity"));
	_glibCursor.reset(_screen->createDisplayable("./ressources/core/entities/menu.cursor.entity"));
	_emptyEntity.reset(_screen->createDisplayable("./ressources/core/entities/menu.empty.entity"));
	refresh();
}

void	MainMenu::refresh()
{
	_gameCursor.select(false);
	_glibCursor.select(false);
	_gameList.refresh();
	_glibList.refresh();
	_gameCursor = _gameList.begin();
	_glibCursor = _glibList.begin();
	_gameCursor.setPos({0.0, 0.0});
	_glibCursor.setPos({50.0, 0.0});
	_screen->clear();
	for (unsigned short i = 1; i < _gameList.length() && i <= 50; i++)
		_screen->write(1, i, _gameList[i].name);
	for (unsigned short i = 1; i < _glibList.length() && i <= 50; i++)
		_screen->write(1, i, _glibList[i].name);
	_screen->setEntity(_gameCursor.getPos().x, _gameCursor.getPos().y, _gameCursor);
	_screen->setEntity(_glibCursor.getPos().x, _glibCursor.getPos().y, _glibCursor);
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
	return _gameCursor.isSelected();
}

bool	MainMenu::hasSelectedGlib() const
{
	return _glibCursor.isSelected();
}

