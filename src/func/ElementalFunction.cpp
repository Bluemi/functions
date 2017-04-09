#include "ElementalFunction.hpp"

ElementalFunction::ElementalFunction(const DataPattern& paramPattern, const DataPattern& returnDataPattern)
	: parameterPattern_(paramPattern), returnDataPattern_(returnDataPattern)
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

DataPattern ElementalFunction::getReturnDataPattern() const
{
	return returnDataPattern_;
}
