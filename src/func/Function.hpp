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
		virtual void call(const Data&) = 0;

		virtual DataPattern getParamPattern() const = 0;
		virtual DataPattern getStackPattern() const = 0;
};

#endif
