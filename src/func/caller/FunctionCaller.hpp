#ifndef __FUNCTIONCALLER_CLASS__
#define __FUNCTIONCALLER_CLASS__

/*
	FunctionCaller werden in Mutable Functions verwendet (MutableFunction.caller).
	Sie sind dafür da, die in diesen FunctionCallern befindliche Function mit den richtigen Parametern zu callen
*/

#include <func/caller/Caller.hpp>

#include <func/Function.hpp>
#include <data/DataMapping.hpp>


class FunctionCaller : public Caller
{
	public:
		FunctionCaller(Function* f, const DataMapping& pMapping, const DataMapping& rMapping);
		virtual ~FunctionCaller();
		virtual void call(Data& data) override;
	private:
		Function* func_;
		DataMapping parameterMapping_;
		DataMapping returnMapping_;
};

#endif
