#include <cstdlib>
#include <iostream>
#include <string>
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

void Mongo::setMoney(std::string pseudo, float money){
	connection_->update(
		dbName_,
		BSON("_id" << pseudo),
		BSON("$set" << BSON("money" << money))
	);
}

void Mongo::incMoney(std::string pseudo, float money){
	connection_->update(
		dbName_,
		BSON("_id" << pseudo),
		BSON("$inc" << BSON("money" << money))
	);
}

void Mongo::displayMembers(){
	auto_ptr<DBClientCursor> cursor = connection_->query(dbName_, BSONObj());
	float sum;
	while(cursor->more()){
		BSONObj p = cursor->next();
		float value = p.getField("money").number();
		sum += value;
	}
	std::cout << "Sum: " << sum << std::endl;
}
