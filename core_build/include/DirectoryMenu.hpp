/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** directory menu object class
*/

#ifndef DIRECTORYMENU_HPP_
    #define DIRECTORYMENU_HPP_

	#include <string>
	#include <vector>

class DirectoryMenu {
	public:

		struct MenuEntry {
			public:
				MenuEntry(const std::string &path,
						  const std::string &prefix = "",
						  const std::string &suffix = "");
				~MenuEntry() = default;

				std::string			name;
				const std::string	path;
		};

		typedef std::vector<MenuEntry>	Menu;
		typedef Menu::iterator			iterator;

		DirectoryMenu(const std::string &dir,
					  const std::string &prefix = "",
					  const std::string &suffix = "");
		~DirectoryMenu() = default;

		void		refresh();
		iterator	begin();
		iterator	end();

		const MenuEntry	&operator[](std::size_t idx) const;

	protected:
	private:

		std::string		_dir;
		std::string		_prefix;
		std::string		_suffix;
		Menu			_entries;
		Menu::iterator	_cursor;
};

#endif /* !DIRECTORYMENU_HPP_ */
