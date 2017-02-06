#ifndef __MUTABLEFUNCTION_CLASS__
#define __MUTABLEFUNCTION_CLASS__

#include "Function.hpp"
#include "Caller.hpp"

class MutableFunction : public Function
{
	public:
		MutableFunction(const DataPattern&);
		~MutableFunction();
		virtual void call(const Data& data) override; // führt die Function aus
		void addFunction(Function* func, const DataMask& mask);
		bool validIndex(unsigned int index); // prüft, ob der übergebene index auf eine gültige Function zeigt
		bool removeFunction(unsigned int index); // entfernt die Function an der Stelle <index> aus den Functions

		virtual DataPattern getParamPattern() const override;
		virtual DataPattern getStackPattern() const override;
	private:
		std::vector<Caller> caller;
		DataPattern pattern;
};

#endif
