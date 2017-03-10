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
	StartErrorCode code = starter.start();
	std::cout << getString(code) << std::endl;
	delete mainFunc;
}

void testTyper()
{
	std::cout << "Typer<int>::toDataType()=" << getTypeName(Typer<int>::toDataType()) << std::endl;
	std::cout << "Typer<float>::toDataType()=" << getTypeName(Typer<float>::toDataType()) << std::endl;
	std::cout << "Typer<bool>::toDataType()=" << getTypeName(Typer<bool>::toDataType()) << std::endl;
	std::cout << "Typer<const int>::toDataType()=" << getTypeName(Typer<const int>::toDataType()) << std::endl;
}

void testAddLocal()
{
	DataPattern paramPattern;
	paramPattern << DataType::INT << DataType::FLOAT;
	MutableFunction* func = new MutableFunction(paramPattern);
	func->addLocal(FLOAT);
	std::cout << "func->getStackPattern().getBytesSize()=" << func->getStackPattern().getBytesSize() << std::endl;
	std::cout << "func->getParameterPattern().getBytesSize()=" << func->getParameterPattern().getBytesSize() << std::endl;
	for (unsigned int i = 0; i < 9; i+=4)
		std::cout << "func->getStackPattern().getTypeAt(" << i << ")=" << getTypeName(func->getStackPattern().getTypeAt(i)) << std::endl;
	delete func;
}

void Test::test()
{
	testDataPattern();
	testStarter();
	testTyper();
	testAddLocal();
}
