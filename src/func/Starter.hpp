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

		const Data& getReturnValues() const;
	private:
		Data data_;
		DataPattern dataPattern_;
		Function* function_;
		Data returnValues_;
};

template <typename T>
Starter& Starter::operator<<(T t)
{
	data_ << t;
	dataPattern_ << Typer<T>::toDataType();
	return *this;
}

#endif
