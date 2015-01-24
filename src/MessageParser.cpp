#include <regex>
#include <iostream>
#include "MessageParser.h"
#include "Action.h"
#include "Parameter.h"
#include "Value.h"
#include "Member.h"


Action* MessageParser::getAction(std::string message){
	std::regex regexp("(\\w*):");
	std::smatch match;
	if(std::regex_search(message, match, regexp)){
		Action *action = nullptr;
		Action *newAction = nullptr;
		while(std::regex_search(message, match, regexp)){
			std::string parsedMessage(match[1]);
			if(parsedMessage == "member"){
				newAction = new Member();
			}else if(parsedMessage == "account"){
				newAction = new Parameter(parsedMessage);
			}else if(parsedMessage == "stock"){
				newAction = new Parameter(parsedMessage);
			}else if(parsedMessage == "log"){
				newAction = new Parameter(parsedMessage);
			}else if(parsedMessage == "add"){
				newAction = new Parameter(parsedMessage);
			}else{
				//if we don't know the word, it's a value
				newAction = new Value(message);
				newAction->parameter(action);
				action = newAction;
				return action;
			}
			newAction->parameter(action);
			action = newAction;			
			message = match.suffix().str();
		}
		//last part of message is always a value (member:add:<cirno>)
		newAction = new Value(message);
		newAction->parameter(action);
		action = newAction;
		return action;
	}else{
		return nullptr;
	}
}

