#ifndef __PRINT_CLASS__
#define __PRINT_CLASS__

#include <func/ElementalFunction.hpp>

class Print : public ElementalFunction
{
	public:
		Print();
		virtual void call(Data&) const override;
};

#endif
