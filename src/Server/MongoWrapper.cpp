#include "MongoWrapper.h"

Mongo& MongoWrapper::database(){
	static Mongo database;
	return database;
}

std::string MongoWrapper::addUser(std::vector<std::string> parameter){
	std::string pseudo(parameter[0]);
	float money = std::stof(parameter[1]);
	database().addUser(pseudo, money);
	return "";
}

std::string MongoWrapper::removeUser(std::vector<std::string> parameter){
	std::string pseudo(parameter[0]);
	database().removeUser(pseudo);
	return "";
}

std::string MongoWrapper::renameUser(std::vector<std::string> parameter){
	std::string oldPseudo(parameter[0]);
	std::string newPseudo(parameter[1]);
	database().renameUser(oldPseudo, newPseudo);
	return "";
}

std::string MongoWrapper::setUserBalance(std::vector<std::string> parameter){
	std::string pseudo(parameter[0]);
	float money = std::stof(parameter[1]);
	database().setUserBalance(pseudo, money);
	return "";
}

std::string MongoWrapper::incUserBalance(std::vector<std::string> parameter){
	std::string pseudo(parameter[0]);
	float money = std::stof(parameter[1]);
	database().incUserBalance(pseudo, money);
	return "";
}

std::string MongoWrapper::decUserBalance(std::vector<std::string> parameter){
	std::string pseudo(parameter[0]);
	float money = std::stof(parameter[1]);
	database().decUserBalance(pseudo, money);
	return "";
}

std::string MongoWrapper::incUserBalanceByOne(std::vector<std::string> parameter){
	std::string pseudo(parameter[0]);
	database().incUserBalanceByOne(pseudo);
	return "";
}

std::string MongoWrapper::decUserBalanceByOne(std::vector<std::string> parameter){
	std::string pseudo(parameter[0]);
	database().decUserBalanceByOne(pseudo);
	return "";
}

std::string MongoWrapper::displayMembers(std::vector<std::string> parameter){
	std::string response = database().displayMembers();
	return response;
}

std::string MongoWrapper::displaySum(std::vector<std::string> parameter){
	database().displaySum();
	return "";
}

std::string MongoWrapper::getUserBalance(std::vector<std::string> parameter){
	float money = database().getUserBalance(parameter[0]);
	return std::to_string(money);
}

