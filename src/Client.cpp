#include <cstdlib>
#include <iostream>
#include "MessageParser.h"
#include "Socket.h"
#include "Mongo.h"
#include "RPC.h"
#include "MongoWrapper.h"

int main(int argc, char* argv[]){
	Mongo database;

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

	Socket socket(argv[0], ZMQ_PUSH);
	int send = socket.send("addUser(Flandre,18)");
	socket.send("displayMembers()");
	
	return EXIT_SUCCESS;
}
