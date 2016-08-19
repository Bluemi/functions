#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <vector>
#include "MenuItem.hpp"

class Menu
{
	public:
		Menu();
		void addItem(MenuItem*);
		void draw();
		void moveCursor(int);
		void action();
	private:
		std::vector<MenuItem*> items;
		int selectedItem;
};

#endif
