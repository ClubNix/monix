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
	rpc.subscribleFunction("removeUser",MongoWrapper::removeUser);
	rpc.subscribleFunction("renameUser",MongoWrapper::renameUser);
	rpc.subscribleFunction("setUserBalance",MongoWrapper::setUserBalance);
	rpc.subscribleFunction("incUserBalance",MongoWrapper::incUserBalance);
	rpc.subscribleFunction("decUserBalance",MongoWrapper::decUserBalance);
	rpc.subscribleFunction("incUserBalanceByOne",MongoWrapper::incUserBalanceByOne);
	rpc.subscribleFunction("decUserBalanceByOne",MongoWrapper::decUserBalanceByOne);
	rpc.subscribleFunction("displayMembers",MongoWrapper::displayMembers);
	rpc.subscribleFunction("displaySum",MongoWrapper::displaySum);
	
	rpc.execute("miaou",{"42"});
	rpc.execute("addUser",{"Nepta","9"});
	rpc.execute("decUserBalanceByOne",{"Nepta"});
	rpc.execute("displaySum",{});
	return EXIT_SUCCESS;
}
