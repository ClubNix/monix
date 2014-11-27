#include <cstdlib>
#include <iostream>
#include "mongo/client/dbclient.h"

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
	return EXIT_SUCCESS;
}
