#include "Gui.h"
#include <ncurses.h>
#include <menu.h>
#include <iostream>

Gui::Gui(){
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	use_default_colors();
	init_pair(Gui::RED, COLOR_RED, -1);
	init_pair(Gui::GREEN, COLOR_GREEN, -1);
	
	attron(COLOR_PAIR(RED));
	box(stdscr,0,0);
	attroff(COLOR_PAIR(RED));
}


void Gui::mvprintw(int y, int x, std::string message, int color){
	attron(COLOR_PAIR(color));
	::mvprintw(y, x, message.c_str());
	attroff(COLOR_PAIR(color));
	refresh();
}

void Gui::debugPrint(std::string message){
	mvprintw(LINES-1, 1, "                                                                                    ");
	mvprintw(LINES-1, 1, message);
	refresh();
}


void Gui::operator>>(int &ch){
	ch = getch();
}

Gui::~Gui(){
	endwin();
}


