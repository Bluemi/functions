#ifndef __MUTABLEFUNCTION_CLASS__
#define __MUTABLEFUNCTION_CLASS__

#include "Function.hpp"
#include <func/caller/FunctionCaller.hpp>

#include <misc/codes/AddErrorCode.hpp>

class MutableFunction : public Function
{
	public:
		MutableFunction(const DataPattern& parameterPattern);
		~MutableFunction();

		// Function handling
		AddErrorCode addFunction(Function* func, const DataMask& mask);
		bool validFunctionIndex(unsigned int index); // prüft, ob der übergebene index auf eine gültige Function zeigt
		bool removeFunction(unsigned int index); // entfernt die Function an der Stelle <index> aus den Functions

		// LocalVars handling
		void addLocal(const DataType& type);

		// get{Stack,Parameter}Pattern
		virtual DataPattern getParameterPattern() const override;
		virtual DataPattern getStackPattern() const override;
	protected:
		virtual void call(const Data& data) const override; // führt die Function aus
	private:
		AddErrorCode checkAddFunction(Function* func, const DataMask& funcMask) const;
		DataPattern parameterPattern_;
		DataPattern localsPattern_;
		int stackSize_;
		std::vector<Caller*> caller_;
};

#endif
