#ifndef __STARTER_CLASS__
#define __STARTER_CLASS__

#include "Function.hpp"

class Starter
{
	public:
		Starter(Function* f);
		void start();

		template <typename T>
		Starter& operator<<(T t);
	private:
		Data data;
		Function* function;
};

template <typename T>
Starter& Starter::operator<<(T t)
{
	data << t;
	return *this;
}

#endif
