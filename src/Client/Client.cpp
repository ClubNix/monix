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
	printw(response.c_str());
	refresh();
	getch();
	endwin();
	
	socket << std::string("quit");
	return EXIT_SUCCESS;
}
