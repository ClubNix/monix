#include <cstdlib>
#include <iostream>
#include "MessageParser.h"
#include "Socket.h"
#include "Mongo.h"
#include "RPC.h"
#include "MongoWrapper.h"

int main(int argc, char* argv[]){
	Mongo database;

	database.displayMembers();
	database.renameUser("Mute","Fira");
	database.displayMembers();

	RPC rpc;
	rpc.subscribeFunction("addUser",MongoWrapper::addUser);
	rpc.subscribeFunction("removeUser",MongoWrapper::removeUser);
	rpc.subscribeFunction("renameUser",MongoWrapper::renameUser);
	rpc.subscribeFunction("setUserBalance",MongoWrapper::setUserBalance);
	rpc.subscribeFunction("incUserBalance",MongoWrapper::incUserBalance);
	rpc.subscribeFunction("decUserBalance",MongoWrapper::decUserBalance);
	rpc.subscribeFunction("incUserBalanceByOne",MongoWrapper::incUserBalanceByOne);
	rpc.subscribeFunction("decUserBalanceByOne",MongoWrapper::decUserBalanceByOne);
	rpc.subscribeFunction("displayMembers",MongoWrapper::displayMembers);
	rpc.subscribeFunction("displaySum",MongoWrapper::displaySum);

	Socket socket(argv[0], ZMQ_PULL);
	std::string message;
	int end = socket >> message;
	while(!end){
		std::string message = socket.message();
		std::string functionName = rpc.getFunctionName(message);
		std::vector<std::string> parameter = rpc.getParameter(message);
		rpc.execute(functionName, parameter);
		end = socket >> message;
	}
	
	return EXIT_SUCCESS;
}
