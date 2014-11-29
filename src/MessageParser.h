#ifndef __MessageParser_H__
#define __MessageParser_H__

#include <string>

class MessageParser{
public:
	enum Action{
		MEMBER,
		STOCK,
		ACCOUNT,
		LOG,
		UNKNOWN
	};
	
	std::string getAction(std::string message);
	
};

#endif /* __MessageParser_H__ */

