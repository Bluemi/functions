#ifndef __CALLER_CLASS__
#define __CALLER_CLASS__

/*
	FunctionCaller werden in Mutable Functions verwendet (MutableFunction.caller).
	Sie sind dafür da, die in diesen FunctionCallern befindliche Function mit den richtigen Parametern zu callen
*/

#include "Function.hpp"
#include <data/DataMask.hpp>

class FunctionCaller
{
	public:
		FunctionCaller(Function* f, const DataMask& m);
		~FunctionCaller();
		void call(const Data& data);
	private:
		Function* func_;
		DataMask mask_;
};

#endif
