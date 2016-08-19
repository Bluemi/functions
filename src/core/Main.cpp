#include "Main.hpp"

#include <string.h>
#include <curses.h>

#include "../menu/MenuItem.hpp"

Main::Main()
	: running(true)
{
	run();
}

void Main::initiateCurses()
{
	initscr();
	keypad(stdscr, true);
	noecho();
	raw();
}

struct Quitter : public MenuItem::Functor
{
	public:
		Quitter(bool* _b) : b(_b) {}
		void onAction() override { *b = false; }
	private:
		bool* b;
};

struct Funcer : public MenuItem::Functor
{
	public:
		Funcer(void (*p)()) : func(p) {}
		void onAction() override { func(); }
	private:
		void (*func)();
};

void say(const std::string& msg)
{
	int x, y;
	getmaxyx(stdscr, y, x);
	mvprintw(y/2,(x-strlen(msg.c_str()))/2,"%s",msg.c_str());
}

void sayHelloWorld()
{
	say("Hello World");
}

void Main::initiateMainMenu()
{
	// menu.addItem(new MenuItem("Say Hello World", sayHelloWorld));
	// menu.addItem(new MenuItem("Say something", saySomething));
	// menu.addItem(new MenuItem("Say something different", saySomethingDifferent));
	
	mainMenu.addItem(new MenuItem("say \"hello World\"", new Funcer(sayHelloWorld)));
	mainMenu.addItem(new MenuItem("Quit", new Quitter(&running)));
}

void Main::quit()
{
	running = false;
}

void Main::run()
{
	initiateCurses();
	initiateMainMenu();

	do
	{
		//clear();
		mainMenu.draw();
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
				mainMenu.moveCursor(1);
				break;
			}
			case 'k':
			case KEY_UP:
			{
				mainMenu.moveCursor(-1);
				break;
			}
			case 10:
			{
				mainMenu.action();
				break;
			}
		}
	} while (running);

	endwin();
}
