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

void MongoWrapper::removeUser(std::vector<std::string> parameter){
	std::string pseudo(parameter[0]);
	database().removeUser(pseudo);
}

void MongoWrapper::renameUser(std::vector<std::string> parameter){
	std::string oldPseudo(parameter[0]);
	std::string newPseudo(parameter[1]);
	database().renameUser(oldPseudo, newPseudo);
}

void MongoWrapper::setUserBalance(std::vector<std::string> parameter){
	std::string pseudo(parameter[0]);
	float money = std::stof(parameter[1]);
	database().setUserBalance(pseudo, money);
}

void MongoWrapper::incUserBalance(std::vector<std::string> parameter){
	std::string pseudo(parameter[0]);
	float money = std::stof(parameter[1]);
	database().incUserBalance(pseudo, money);
}

void MongoWrapper::decUserBalance(std::vector<std::string> parameter){
	std::string pseudo(parameter[0]);
	float money = std::stof(parameter[1]);
	database().decUserBalance(pseudo, money);
}

void MongoWrapper::incUserBalanceByOne(std::vector<std::string> parameter){
	std::string pseudo(parameter[0]);
	database().incUserBalanceByOne(pseudo);
}

void MongoWrapper::decUserBalanceByOne(std::vector<std::string> parameter){
	std::string pseudo(parameter[0]);
	database().decUserBalanceByOne(pseudo);
}

void MongoWrapper::displayMembers(std::vector<std::string> parameter){
	database().displayMembers();
}

void MongoWrapper::displaySum(std::vector<std::string> parameter){
	database().displaySum();
}

