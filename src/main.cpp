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

	Socket socket;
	int end = socket.receive();
	while(!end){
		std::string message = socket.message();
		std::string functionName = rpc.getFunctionName(message);
		std::vector<std::string> parameter = rpc.getParameter(message);
		rpc.execute(functionName, parameter);
		end = socket.receive();
	}
	
	return EXIT_SUCCESS;
}
