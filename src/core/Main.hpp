#ifndef __MAIN_CLASS__
#define __MAIN_CLASS__

#include "../menu/Menu.hpp"

class Main
{
	public:
		Main();
	private:
		Menu mainMenu;
		void initiateCurses();
		void initiateMainMenu();
		void run();
		void quit();

		bool running;
};

#endif
