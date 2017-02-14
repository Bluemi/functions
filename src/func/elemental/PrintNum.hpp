#ifndef __PRINTNUM_CLASS__
#define __PRINTNUM_CLASS__

#include <func/ElementalFunction.hpp>

class PrintNum : public ElementalFunction
{
	public:
		PrintNum();
		virtual void call(const Data&) override;

		virtual DataPattern getParameterPattern() const override;
		virtual DataPattern getStackPattern() const override;
};

#endif
