#include <regex>
#include <iostream>
#include "RPC.h"

std::string RPC::getFunctionName(std::string functionString){
	std::smatch match;
	try{
		std::regex regexp("\\.?(\\w*?)\\(");
		std::regex_search(functionString, match, regexp);
	}catch(std::regex_error& e){
		std::cerr << "chat" << e.code() << std::endl;
	}
	return match[1];
}

std::vector<std::string> RPC::getParameter(std::string functionString){
	std::vector<std::string> parameterList;
	std::regex regexp("\\.?\\w*?\\((.*?)\\)");
	std::smatch match;
	std::regex_search(functionString, match, regexp);
	return split(match[1],",");
}

//code from : http://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::string> RPC::split(std::string s, std::string delimiter){
	size_t pos = 0;
	std::vector<std::string> token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		 token.push_back(s.substr(0, pos));
		 s.erase(0, pos + delimiter.length());
	}
	token.push_back(s.substr(0, pos));
	return token;
}

void RPC::subscribeFunction(std::string functionName, RPC::wrappedFunction function){
	subscribedFunction_[functionName] = function;
}

bool RPC::isAnExistingFunction(std::string functionName){
	return subscribedFunction_.count(functionName) > 0;
}

std::string RPC::execute(std::string functionName, std::vector<std::string> parameter){
	if(isAnExistingFunction(functionName)){
		return subscribedFunction_[functionName](parameter);
	}else{
		std::cerr << functionName << " doesn't exist" << std::endl;
		return "";
	}
}

