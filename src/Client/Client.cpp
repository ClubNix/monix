#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "ClientSocket.h"
#include "ClientParser.h"

int main(int argc, char* argv[]){
	ClientSocket& socket = *(new ClientSocket());
//	socket << std::string("addUser(Flandre,18)");
	socket << std::string("displayMembers()");
//	socket << std::string("getUserBalance(Flandre)");
	std::string response;
	socket >> response;
	delete &socket;
	
	sf::RenderWindow gui(
		sf::VideoMode(480, 320),
		"Monix - Client"
	);

	while(gui.isOpen()){
		sf::Event event;
		while(gui.pollEvent(event)){
			switch(event.type){
				case sf::Event::Closed:
					gui.close();
					break;
				default:
					break;
			}
		}
		
		gui.clear(sf::Color::Black);
		gui.display();
		
	}
//	socket << std::string("quit");
	return EXIT_SUCCESS;
}
