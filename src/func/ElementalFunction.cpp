#include "ElementalFunction.hpp"

ElementalFunction::ElementalFunction(const DataPattern& paramPattern)
	: parameterPattern_(paramPattern)
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
