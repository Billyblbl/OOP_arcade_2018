/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade main menu pseudo-game
*/

#include "MainMenu.hpp"

MainMenu::MainMenu(IGraphic &handler):
	_gameList("./games", "./games/lib_arcade_", ".so"),
	_glibList("./lib", "./lib/lib_arcade_", ".so"),
	_screen(&handler),
	_gameCursor(_gameList,
				_screen->createDisplayable("./ressources/core/entities/menu.cursor.entity"),
				Position2F({0.0f, 0.0f})),
	_glibCursor(_glibList,
				_screen->createDisplayable("./ressources/core/entities/menu.cursor.entity"),
				Position2F({50.0f, 0.0f}))
{
	_screen->setSize(100, 100);
	_keyBinds[KeyCode::arrowUp] = [this](){--this->_gameCursor;};
	_keyBinds[KeyCode::arrowDown] = [this](){++this->_gameCursor;};
	_keyBinds[KeyCode::pageUp] = [this](){--this->_glibCursor;};
	_keyBinds[KeyCode::pageDown] = [this](){++this->_glibCursor;};
	_keyBinds['r'] = [this](){this->refresh();};
	_keyBinds['\n'] = [this](){this->_gameCursor.select();};
	_keyBinds['g'] = [this](){this->_glibCursor.select();};
}

bool	MainMenu::update(std::chrono::nanoseconds deltaT, std::chrono::seconds upTime)
{
	for (unsigned short i = 0; i < _gameList.length() && i <= 50; i++)
		_screen->write(2, i, _gameList[i].name);
	for (unsigned short i = 0; i < _glibList.length() && i <= 50; i++)
		_screen->write(52, i, _glibList[i].name);
	_screen->setEntity(_gameCursor.getPos().x, _gameCursor.getPos().y, _gameCursor);
	_screen->setEntity(_glibCursor.getPos().x, _glibCursor.getPos().y, _glibCursor);
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
	_gameCursor.reset(_screen->createDisplayable("./ressources/core/entities/menu.cursor.entity"));
	_glibCursor.reset(_screen->createDisplayable("./ressources/core/entities/menu.cursor.entity"));
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
	// std::cout << __func__ << std::endl;
}

void	MainMenu::onEnable()
{
	_screen->setSize(100, 100);
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

void	MainMenu::endSelect()
{
	_gameCursor.select(false);
	_glibCursor.select(false);
}