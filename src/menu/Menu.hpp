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
	private:
		std::vector<MenuItem*> items;
		int selectedItem;
};

#endif
