#include <string>
#include <iostream>
#include <ncurses.h>
#include "ClientSocket.h"
#include "Gui.h"
#include "GuiMenu.h"
#include "ClientParser.h"

int main(int argc, char* argv[]){
	ClientSocket& socket = *(new ClientSocket());
//	socket << std::string("addUser(Flandre,18)");
	socket << std::string("displayMembers()");
//	socket << std::string("getUserBalance(Flandre)");
	std::string response;
	socket >> response;
	delete &socket;
//	std::string response = "Flandre : 18";
	Gui gui;
	
//	gui.mvprintw(LINES/2, COLS/3, response.c_str());
	gui.debugPrint("miaou");
	ClientParser::NameMoneyList userList = ClientParser::parse(response);
	
	for(auto user : userList){
		gui.getMenu().addItem(user.first.c_str(), user.second.c_str());
	}
	gui.getMenu().createMenu();

	int ch;
	do{
		gui >> ch;
		switch(ch){
			case KEY_DOWN:
				gui.getMenu().down();
				break;
			
			case KEY_UP:
				gui.getMenu().up();
				break;
			case '+':
				gui.getMenu()++;
				break;
				
			case '-':
				gui.getMenu()--;
				break;
				
			default:
				gui.debugPrint(std::to_string(ch));
				break;
		}
	}while(ch != 'q');
//	socket << std::string("quit");
	return EXIT_SUCCESS;
}
