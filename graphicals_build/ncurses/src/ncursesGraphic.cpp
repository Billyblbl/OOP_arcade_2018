/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Graphic handler ncurses
*/

#include    "ncursesGraphic.hpp"
#include	"ncursesDisplayable.hpp"
#include	"IGame.hpp"

extern "C" {

	ncursesGraphic	*CreateHandler()
	{
		return new ncursesGraphic;
	}
}

const ncursesGraphic::translation ncursesGraphic::Translator = {
	{KEY_UP, IGame::arrowUp},
	{KEY_DOWN, IGame::arrowDown},
	{KEY_LEFT, IGame::arrowLeft},
	{KEY_RIGHT, IGame::arrowRight},
	{KEY_PPAGE, IGame::pageUp},
	{KEY_NPAGE, IGame::pageDown},
	{KEY_HOME, IGame::home},
	{KEY_END, IGame::end}
};

ncursesGraphic::ncursesGraphic() {

    initscr();
	cbreak();
	noecho();
	scrollok(win, TRUE);
	nodelay(win, TRUE);
	if (has_colors() == TRUE)
		start_color();
    win = newwin(0, 0, 0, 0);
}

ncursesGraphic::~ncursesGraphic() {
	nodelay(win, FALSE);
	scrollok(win, FALSE);
	echo();
	nocbreak();
	delwin(win);
}

void	ncursesGraphic::setEntity(float x, float y, IDisplayable &entity) {
	ncurseDisplayable	&nentity =  static_cast<ncurseDisplayable &>(entity);
	const ncursesState &state = nentity.getStateData();
	char	str[2] = {state.ascii, '\0'};
	if (has_colors() == TRUE) {
		init_color(COLOR_WHITE, state.foreground.r, state.foreground.g, state.foreground.b);
		init_color(COLOR_BLACK, state.background.r, state.background.g, state.background.b);
		init_pair(1, COLOR_WHITE, COLOR_BLACK);
		wattron(win, COLOR_PAIR(1));
	}
	mvwprintw(win, y, x, str);
	if (has_colors() == TRUE) {
		wattroff(win, COLOR_PAIR(1));
		init_color(COLOR_WHITE, 1000, 1000, 1000);
		init_color(COLOR_BLACK, 0, 0, 0);
	}
}

void    ncursesGraphic::write(int x, int y, const std::string &text) {
	//verifier que le fond est bien NWAR comme alex
    mvwprintw(win, y, x, text.c_str());
}

void    ncursesGraphic::setSize(int x, int y) {
	size.x = x;
	size.y = y;
}

bool	ncursesGraphic::update() {
	int	x;
	int y;

	getmaxyx(win, y, x);
	std::cerr << "x=" << x <<std::endl;
	std::cerr << "y=" << y <<std::endl;
	if (x < size.x || y < size.y) {
		wclear(win);
		mvwprintw(win, 0, 0, "window too small");
	}
	wrefresh(win);
	return true;
}

void	ncursesGraphic::clear() {
	wclear(win);
}

IDisplayable    *ncursesGraphic::createDisplayable(const std::string &path) {
	return new ncurseDisplayable(path);
}

bool	ncursesGraphic::hasInput() {
	input = wgetch(win);
	return (input != ERR);
}

int32_t	ncursesGraphic::getInput() {
	auto it = Translator.find(input);
	if (it != Translator.end())
		return Translator.at(input);
	return input;
}