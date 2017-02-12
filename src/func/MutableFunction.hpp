#ifndef __MUTABLEFUNCTION_CLASS__
#define __MUTABLEFUNCTION_CLASS__

#include "Function.hpp"
#include "Caller.hpp"

#include <misc/ErrorCode.hpp>

class MutableFunction : public Function
{
	public:
		MutableFunction(const DataPattern&);
		~MutableFunction();
		virtual void call(const Data& data) override; // führt die Function aus
		ErrorCode addFunction(Function* func, const DataMask& mask);
		bool validIndex(unsigned int index); // prüft, ob der übergebene index auf eine gültige Function zeigt
		bool removeFunction(unsigned int index); // entfernt die Function an der Stelle <index> aus den Functions

		virtual DataPattern getParamPattern() const override;
		virtual DataPattern getStackPattern() const override;
	private:
		ErrorCode checkAddFunction(Function* func, const DataMask& funcMask) const;
		DataPattern pattern_;
		int stackSize_;
		std::vector<Caller> caller_;
};

#endif
