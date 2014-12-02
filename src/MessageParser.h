#ifndef __MessageParser_H__
#define __MessageParser_H__
#include "Action.h"
#include <string>

class MessageParser{
public:
	static std::string getAction(std::string message);
};

#endif /* __MessageParser_H__ */

