#include "Starter.hpp"

#include <misc/Debug.hpp>

Starter::Starter(Function* f)
	: function(f)
{}

void Starter::start()
{
	if (function->getStackSize() != data.getSize())
	{
		Debug::warn("Starter::start(): can't call function, cause data.size(" + Converter::intToString(data.getSize()) + ") and function.stacksize(" + Converter::intToString(function->getStackSize()) + ") differ in length");
		return;
	}
	function->call(data);
}
