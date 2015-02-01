#include <string>
#include <iostream>
#include "../Server/Socket.h"
#include <ncurses.h>

int main(int argc, char* argv[]){
	Socket socket("client");
	socket << std::string("addUser(Flandre,18)");
	socket << std::string("displayMembers()");
	socket << std::string("getUserBalance(Flandre)");
	std::string response;
	socket >> response;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	
	attron(COLOR_PAIR(1));
	box(stdscr,0,0);
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
	mvprintw(LINES/2, COLS/2, response.c_str());
	attroff(COLOR_PAIR(2));
	refresh();
	getch();
	endwin();
	
	socket << std::string("quit");
	return EXIT_SUCCESS;
}
