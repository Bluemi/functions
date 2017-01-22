#include "Main.hpp"

#include <iostream>

#include <func/MutableFunction.hpp>
#include <func/elemental/Print.hpp>
#include <data/Date.hpp>

int main()
{
	Main m;
	m.run();
	return 0;
}

void Main::run()
{
	MutableFunction mainFunction;
	Date d(10);
	mainFunction.addFunction(new Print());
	mainFunction.call(d);
}
