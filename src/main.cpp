#include <cstdlib>
#include <iostream>
#include "MessageParser.h"
#include "Socket.h"
#include "mongo.h"
#include "RPC.h"
#include "MongoWrapper.h"

int main(){
	Mongo database;

	database.displayMembers();
	database.renameUser("Mute","Fira");
	database.displayMembers();

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
	rpc.subscribleFunction("addUser",MongoWrapper::addUser);
	rpc.execute("miaou",{"42"});
	rpc.execute("addUser",{"'Nepta'","9"});
	return EXIT_SUCCESS;
}
