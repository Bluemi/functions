#ifndef __ADDITION_CLASS__
#define __ADDITION_CLASS__

#include <func/ElementalFunction.hpp>

class Addition : public ElementalFunction
{
	public:
		Addition();
		virtual void call(Data& stack, Data* returnValues) const override;
};

#endif
