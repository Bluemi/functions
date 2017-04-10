#include "Main.hpp"

#include <iostream>

#include <func/MutableFunction.hpp>
#include <func/elemental/Addition.hpp>
#include <data/DataPattern.hpp>
#include <data/DataMapping.hpp>
#include <func/Starter.hpp>
// Debug
#include <misc/Debug.hpp>
#include <misc/Converter.hpp>
#include <test/Test.hpp>

int main()
{
	if (TEST)
	{
		Test t;
		t.test();
	}
	else
	{
		Main m;
		m.run();
	}
	return 0;
}

void Main::run()
{
	DataPattern paramPattern;
	paramPattern << INT << INT;

	MutableFunction* mainFunction = new MutableFunction(paramPattern); // create MutableFunction that takes 3 ints as parameters

	mainFunction->addLocal(INT);

	DataMapping pMapping;
	pMapping << 0 << 4;

	DataMapping rMapping;
	rMapping << 8;

	Addition* p = new Addition();
	if (AddErrorCode code = mainFunction->addFunction(p, pMapping, rMapping))
	{
		Debug::warn("Main::run(): mainFunction.addFunction() returns errorCode " + getString(code));
	}

	Starter starter(mainFunction);
	starter << 1 << 2;

	starter.start();
	delete mainFunction;
	delete p;
}
