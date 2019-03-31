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


	//All this shit is to correctly include the filesystem stuff
	#ifndef INCLUDE_STD_FILESYSTEM_EXPERIMENTAL
	#   if defined(__cpp_lib_filesystem)
	#       define INCLUDE_STD_FILESYSTEM_EXPERIMENTAL 0
	#   elif defined(__cpp_lib_experimental_filesystem)
	#       define INCLUDE_STD_FILESYSTEM_EXPERIMENTAL 1
	#   elif !defined(__has_include)
	#       define INCLUDE_STD_FILESYSTEM_EXPERIMENTAL 1
	#   elif __has_include(<filesystem>)
	#		define INCLUDE_STD_FILESYSTEM_EXPERIMENTAL 0
	#   elif __has_include(<experimental/filesystem>)
	#       define INCLUDE_STD_FILESYSTEM_EXPERIMENTAL 1
	#   else
	#       error Could not find system header "<filesystem>" or "<experimental/filesystem>"
	#   endif
	#   if INCLUDE_STD_FILESYSTEM_EXPERIMENTAL
	#       include <experimental/filesystem>
	namespace std {
	    namespace filesystem = experimental::filesystem;
	}
	#   else
	#       include <filesystem>
	#   endif
	#endif // #ifndef INCLUDE_STD_FILESYSTEM_EXPERIMENTAL


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
		std::size_t	length();

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
