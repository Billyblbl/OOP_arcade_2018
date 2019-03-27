/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade main menu cursor object
*/

#include "MainMenu.hpp"

MainMenu::Cursor::Cursor(DirectoryMenu &directory,
						 IDisplayable *entity,
						 MainMenu::Position2F position):
	_directory(&directory),
	_iterator(_directory->begin()),
	_entity(entity),
	_position(position),
	_initPosition(position),
	_selected(false)
{}

//act as iterator (but wrapping around)

MainMenu::Cursor	&MainMenu::Cursor::operator++()
{
	if (_directory->length() == 0)
		return *this;
	_iterator++;
	if (_iterator >= _directory->end()) {
		_iterator = _directory->begin();
		_position = _initPosition;
	} else if (_iterator >= _directory->begin())
		_position.y++;
	return *this;
}

MainMenu::Cursor	&MainMenu::Cursor::operator--()
{
	if (_directory->length() == 0)
		return *this;
	if (_iterator <= _directory->begin()) {
		_iterator = _directory->end() - 1;
		_position.y = _initPosition.y + _directory->length() - 1;
	} else if (_iterator <= _directory->end()) {
		_iterator--;
		_position.y--;
	}
	return *this;
}

MainMenu::Cursor	&MainMenu::Cursor::operator=(DirectoryMenu::iterator rhs)
{
	_iterator = rhs;
	_position.y = _initPosition.y + (rhs - _directory->begin());
	return *this;
}

bool				MainMenu::Cursor::operator==(DirectoryMenu::iterator rhs) const
{
	return _iterator == rhs;
}

bool				MainMenu::Cursor::operator!=(DirectoryMenu::iterator rhs) const
{
	return _iterator != rhs;
}

MainMenu::Cursor::operator	DirectoryMenu::MenuEntry &()
{
	return *_iterator;
}

DirectoryMenu::MenuEntry	*MainMenu::Cursor::operator->()
{
	return &(*_iterator);
}

const DirectoryMenu::MenuEntry	*MainMenu::Cursor::operator->() const
{
	return &(*_iterator);
}

DirectoryMenu::MenuEntry	&MainMenu::Cursor::operator*()
{
	return *_iterator;
}

const DirectoryMenu::MenuEntry	&MainMenu::Cursor::operator*() const
{
	return *_iterator;
}

//act as entity

MainMenu::Cursor::operator IDisplayable &()
{
	return *_entity;
}

void					MainMenu::Cursor::reset(IDisplayable *newEntity)
{
	_entity.reset(newEntity);
}

MainMenu::Position2F	MainMenu::Cursor::getPos() const
{
	return _position;
}

void					MainMenu::Cursor::setPos(MainMenu::Position2F pos)
{
	_position = pos;
}

//act as both ("cursor")

bool					MainMenu::Cursor::isSelected() const
{
	return _selected;
}

void					MainMenu::Cursor::select(bool on)
{
	_selected = (on && _directory->length() > 0);
	if (on)
		_entity->setState("selected");
	else
		_entity->setState("untouched");
}