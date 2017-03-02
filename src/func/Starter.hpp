#ifndef __STARTER_CLASS__
#define __STARTER_CLASS__

#include "Function.hpp"
#include <misc/codes/StartErrorCode.hpp>
#include <data/types/Typer.hpp>

class Starter
{
	public:
		Starter(Function* f);
		StartErrorCode start();

		template <typename T>
		Starter& operator<<(T t);
	private:
		Data data;
		DataPattern dataPattern;
		Function* function;
};

template <typename T>
Starter& Starter::operator<<(T t)
{
	data << t;
	dataPattern << Typer<T>::toDataType();
	return *this;
}

#endif
