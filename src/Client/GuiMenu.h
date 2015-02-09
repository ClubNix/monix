#ifndef __GuiMenu_H__
#define __GuiMenu_H__
#include <menu.h>
#include <vector>

class GuiMenu{
	std::vector<ITEM*> item_;
	MENU *menu_;
	WINDOW *menuWindows_;
	int rows_;
	int cols_;
	
	
public:
	GuiMenu(int rows, int cols, WINDOW *parent=stdscr);
	void addItem(const char* name, const char* description);
	void createMenu();
	void up() const;
	void down() const;
	virtual ~GuiMenu();
};

#endif /* __GuiMenu_H__ */

