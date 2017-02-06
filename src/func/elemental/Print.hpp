#ifndef __PRINT_CLASS__
#define __PRINT_CLASS__

#include "../ElementalFunction.hpp"

class Print : public ElementalFunction
{
	public:
		Print();
		virtual void call(const Data&) override;

		virtual DataPattern getParamPattern() const override;
};

#endif
