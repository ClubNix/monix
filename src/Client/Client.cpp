#include <string>
#include "../Server/Socket.h"

int main(int argc, char* argv[]){
	Socket socket("client", ZMQ_PUSH);
	socket << std::string("addUser(Flandre,18)");
	socket << std::string("displayMembers()");
	socket << std::string("quit");
	return EXIT_SUCCESS;
}
