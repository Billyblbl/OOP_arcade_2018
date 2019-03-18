/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade main menu cursor object
*/

#include "MainMenu.hpp"

MainMenu::Cursor::Cursor(DirectoryMenu::iterator it,
						 IDisplayable *entity,
						 MainMenu::Position2F position):
	_iterator(it),
	_entity(entity),
	_position(position),
	_selected(false)
{}

//act as iterator

MainMenu::Cursor	&MainMenu::Cursor::operator++()
{
	_iterator++;
	_position.y++;
	return *this;
}

MainMenu::Cursor	&MainMenu::Cursor::operator--()
{
	_iterator--;
	_position.y--;
	return *this;
}

MainMenu::Cursor	&MainMenu::Cursor::operator=(DirectoryMenu::iterator rhs)
{
	_iterator = rhs;
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
	return _iterator.base();
}

const DirectoryMenu::MenuEntry	*MainMenu::Cursor::operator->() const
{
	return _iterator.base();
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
	_selected = on;
}