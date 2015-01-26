#include "MongoWrapper.h"

Mongo& MongoWrapper::database(){
	static Mongo database;
	return database;
}

void MongoWrapper::addUser(std::vector<std::string> parameter){
	std::string pseudo(parameter[0]);
	float money = std::stof(parameter[1]);
	database().addUser(pseudo, money);
}

