#ifndef __GuiMenu_H__
#define __GuiMenu_H__
#include <menu.h>
#include <vector>

class GuiMenu{
	std::vector<ITEM*> item_;
	MENU *menu_;
public:
	void addItem(const char* name, const char* description);
	void createMenu();
	void up() const;
	void down() const;
	virtual ~GuiMenu();
};

#endif /* __GuiMenu_H__ */

