#ifndef __CALLER_CLASS__
#define __CALLER_CLASS__

#include "data/Data.hpp"

class Caller
{
	public:
		Caller();
		virtual ~Caller();
		virtual void call(const Data&) = 0;
	protected:
};

#endif
