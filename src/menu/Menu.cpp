#include "Menu.hpp"

#include <curses.h>
#include <iostream>

Menu::Menu()
	: selectedItem(0)
{}

void Menu::addItem(MenuItem* item)
{
	items.push_back(item);
}

void Menu::draw()
{
	int counter = 0;
	std::string text;
	for (MenuItem* item : items)
	{
		if (counter == selectedItem)
		{
			text = "> " + item->getName();
		}
		else
		{
			text = "  " + item->getName();
		}
		mvprintw(counter, 0, text.c_str());
		counter++;
	}
	refresh();
}

void Menu::moveCursor(int value)
{
	selectedItem += value;
	if (selectedItem < 0)
	{
		selectedItem = 0;
	}
	else if (selectedItem >= (int)items.size())
	{
		selectedItem = items.size()-1;
	}
}
