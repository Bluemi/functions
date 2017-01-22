#ifndef __FUNCTION_CLASS__
#define __FUNCTION_CLASS__

#include <data/Date.hpp>

class Function
{
	public:
		Function();
		virtual ~Function();
		virtual void call(const Date&) = 0;
};

#endif
