#ifndef __CALLER_CLASS__
#define __CALLER_CLASS__

/*
	Caller werden in Mutable Functions verwendet (MutableFunction.caller).
	Sie sind dafür da, die in diesen Callern befindliche Function mit den richtigen Parametern zu callen
*/

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
