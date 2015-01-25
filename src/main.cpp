#include <cstdlib>
#include <iostream>
#include "mongo/client/dbclient.h"
#include "MessageParser.h"
#include "Socket.h"
#include "mongo.h"
#include "RPC.h"

int main(){
	//client::initialize();
	Mongo database;
	database.addUser("Nepta", 9);
	
	Socket socket;
//	int end = socket.receive();
//	while(!end){
//		Action *action = MessageParser::getAction(socket.message());
//		action->execute();
//		std::cerr << std::endl;
//		delete action;
//		end = socket.receive();
//	}
	RPC rpc;
	std::string functionString("addMember('Nepta',9)");
	std::cout << "functionName: " << rpc.getFunctionName(functionString) << std::endl;
	for(std::string s : rpc.getParameter(functionString)){
		std::cout << s << " ";
	}
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
