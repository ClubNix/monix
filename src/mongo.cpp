#include <cstdlib>
#include <iostream>
#include "mongo/client/dbclient.h"

#include "mongo.h"

using namespace mongo;

Mongo::Mongo(){
	dbName_ = "nix.monix";
    connection_ = new DBClientConnection();
	try{
		connection_->connect("localhost");
		std::cout << "connected ok" << std::endl;
	} catch(const DBException &e){
		std::cout << "caught" << e.what() << std::endl;
        exit(-1);
	}
}

void Mongo::addUser(std::string pseudo, float money){
    BSONObjBuilder builder;
    builder.append("_id", pseudo);
    builder.append("money", money);
    connection_->insert(dbName_, builder.obj());
}

void Mongo::removeUser(std::string pseudo){
    BSONObjBuilder builder;
    builder.append("_id", pseudo);
    connection_->remove(dbName_, builder.obj());
}
