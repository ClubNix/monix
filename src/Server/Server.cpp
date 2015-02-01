#include <iostream>
#include "Socket.h"
#include "Mongo.h"
#include "RPC.h"
#include "MongoWrapper.h"

int main(int argc, char* argv[]){
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

	Socket socket("server", ZMQ_PULL);
	std::string message;
	int end = socket >> message;
	while(!end){
		std::string functionName = rpc.getFunctionName(message);
		std::vector<std::string> parameter = rpc.getParameter(message);
		rpc.execute(functionName, parameter);
		end = socket >> message;
	}
	std::cout << MongoWrapper::getUserBalance({"Cirno"}) << std::endl;
	return EXIT_SUCCESS;
}
