#include <cstdlib>
#include <iostream>
#include "mongo/client/dbclient.h"
#include "mongo.h"

using namespace mongo;

int main(){
	Mongo database;

	database.displayMembers();
	database.decUserBalance("Obsi", 1);
	database.displayMembers();
	database.incUserBalanceByOne("Obsi");
	database.displayMembers();

	return 0;
}
