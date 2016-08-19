#ifndef __MENUITEM_CLASS__
#define __MENUITEM_CLASS__

#include <string>

class MenuItem
{
	public:
		struct Functor
		{
			public:
				virtual void onAction()=0;
		};
		MenuItem(const std::string&, Functor*);
		virtual void onAction();
		const std::string& getName();
	private:
		std::string name;
		Functor* func;
};

#endif
