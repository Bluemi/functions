#include "Caller.hpp"

Caller::Caller(Function* f, const DataMask& m)
	: func(f), mask(m)
{}

Caller::~Caller()
{}

void Caller::call(const Data& data)
{
	func->call(data);
}
