#include <ncurses.h>
#include <menu.h>
#include <iostream>
#include "Gui.h"
#include "GuiMenu.h"
#include "ClientSocket.h"
#include "ClientParser.h"

Gui::Gui(){
	initscr();
	window(stdscr);
	raw();
	keypad(window(), TRUE);
	noecho();
	start_color();
	use_default_colors();
	init_pair(Gui::RED, COLOR_RED, -1);
	init_pair(Gui::GREEN, COLOR_GREEN, -1);
	
	attron(COLOR_PAIR(RED));
	box(window(),0,0);
	attroff(COLOR_PAIR(RED));
	
	menu_ = new GuiMenu(this, LINES, COLS/2);
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

GuiMenu& Gui::getMenu(){
	return *menu_;
}

void Gui::getMembers(){
	delete menu_;
	menu_ = new GuiMenu(this, LINES, COLS/2);
	
	ClientSocket& socket = *(new ClientSocket());
	socket << std::string("displayMembers()");
	std::string response;
	socket >> response;
	delete &socket;
	
	ClientParser::NameMoneyList userList = ClientParser::parse(response);
	for(auto user : userList){
		getMenu().addItem(user.first.c_str(), user.second.c_str());
	}
	getMenu().createMenu();
}

Gui::~Gui(){
	delete menu_;
	endwin();
}


