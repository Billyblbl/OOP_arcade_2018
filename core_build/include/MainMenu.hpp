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

		typedef	std::unique_ptr<IDisplayable>	DisplayablePtr;

		struct Position2F {
			float	x;
			float	y;
		};

		//kinda looks like an union in some sense
		//might be a good idea to explore, to avoid unnecessary code
		class Cursor {
			public:

			Cursor(DirectoryMenu::iterator it, IDisplayable *entity, Position2F position);

			//act as iterator
			Cursor	&operator++();
			Cursor	&operator--();
			Cursor	&operator=(DirectoryMenu::iterator rhs);
			bool	operator==(DirectoryMenu::iterator rhs) const;
			bool	operator!=(DirectoryMenu::iterator rhs) const;
			operator DirectoryMenu::MenuEntry &();
			DirectoryMenu::MenuEntry		*operator->();
			const DirectoryMenu::MenuEntry	*operator->() const;
			DirectoryMenu::MenuEntry		&operator*();
			const DirectoryMenu::MenuEntry	&operator*() const;

			//act as entity
			operator IDisplayable &();
			void		reset(IDisplayable *newEntity);

			Position2F	getPos() const;
			void		setPos(Position2F pos);

			//both (cursor)
			bool		isSelected() const;
			void		select(bool on = true);

			// private:

			DirectoryMenu::iterator	_iterator;
			DisplayablePtr			_entity;
			Position2F				_position;
			bool					_selected;

		};

		MainMenu();
		~MainMenu() = default;

	    bool	update(std::chrono::nanoseconds deltaT, std::chrono::seconds upTime) override;
		void	handleKey(int32_t key) override;
    	void    setGraphic(IGraphic &handler) override;
		void	onEnable() override;
		void	onDisable() override;

		const std::string	&getGame() const;
		const std::string	&getGlib() const;

		bool	hasSelectedGame() const;
		bool	hasSelectedGlib() const;

	protected:
	private:

		void	refresh();
		void	incGameCursor(bool reverse = false);
		void	incGlibCursor(bool reverse = false);

		DirectoryMenu	_gameList;
		DirectoryMenu	_glibList;
		Cursor			_gameCursor;
		Cursor			_glibCursor;
		IGraphic		*_screen;

		DisplayablePtr			_emptyEntity;

		std::unordered_map<int32_t, Action>	_keyBinds;

};

#endif /* !MAINMENU_HPP_ */
