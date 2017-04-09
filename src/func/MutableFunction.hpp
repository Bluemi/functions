#ifndef __MUTABLEFUNCTION_CLASS__
#define __MUTABLEFUNCTION_CLASS__

#include "Function.hpp"

#include <misc/codes/AddErrorCode.hpp>
#include <data/DataMask.hpp>
#include <func/caller/Caller.hpp>

class MutableFunction : public Function
{
	public:
		MutableFunction(const DataPattern& parameterPattern);
		~MutableFunction();

		// Function handling
		AddErrorCode addFunction(Function* func, const DataMask& mask);
		AddErrorCode addFunction(Function* func, const DataMask& mask, const DataMask& rMask);
		bool validFunctionIndex(unsigned int index); // prüft, ob der übergebene index auf eine gültige Function zeigt
		bool removeFunction(unsigned int index); // entfernt die Function an der Stelle <index> aus den Functions

		bool isRunning() const;

		// LocalVars handling
		void addLocal(const DataType& type);

		// get{Stack,Parameter}Pattern
		virtual DataPattern getParameterPattern() const override;
		virtual DataPattern getStackPattern() const override;
		virtual DataPattern getReturnDataPattern() const override;
	protected:
		virtual void call(Data& stack, Data* returnValues) const override; // führt die Function aus
	private:
		AddErrorCode checkAddFunction(Function* func, const DataMask& pMask) const;
		AddErrorCode checkAddFunction(Function* func, const DataMask& pMask, const DataMask& rMask) const;
		DataPattern parameterPattern_;
		DataPattern localsPattern_;
		DataPattern returnDataPattern_;
		int stackSize_;
		std::vector<Caller*> caller_;
};

#endif
