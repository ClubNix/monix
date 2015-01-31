#ifndef __action_H__
#define __action_H__

#include <string>

class Action{
	std::string message_;
	Action *parameter_;
public:
	Action(std::string message);
	std::string message() const;
	void parameter(Action* parameter);
	virtual void execute();
	virtual ~Action();
};

#endif /* __action_H__ */

