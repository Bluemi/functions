#ifndef __MENUITEM_CLASS__
#define __MENUITEM_CLASS__

#include <string>

class MenuItem
{
	public:
		MenuItem(const std::string&, void (*f)());
		virtual void onAction();
		const std::string& getName();
	private:
		std::string name;
		void (*func)();
};

#endif
