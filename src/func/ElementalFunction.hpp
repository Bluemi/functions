#ifndef __ELEMENTALFUNCTION_CLASS__
#define __ELEMENTALFUNCTION_CLASS__

#include "Function.hpp"

class ElementalFunction : public Function
{
	public:
		ElementalFunction(const DataPattern& paramPattern);
		virtual ~ElementalFunction();

		virtual DataPattern getParameterPattern() const final;
		virtual DataPattern getStackPattern() const final;
	private:
		DataPattern parameterPattern_;
};

#endif
