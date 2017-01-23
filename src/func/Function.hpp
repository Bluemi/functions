#ifndef __FUNCTION_CLASS__
#define __FUNCTION_CLASS__

#include <vector>

#include <data/Data.hpp>

class Function
{
	public:
		Function();
		virtual ~Function();
		virtual void call(const Data&) = 0;
};

#endif
