#include <menu.h>
#include <ncurses.h>
#include <string>
#include "GuiMenu.h"

void GuiMenu::addItem(const char* name, const char* description){
	item_.push_back(new_item(name, description));
}

GuiMenu::~GuiMenu(){
	for(int i=0; i<item_.size()-1; i++){
		free_item(item_[i]);
	}
	free_menu(menu_);
}

void GuiMenu::createMenu(){
	item_.push_back(NULL);
	menu_ = new_menu(item_.data());
	post_menu(menu_);
}

void GuiMenu::up() const{
	menu_driver(menu_, REQ_DOWN_ITEM);
}

void GuiMenu::down() const{
	menu_driver(menu_, REQ_DOWN_ITEM);
}

