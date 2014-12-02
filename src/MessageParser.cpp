#include "MessageParser.h"
#include <regex>

std::string MessageParser::getAction(std::string message){
	std::regex regexp("(\\w*):");
	std::smatch match;
	if(std::regex_search(message, match, regexp)){ // while ça -> decorer
		std::string parsedMessage;
		while(std::regex_search(message, match, regexp)){
			parsedMessage += std::string(match[1]) + std::string(" | ");
			message = match.suffix().str();
		}
		return parsedMessage + message;
	}else{
		return "";
	}
}

