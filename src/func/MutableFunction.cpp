#include "MutableFunction.hpp"

MutableFunction::MutableFunction()
{}

MutableFunction::~MutableFunction()
{
	for (Function* f : functions)
	{
		delete f;
	}
	functions.clear();
}

void MutableFunction::addFunction(Function* func)
{
	functions.push_back(func);
}

bool MutableFunction::validIndex(unsigned int index)
{
	return (index >= 0) && (index < functions.size());
}

bool MutableFunction::deleteFunction(unsigned int index)
{
	if (!validIndex(index))
	{
		return false;
	}

	Function* f = functions[index];
	functions.erase(functions.begin()+index);
	delete f;
	return true;
}

void MutableFunction::call(const Date& d)
{
	for (Function* f : functions)
	{
		f->call(d);
	}
}
