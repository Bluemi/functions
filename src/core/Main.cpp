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

template<typename function>
struct Funcer : public MenuItem::Functor
{
	public:
		Funcer(function p) : func(p) {}
		void onAction() override { func(); }
	private:
		function func;
};

void say(const std::string& msg)
{
	int x, y;
	getmaxyx(stdscr, y, x);
	clear();
	mvprintw(y/2,(x-strlen(msg.c_str()))/2,"%s",msg.c_str());
}

void sayHelloWorld()
{
	say("Hello World");
}

void sayByeWorld()
{
	say("Bye World");
}

void Main::initiateMainMenu()
{
	mainMenu.addItem(new MenuItem("say \"hello world\"", new Funcer<void (*)()>(sayHelloWorld)));
	mainMenu.addItem(new MenuItem("say \"bye world\"", new Funcer<void (*)()>(sayByeWorld)));
	mainMenu.addItem(new MenuItem("clear", new Funcer<int (*)()>(clear)));
	mainMenu.addItem(new MenuItem("quit", new Quitter(&running)));
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
