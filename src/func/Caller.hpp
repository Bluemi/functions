#ifndef __CALLER_CLASS__
#define __CALLER_CLASS__

#include "Function.hpp"
#include <data/DataMask.hpp>

class Caller
{
	public:
		Caller(Function* f, const DataMask& m);
		~Caller();
		void call(const Data& data);
	private:
		Function* func;
		DataMask mask;
};

#endif
