#include "Main.hpp"

#include <iostream>

#include <func/MutableFunction.hpp>
#include <func/elemental/PrintNum.hpp>
#include <data/DataPattern.hpp>
#include <data/DataMask.hpp>
// Debug
#include <misc/Debug.hpp>
#include <misc/Converter.hpp>
#include <test/Test.hpp>

#define TEST false

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
	DataPattern pattern;
	pattern.addType(DataType::INT);
	pattern.addType(DataType::INT);
	pattern.addType(DataType::INT);

	MutableFunction mainFunction(pattern);

	DataMask mask;
	mask.addOffset(8);

	PrintNum* p = new PrintNum();
	if (ErrorCode code = mainFunction.addFunction(p, mask))
	{
		Debug::warn("Main::run(): mainFunction.addFunction() returns errorCode " + getString(code));
	}

	Data data;
	data << 1 << 2 << 3;
	data.printString();

	mainFunction.call(data);
	delete p;
}
