#include "Test.hpp"

#include <misc/Debug.hpp>
#include <data/DataPattern.hpp>
#include <data/DataType.hpp>

void testDataPattern()
{
	DataPattern pattern;
	pattern.addType(DataType::INT);
	pattern.addType(DataType::BOOL);
	pattern.addType(DataType::FLOAT);
	std::cout << pattern.toString() << std::endl;
	for (unsigned int at = 0; at < 10; at++)
	{
		std::cout << "pattern.getTypeAt(" << at << "): " << getTypeName(pattern.getTypeAt(at)) << std::endl;
	}
}

void Test::test()
{
	testDataPattern();
}