#ifndef __rpc_H__
#define __rpc_H__

#include <unordered_map>


class RPC{
	typedef void (*function)(std::string);
	std::unordered_map<std::string, function> subscribedFunction_;

public:
	std::string getFunctionName(std::string functionString);
	std::vector<std::string> getParameter(std::string functionString);
	void subscribleFunction(std::string functionName, void (*function)(std::string));
	bool isAnExistingFunction(std::string functionName);
	std::vector<std::string> split(std::string s, std::string delimiter);
};

#endif /* __rpc_H__ */

