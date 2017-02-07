#ifndef __MUTABLEFUNCTION_CLASS__
#define __MUTABLEFUNCTION_CLASS__

#include "Function.hpp"
#include "Caller.hpp"

enum AddError { NONE, WRONG_PARAMETER_SIZE, TYPE_MISMATCH, UNDEFINED_DATA_TYPE };

class MutableFunction : public Function
{
	public:
		MutableFunction(const DataPattern&);
		~MutableFunction();
		virtual void call(const Data& data) override; // führt die Function aus
		AddError addFunction(Function* func, const DataMask& mask);
		bool validIndex(unsigned int index); // prüft, ob der übergebene index auf eine gültige Function zeigt
		bool removeFunction(unsigned int index); // entfernt die Function an der Stelle <index> aus den Functions

		virtual DataPattern getParamPattern() const override;
		virtual DataPattern getStackPattern() const override;
	private:
		AddError checkAddFunction(Function* func, const DataMask& funcMask) const;
		std::vector<Caller> caller;
		DataPattern pattern;
};

#endif
