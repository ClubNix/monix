#include <string>
#include <iostream>
#include <ncurses.h>
#include "../Server/Socket.h"
#include "Gui.h"
#include "GuiMenu.h"
#include "ClientParser.h"

int main(int argc, char* argv[]){
	Socket socket("client");
//	socket << std::string("addUser(Flandre,18)");
	socket << std::string("displayMembers()");
//	socket << std::string("getUserBalance(Flandre)");
	std::string response;
	socket >> response;
//	std::string response = "Flandre : 18";
	Gui gui;
	
//	gui.mvprintw(LINES/2, COLS/3, response.c_str());
	gui.debugPrint("miaou");
	ClientParser::NameMoneyList userList = ClientParser::parse(response);
	GuiMenu menu(LINES, COLS/2);
	for(auto user : userList){
		menu.addItem(user.first.c_str(), user.second.c_str());
	}
	menu.createMenu();

	int ch;
	gui >> ch;
	menu.down();
	gui >> ch;
//	socket << std::string("quit");
	return EXIT_SUCCESS;
}
