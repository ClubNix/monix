#include <cstdlib>
#include <cassert>
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

void Mongo::renameUser(std::string pseudo, std::string newPseudo){
	auto_ptr<DBClientCursor> cursor = connection_->query(dbName_, BSONObj());
	std::string currentPseudo = "";
	while(cursor->more()){
		BSONObj obj = cursor->next();
		currentPseudo = obj.getStringField("_id");
		std::cout << currentPseudo << std::endl;
		if(currentPseudo == newPseudo){
			std::cout << "Error: The new pseudo already exists" << std::endl;
			return;
		}
	}
	float savedMoney = getUserBalance(pseudo);
	removeUser(pseudo);
	addUser(newPseudo, savedMoney);
}

void Mongo::setUserBalance(std::string pseudo, float money){
	connection_->update(
		dbName_,
		BSON("_id" << pseudo),
		BSON("$set" << BSON("money" << money))
	);
}

void Mongo::incUserBalance(std::string pseudo, float money){
	assert(money >= 0);
	connection_->update(
		dbName_,
		BSON("_id" << pseudo),
		BSON("$inc" << BSON("money" << money))
	);
}

void Mongo::incUserBalanceByOne(std::string pseudo){
	incUserBalance(pseudo, 1);
}

void Mongo::decUserBalance(std::string pseudo, float money){
	assert(money >= 0);
	money *= -1;
	connection_->update(
		dbName_,
		BSON("_id" << pseudo),
		BSON("$inc" << BSON("money" << money))
	);
}

void Mongo::decUserBalanceByOne(std::string pseudo){
	decUserBalance(pseudo, 1);
}

void Mongo::displayMembers(){
	auto_ptr<DBClientCursor> cursor = connection_->query(dbName_, BSONObj());
	while(cursor->more()){
		BSONObj p = cursor->next();
		std::cout << p.toString() << std::endl;
	}
}

void Mongo::displaySum(){
	auto_ptr<DBClientCursor> cursor = connection_->query(dbName_, BSONObj());
	float sum;
	while(cursor->more()){
		BSONObj p = cursor->next();
		float value = p.getField("money").number();
		sum += value;
	}
	std::cout << "Sum: " << sum << std::endl;
}

float Mongo::getUserBalance(std::string pseudo){
	auto_ptr<DBClientCursor> cursor = connection_->query(dbName_, QUERY("_id" << pseudo));
	BSONObj obj = cursor->next();
	float money = obj.getField("money").number();
	return money;
}
