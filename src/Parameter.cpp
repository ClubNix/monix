#include "Parameter.h"
#include <iostream>

Parameter::Parameter(std::string parameter) : Action(parameter){
}

void Parameter::execute(){
	Action::execute();
	std::cerr << message() << " -> ";
}

