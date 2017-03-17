#ifndef __PRINTNUM_CLASS__
#define __PRINTNUM_CLASS__

#include <func/ElementalFunction.hpp>

class PrintNum : public ElementalFunction
{
	public:
		PrintNum();
		virtual void call(Data&) const override;
};

#endif
