#ifndef __ELEMENTALFUNCTION_CLASS__
#define __ELEMENTALFUNCTION_CLASS__

#include "Function.hpp"

class ElementalFunction : public Function
{
	public:
		ElementalFunction(const DataPattern& paramPattern, const DataPattern& returnValuesDataPattern);
		virtual ~ElementalFunction();

		virtual DataPattern getParameterPattern() const final override;
		virtual DataPattern getStackPattern() const final override;
		virtual DataPattern getReturnDataPattern() const final override;
	private:
		DataPattern parameterPattern_;
		DataPattern returnDataPattern_;
};

#endif
