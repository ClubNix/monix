#include <cstdlib>
#include <iostream>
#include "mongo/client/dbclient.h"
#include "mongo.h"

using namespace mongo;

int main(){
	Mongo database;
	// database.setMoney("Mute", 8);
	database.renameUser("Obsi", "Nepta");
	database.displayMembers();
	// database.displaySum();
	float v = database.getMemberMoney("Nepta");
	std::cout << v << std::endl;

	return 0;
}
