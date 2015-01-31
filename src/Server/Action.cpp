#include "Action.h"
#include <iostream>

Action::Action(std::string message) : message_(message){
	parameter_ = nullptr;
}

std::string Action::message() const{
	return message_;
}

void Action::parameter(Action *parameter){
	parameter_ = parameter;
}

Action::~Action(){
	if(parameter_ != nullptr){
		delete parameter_;
	}
}

void Action::execute(){
	if(parameter_ != nullptr){
		parameter_->execute();
	}
}

