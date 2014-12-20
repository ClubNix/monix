#include <regex>
#include <iostream>
#include "MessageParser.h"
#include "Action.h"
#include "Parameter.h"
#include "Value.h"

Action* MessageParser::getAction(std::string message){
	std::regex regexp("(\\w*):");
	std::smatch match;
	if(std::regex_search(message, match, regexp)){
		Action *action = nullptr;
		while(std::regex_search(message, match, regexp)){
			std::string parsedMessage(match[1]);
			if(parsedMessage == "member"){
				Action *newAction = new Parameter(parsedMessage);
				newAction->parameter(action);
				action = newAction;
			}else if(parsedMessage == "account"){
				Action *newAction = new Parameter(parsedMessage);
				newAction->parameter(action);
				action = newAction;
			}else if(parsedMessage == "stock"){
				Action *newAction = new Parameter(parsedMessage);
				newAction->parameter(action);
				action = newAction;
			}else if(parsedMessage == "log"){
				Action *newAction = new Parameter(parsedMessage);
				newAction->parameter(action);
				action = newAction;
			}else if(parsedMessage == "add"){
				Action *newAction = new Parameter(parsedMessage);
				newAction->parameter(action);
				action = newAction;
			}else{
				Action *newAction = new Value(parsedMessage);
				newAction->parameter(action);
				action = newAction;
			}
			message = match.suffix().str();
		}
		Action *newAction = new Value(message);
		newAction->parameter(action);
		action = newAction;
		return action;
	}else{
		return nullptr;
	}
}

