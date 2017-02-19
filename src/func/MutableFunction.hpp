#ifndef __MUTABLEFUNCTION_CLASS__
#define __MUTABLEFUNCTION_CLASS__

#include "Function.hpp"
#include "Caller.hpp"

#include <misc/ErrorCode.hpp>

class MutableFunction : public Function
{
	public:
		MutableFunction(const DataPattern& parameterPattern);
		~MutableFunction();
		ErrorCode addFunction(Function* func, const DataMask& mask);
		bool validIndex(unsigned int index); // prüft, ob der übergebene index auf eine gültige Function zeigt
		bool removeFunction(unsigned int index); // entfernt die Function an der Stelle <index> aus den Functions

		virtual DataPattern getParameterPattern() const override;
		virtual DataPattern getStackPattern() const override;
	protected:
		virtual void call(const Data& data) override; // führt die Function aus
	private:
		ErrorCode checkAddFunction(Function* func, const DataMask& funcMask) const;
		DataPattern parameterPattern_;
		int stackSize_;
		std::vector<Caller> caller_;
};

#endif
