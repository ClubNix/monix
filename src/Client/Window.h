#ifndef __Window_H__
#define __Window_H__

#include <menu.h>

class Window{
	WINDOW *window_;
	Window *parent_;
public:
	Window(Window *parent=nullptr) : parent_(parent){}
	
	WINDOW* window(){
		return window_;
	}
	
	void window(WINDOW *window){
		window_ = window;
	}
	
	Window* parent(){
		return parent_;
	}
};

#endif /* __Window_H__ */

