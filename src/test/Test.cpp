#include "Test.hpp"

#include <misc/Debug.hpp>
#include <data/DataPattern.hpp>
#include <data/types/DataType.hpp>
#include <func/MutableFunction.hpp>
#include <func/Starter.hpp>
#include <data/types/Typer.hpp>

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
void testTyper()
{
	std::cout << "Typer<int>::toDataType()=" << getTypeName(Typer<int>::toDataType()) << std::endl;
	std::cout << "Typer<float>::toDataType()=" << getTypeName(Typer<float>::toDataType()) << std::endl;
	std::cout << "Typer<bool>::toDataType()=" << getTypeName(Typer<bool>::toDataType()) << std::endl;
	std::cout << "Typer<const int>::toDataType()=" << getTypeName(Typer<const int>::toDataType()) << std::endl;
}

void Test::test()
{
	//testDataPattern();
	testStarter();
	//testTyper();
}
