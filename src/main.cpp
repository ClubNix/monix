#include <cstdlib>
#include <iostream>
#include "mongo/client/dbclient.h"
#include "MessageParser.h"
#include "Socket.h"
#include "mongo.h"

int main(){
	//client::initialize();
	Mongo database;
	database.addUser("Nepta", 9);
	
	Socket socket;
	int end = socket.receive();
	while(!end){
		Action *action = MessageParser::getAction(socket.message());
		action->execute();
		std::cerr << std::endl;
		delete action;
		end = socket.receive();
	}
	return EXIT_SUCCESS;
}
