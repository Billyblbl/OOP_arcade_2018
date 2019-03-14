/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** arcade main menu
*/

#ifndef MAINMENU_HPP_
    #define MAINMENU_HPP_

	#include <memory>
	#include "IGame.hpp"
	#include "DirectoryMenu.hpp"

class MainMenu : public IGame {
	public:
		MainMenu();
		~MainMenu() = default;

	    bool	update(std::chrono::nanoseconds deltaT, std::chrono::seconds upTime) override;
		void	handleKey(int32_t key) override;
    	void    setGraphic(IGraphic &handler) override;
		void	onEnable() override;
		void	onDisable() override;

		void				refresh();
		const std::string	&getGame() const;
		const std::string	&getGlib() const;

		bool	hasSelectedGame() const;
		bool	hasSelectedGlib() const;

		void	incGameCursor(bool reverse = false);
		void	incGlibCursor(bool reverse = false);

		typedef	std::unique_ptr<IDisplayable>	DisplayablePtr;

	protected:
	private:

		DirectoryMenu			_gameList;
		DirectoryMenu			_glibList;
		DirectoryMenu::iterator	_gameCursor;
		DirectoryMenu::iterator	_glibCursor;
		IGraphic				*_handler;

		DisplayablePtr			_gameCursorEntity;
		DisplayablePtr			_glibCursorEntity;

		bool					_selectedGame;
		bool					_selectedGlib;

		std::unordered_map<int32_t, Action>	_keyBinds;

};

#endif /* !MAINMENU_HPP_ */
