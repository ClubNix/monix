#include <cstdlib>
#include <iostream>
#include "mongo/client/dbclient.h"
#include "mongo.h"

using namespace mongo;

int main(){
	Mongo database;
    // database.setMoney("Mute", 8);
	database.displayMembers();
	
	return 0;
}
