#include "Value.h"
#include <iostream>

Value::Value(std::string value) : Action(value){
}

void Value::execute(){
	Action::execute();
	std::cerr << message() << std::endl;
}

