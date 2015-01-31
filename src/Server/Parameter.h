#ifndef __parameter_H__
#define __parameter_H__
#include "Action.h"

class Parameter : public Action{
public:
	Parameter(std::string);
	virtual void execute();
};

#endif /* __parameter_H__ */

