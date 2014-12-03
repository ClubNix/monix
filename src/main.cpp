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
	
	MessageParser parser;
	Action *action = MessageParser::getAction("member:add:cirno");
	action->execute();
	delete action;
	Socket socket;
	socket.receive();
	return EXIT_SUCCESS;
}
