#include <string>
#include <iostream>
#include "../Server/Socket.h"

int main(int argc, char* argv[]){
	Socket socket("client");
	socket << std::string("addUser(Flandre,18)");
	socket << std::string("displayMembers()");
	socket << std::string("getUserBalance(Flandre)");
	std::string response;
	socket >> response;
	std::cout << response << std::endl;
	socket << std::string("quit");
	return EXIT_SUCCESS;
}
