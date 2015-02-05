#ifndef __Gui_H__
#define __Gui_H__

#include <string>

class Gui{
enum{
	RED = 1,
	GREEN
};

public:
	Gui();
	void mvprintw(int y, int x, std::string message, int color = GREEN);
	void operator>>(int &ch);
	~Gui();
};

#endif /* __Gui_H__ */

