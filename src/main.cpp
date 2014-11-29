#include <cstdlib>
#include <iostream>
#include "mongo/client/dbclient.h"
#include "MessageParser.h"

using namespace mongo;

void run(){
	DBClientConnection c;
	c.connect("localhost");
}

int main(){
	//client::initialize();
	try{
		run();
		std::cout << "connected ok" << std::endl;
	} catch(const DBException &e){
		std::cout << "caught" << e.what() << std::endl;
	}
	
	MessageParser parser;
	std::cout << parser.getAction("member:add:cirno") << std::endl;
	
	return EXIT_SUCCESS;
}
