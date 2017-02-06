#include "Main.hpp"

#include <iostream>

#include <func/MutableFunction.hpp>
#include <func/elemental/Print.hpp>
#include <data/DataPattern.hpp>
#include <data/DataMask.hpp>

int main()
{
	Main m;
	m.run();
	return 0;
}

void Main::run()
{
	DataPattern pattern;
	MutableFunction mainFunction(pattern);
	Data data;
	DataMask mask;
	Print* p = new Print();
	mainFunction.addFunction(p, mask);
	mainFunction.call(data);
	delete p;
}
