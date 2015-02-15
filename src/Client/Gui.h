#ifndef __Gui_H__
#define __Gui_H__

#include <string>
#include "Window.h"
#include "GuiMenu.h"

class Gui : public Window{
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
	GuiMenu& getMenu();
	void getMembers();
	~Gui();
	
private:
	GuiMenu* menu_;
};

#endif /* __Gui_H__ */

