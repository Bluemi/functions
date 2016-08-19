#include <iostream>
#include <curses.h>

#include <vector>

#include "../menu/Menu.hpp"
#include "../menu/MenuItem.hpp"

void initiateCurses()
{
	initscr();
	keypad(stdscr, true);
	noecho();
	raw();
}

void sayHelloWorld()
{
	int row, col;
	getmaxyx(stdscr,row,col);
	move(row-1, 0);
	addstr("hello World             ");
}

void saySomething()
{
	int row, col;
	getmaxyx(stdscr,row,col);
	move(row-1, 0);
	addstr("something               ");
}

void saySomethingDifferent()
{
	int row, col;
	getmaxyx(stdscr,row,col);
	move(row-1, 0);
	addstr("something different     ");
}

bool running = true;

void quit()
{
	running = false;
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
	MenuItem* item4 = new MenuItem("Quit", quit);
	menu.addItem(item4);

	do
	{
		//clear();
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
			case 10:
			{
				menu.action();
				break;
			}
		}
	} while (running);

	endwin();

	return 0;
}
