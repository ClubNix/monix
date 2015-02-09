#ifndef __GuiMenu_H__
#define __GuiMenu_H__
#include <menu.h>
#include <vector>
#include "Window.h"

class GuiMenu : public Window{
	std::vector<ITEM*> item_;
	MENU *menu_;
	int rows_;
	int cols_;
	
public:
	GuiMenu(Window *parent, int rows, int cols);
	void addItem(const char* name, const char* description);
	void createMenu();
	void up() const;
	void down() const;
	GuiMenu& operator--(int);
	GuiMenu& operator++(int);
	virtual ~GuiMenu();
};

#endif /* __GuiMenu_H__ */

