#ifndef __ELEMENTALFUNCTION_CLASS__
#define __ELEMENTALFUNCTION_CLASS__

#include "Function.hpp"

class ElementalFunction : public Function
{
	public:
		ElementalFunction(const DataPattern& paramPattern);
		virtual ~ElementalFunction();

		virtual DataPattern getParameterPattern() const;
		virtual DataPattern getStackPattern() const;
	private:
		DataPattern parameterPattern_;
};

#endif
