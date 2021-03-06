#ifndef __FUNCTION_CLASS__
#define __FUNCTION_CLASS__

#include <vector>

#include <data/Data.hpp>
#include <data/DataPattern.hpp>

class Function
{
	public:
		Function();
		virtual ~Function();

		unsigned int getStackSize() const;

		virtual DataPattern getParameterPattern() const = 0;
		virtual DataPattern getStackPattern() const = 0;
		virtual DataPattern getReturnPattern() const = 0;
	protected:
		virtual void call(Data& stack, Data* returnValues) const = 0;
	friend class Starter;
	friend class FunctionCaller;
};

#endif
