#include <cstdlib>
#include <iostream>
#include "mongo/client/dbclient.h"
#include "MessageParser.h"
#include "Socket.h"

void run(){
	mongo::DBClientConnection c;
	c.connect("localhost");
}

int main(){
	//client::initialize();
	try{
		run();
		std::cout << "connected ok" << std::endl;
	} catch(const mongo::DBException &e){
		std::cout << "caught" << e.what() << std::endl;
	}
	
	Socket socket;
	int end = socket.receive();
	while(!end){
		Action *action = MessageParser::getAction(socket.message());
		action->execute();
		delete action;
		end = socket.receive();
	}
	return EXIT_SUCCESS;
}
