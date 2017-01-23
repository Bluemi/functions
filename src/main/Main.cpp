#include "Main.hpp"

#include <iostream>

#include <func/MutableFunction.hpp>
#include <func/elemental/PrintAddition.hpp>
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
	Data data;
	data.addDate(Date(100));
	data.addDate(Date(20));
	mainFunction.addFunction(new PrintAddition());
	mainFunction.call(data);
}
