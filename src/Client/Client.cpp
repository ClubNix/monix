#include <string>
#include <iostream>
#include <ncurses.h>
#include "../Server/Socket.h"
#include "Gui.h"
#include "GuiMenu.h"



int main(int argc, char* argv[]){
	Socket socket("client");
//	socket << std::string("addUser(Flandre,18)");
	socket << std::string("displayMembers()");
//	socket << std::string("getUserBalance(Flandre)");
	std::string response;
	socket >> response;
	std::cout << response;
//	std::string response = "Flandre : 18";
//	Gui gui;
//	
//	gui.mvprintw(LINES/2, COLS/3, response.c_str());


//	GuiMenu menu;
//	menu.addItem("Cirno","ice fairy");
//	menu.addItem("Suwako","frog");
//	menu.createMenu();

//	int ch;
//	gui >> ch;
//	menu.down();
//	gui >> ch;
	socket << std::string("quit");
	return EXIT_SUCCESS;
}
