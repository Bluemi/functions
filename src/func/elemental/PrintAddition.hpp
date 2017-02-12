#ifndef __PRINTADDITION_CLASS__
#define __PRINTADDITION_CLASS__

#include <func/ElementalFunction.hpp>

class PrintAddition : public ElementalFunction
{
	public:
		PrintAddition();
		virtual void call(const Data&) override;

		virtual DataPattern getParamPattern() const override;
		virtual DataPattern getStackPattern() const override;
};

#endif
