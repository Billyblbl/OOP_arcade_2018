/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade directory menu object method
*/

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
#if INCLUDE_STD_FILESYSTEM_EXPERIMENTAL
		if (std::filesystem::is_regular_file(entry.path()))
#else
		if (entry.is_regular_file())
#endif
			_entries.emplace_back(entry.path(), _prefix, _suffix);
	}
}

DirectoryMenu::iterator	DirectoryMenu::begin()
{
	return _entries.begin();
}

DirectoryMenu::iterator	DirectoryMenu::end()
{
	return _entries.end();
}

std::size_t							DirectoryMenu::length()
{
	return _entries.size();
}

const DirectoryMenu::MenuEntry	&DirectoryMenu::operator[](std::size_t idx) const
{
	return _entries[idx];
}

