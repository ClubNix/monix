#include "Member.h"
#include <iostream>

Member::Member() : Action("member"){
}

void Member::execute(){
//	Action::execute();
	std::cerr << message() << " -> ";
}

