#ifndef __value_H__
#define __value_H__
#include "Action.h"

class Value : public Action{
public:
	Value(std::string);
	void execute();
};

#endif /* __value_H__ */

