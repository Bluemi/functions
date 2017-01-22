#ifndef __MUTABLEFUNCTION_CLASS__
#define __MUTABLEFUNCTION_CLASS__

#include <vector>

#include "Function.hpp"

class MutableFunction : public Function
{
	public:
		MutableFunction();
		~MutableFunction();
		virtual void call(const Date&) override; // führt die Function aus
		void addFunction(Function* func);
		bool validIndex(unsigned int index); // prüft, ob der übergebene index auf eine gültige Function zeigt
		bool deleteFunction(unsigned int index); // entfernt die Function an der Stelle <index> aus den Functions und führt delete auf die entfernte Function aus
	private:
		std::vector<Function*> functions;
};

#endif
