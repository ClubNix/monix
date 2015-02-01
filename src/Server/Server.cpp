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
	rpc.subscribeFunction("getUserBalance",MongoWrapper::getUserBalance);

	Socket socket("server");
	std::string message;
	int end = socket >> message;
	while(!end){
		std::string functionName = rpc.getFunctionName(message);
		std::vector<std::string> parameter = rpc.getParameter(message);
		std::string result = rpc.execute(functionName, parameter);
		if(result != ""){
			std::cout << result << std::endl;
		}
		end = socket >> message;
	}
	return EXIT_SUCCESS;
}
