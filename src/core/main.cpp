#include <iostream>
#include <curses.h>

#include <vector>

#include "../menu/Menu.hpp"
#include "../menu/MenuItem.hpp"

void sayHelloWorld()
{
	std::cout << "hello World" << std::endl;
}

void saySomething()
{
	std::cout << "something" << std::endl;
}

void saySomethingDifferent()
{
	std::cout << "something different" << std::endl;
}

void initiateCurses()
{
	initscr();
	keypad(stdscr, true);
	raw();
}

int main()
{
	initiateCurses();

	Menu menu;
	MenuItem* item = new MenuItem("Say Hello World", sayHelloWorld);
	menu.addItem(item);
	MenuItem* item2 = new MenuItem("Say something", saySomething);
	menu.addItem(item2);
	MenuItem* item3 = new MenuItem("Say something different", saySomethingDifferent);
	menu.addItem(item3);

	bool running = true;

	do
	{
		clear();
		menu.draw();
		switch (getch())
		{
			case 'q':
			{
				running = false;
				break;
			}
			case 'j':
			case KEY_DOWN:
			{
				menu.moveCursor(1);
				break;
			}
			case 'k':
			case KEY_UP:
			{
				menu.moveCursor(-1);
				break;
			}
		}
	} while (running);

	endwin();

	return 0;
}
