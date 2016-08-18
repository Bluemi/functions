#include "MenuItem.hpp"

MenuItem::MenuItem(const std::string& n, void (*f)())
	: name(n), func(f)
{}

const std::string& MenuItem::getName() { return name; }

void MenuItem::onAction()
{
	func();
}
