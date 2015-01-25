#include "MongoWrapper.h"

void MongoWrapper::addUser(std::vector<std::string> parameter){
	std::string pseudo(parameter[0]);
	float money = std::stof(parameter[1]);
	std::cout << "addUser -> "<< pseudo << " : " << money << std::endl;
}

