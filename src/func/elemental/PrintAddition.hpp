#ifndef __PRINTADDITION_CLASS__
#define __PRINTADDITION_CLASS__

#include <func/ElementalFunction.hpp>

class PrintAddition : public ElementalFunction
{
	public:
		PrintAddition();
		virtual void call(const Data&) const override;
};

#endif
