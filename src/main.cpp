#include <cstdlib>
#include <iostream>
#include "MessageParser.h"
#include "Socket.h"
#include "mongo.h"
#include "RPC.h"
#include "MongoWrapper.h"
#include <regex>

int main(){
//	Mongo database;

//	database.displayMembers();
//	database.renameUser("Mute","Fira");
//	database.displayMembers();

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

	Socket socket;
	std::string message;
	int end = socket >> message;
	while(!end){
		std::string functionName = rpc.getFunctionName(message);
		std::vector<std::string> parameter = rpc.getParameter(message);
		std::cout << functionName << std::endl;
		for(std::string s : parameter){
			std::cout << s << std::endl;
		}
		rpc.execute(functionName, parameter);
		end = socket >> message;
	}
	return EXIT_SUCCESS;
}
