#include "Main.hpp"

#include <iostream>

#include <func/MutableFunction.hpp>
#include <func/elemental/PrintAddition.hpp>
#include <data/DataPattern.hpp>
#include <data/DataMask.hpp>
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
	paramPattern << INT << INT << INT;

	MutableFunction* mainFunction = new MutableFunction(paramPattern); // create MutableFunction that takes 3 ints as parameters

	DataMask mask;
	mask << 8 << 4;

	PrintAddition* p = new PrintAddition();
	if (ErrorCode code = mainFunction->addFunction(p, mask))
	{
		Debug::warn("Main::run(): mainFunction.addFunction() returns errorCode " + getString(code));
	}

	Starter starter(mainFunction);
	starter << 3 << 2 << 1;

	starter.start();
	delete mainFunction;
	delete p;
}
