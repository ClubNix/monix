#ifndef __Window_H__
#define __Window_H__

#include <menu.h>

class Window{
	WINDOW *window_;

public:
	Window(WINDOW *window=stdscr) : window_(window){}
	
	WINDOW* window(){
		return window_;
	}
	
	void window(WINDOW *window){
		window_ = window;
	}
};

#endif /* __Window_H__ */

