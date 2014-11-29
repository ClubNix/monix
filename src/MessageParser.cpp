#include "MessageParser.h"
#include <regex>

std::string MessageParser::getAction(std::string message){
	std::regex regexp("(\\w*):");
	std::smatch match;
	if(std::regex_search(message, match, regexp)){
		return match[1];
	}else{
		return "";
	}
}

