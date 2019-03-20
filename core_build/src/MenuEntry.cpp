/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** directory menu menu entry struct
*/

#include <stdexcept>
#include "DirectoryMenu.hpp"

DirectoryMenu::MenuEntry::MenuEntry(const std::string &_path,
									const std::string &prefix,
									const std::string &suffix):
									path(_path)
{
	if (path.substr(0, prefix.size()) != prefix || path.substr(path.size() - suffix.size()) != suffix)
		throw std::runtime_error(path + " : not an intended entry : " + prefix + "[name]" + suffix);
	name = path.substr(prefix.size(), (path.size() - suffix.size()));
	if (std::islower(name[0]))
		name[0] = std::toupper(name[0]);
}
