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
	#include "Types.hpp"

class MainMenu : public IGame {
	public:

		MainMenu(IGraphic &handler);
		~MainMenu() = default;

		typedef	std::unique_ptr<IDisplayable>	DisplayablePtr;

		struct Position2F {
			float	x;
			float	y;
		};

		class Cursor {
			public:

			Cursor(DirectoryMenu &directory, IDisplayable *entity, Position2F position);

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

			DirectoryMenu			*_directory;
			DirectoryMenu::iterator	_iterator;
			DisplayablePtr			_entity;
			Position2F				_position;
			const Position2F		_initPosition;
			bool					_selected;

		};


	    bool	update(std::chrono::nanoseconds deltaT, std::chrono::seconds upTime) override;
		void	handleKey(int32_t key) override;
    	void    setGraphic(IGraphic &handler) override;
		void	onEnable() override;
		void	onDisable() override;

		const std::string	&getGame() const;
		const std::string	&getGlib() const;

		bool	hasSelectedGame() const;
		bool	hasSelectedGlib() const;

		void	endSelect();

		typedef std::function<void ()>	Action;

	protected:
	private:

		void	refresh();

		DirectoryMenu	_gameList;
		DirectoryMenu	_glibList;
		IGraphic		*_screen;
		Vector2<int>	_boardSize;
		Cursor			_gameCursor;
		Cursor			_glibCursor;

		std::unordered_map<int32_t, Action>	_keyBinds;

};

#endif /* !MAINMENU_HPP_ */
