#ifndef __Gui_H__
#define __Gui_H__

#include <string>

class Gui{
public:
	enum{
		RED = 1,
		GREEN
	};

public:
	Gui();
	void mvprintw(int y, int x, std::string message, int color = GREEN);
	void operator>>(int &ch);
	void debugPrint(std::string message);
	~Gui();
};

#endif /* __Gui_H__ */

