#include "ElementalFunction.hpp"

ElementalFunction::ElementalFunction(const DataPattern& paramPattern, const DataPattern& returnPattern)
	: parameterPattern_(paramPattern), returnPattern_(returnPattern)
{}

ElementalFunction::~ElementalFunction()
{}

DataPattern ElementalFunction::getParameterPattern() const
{
	return parameterPattern_;
}

DataPattern ElementalFunction::getStackPattern() const
{
	return DataPattern();
}

DataPattern ElementalFunction::getReturnPattern() const
{
	return returnPattern_;
}
