#include "Main.hpp"

#include <iostream>

#include <func/MutableFunction.hpp>
#include <func/elemental/PrintNum.hpp>
#include <data/DataPattern.hpp>
#include <data/DataMask.hpp>
#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

int main()
{
	Main m;
	m.run();
	return 0;
}

void Main::run()
{
	DataPattern pattern;
	pattern.addType(DataType::INT);
	MutableFunction mainFunction(pattern);
	Data data;
	data << 1 << 2;
	DataMask mask;
	mask.addOffset(0);
	PrintNum* p = new PrintNum();
	if (ErrorCode code = mainFunction.addFunction(p, mask))
	{
		Debug::warn("Main::run(): mainFunction.addFunction() returns errorCode " + getString(code));
	}
	mainFunction.call(data);
	delete p;
}
