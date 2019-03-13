/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade directory menu object method
*/

#include <filesystem>
#include "DirectoryMenu.hpp"

DirectoryMenu::DirectoryMenu(const std::string &dir,
							 const std::string &prefix,
							 const std::string &suffix):
	_dir(dir),
	_prefix(prefix),
	_suffix(suffix),
	_entries({})
{
	refresh();
}

void	DirectoryMenu::refresh()
{
	_entries.clear();
	using dirIterator = std::filesystem::directory_iterator;
    for (const auto & entry : dirIterator(_dir)) {
		if (entry.is_regular_file())
			_entries.emplace_back(entry.path(), _prefix, _suffix);
	}
}

DirectoryMenu::Menu::iterator	DirectoryMenu::begin()
{
	return _entries.begin();
}

DirectoryMenu::Menu::iterator	DirectoryMenu::end()
{
	return _entries.end();
}

const DirectoryMenu::MenuEntry	&DirectoryMenu::operator[](std::size_t idx) const
{
	return _entries[idx];
}

