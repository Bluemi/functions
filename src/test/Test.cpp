#include "Test.hpp"

#include <misc/Debug.hpp>
#include <data/DataPattern.hpp>
#include <data/DataType.hpp>
#include <func/MutableFunction.hpp>
#include <func/Starter.hpp>

void testDataPattern()
{
	DataPattern pattern;
	pattern << DataType::INT << DataType::BOOL << DataType::FLOAT;
	std::cout << pattern.toString() << std::endl;
	for (unsigned int at = 0; at < 10; at++)
	{
		std::cout << "pattern.getTypeAt(" << at << "): " << getTypeName(pattern.getTypeAt(at)) << std::endl;
	}
}

void testStarter()
{
	DataPattern pattern;
	pattern << DataType::INT;
	Function* mainFunc = new MutableFunction(pattern);
	Starter starter(mainFunc);
	starter << 3;
	starter.start();
}

void Test::test()
{
	//testDataPattern();
	testStarter();
}
