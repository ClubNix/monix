#include <string>
#include <iostream>
#include <ncurses.h>
#include "../Server/Socket.h"
#include "Gui.h"


int main(int argc, char* argv[]){
//	Socket socket("client");
//	socket << std::string("addUser(Flandre,18)");
//	socket << std::string("displayMembers()");
//	socket << std::string("getUserBalance(Flandre)");
//	std::string response;
//	socket >> response;
	std::string response = "Flandre : 18";
	Gui gui;
	
	gui.mvprintw(LINES/2, COLS/3, response.c_str());
	gui.createDummyMenu(LINES/2, 2*COLS/3);
	int ch;
	gui >> ch;
	
//	socket << std::string("quit");
	return EXIT_SUCCESS;
}
