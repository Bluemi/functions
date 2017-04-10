#ifndef __MUTABLEFUNCTION_CLASS__
#define __MUTABLEFUNCTION_CLASS__

#include "Function.hpp"

#include <misc/codes/AddErrorCode.hpp>
#include <data/DataMapping.hpp>
#include <func/caller/Caller.hpp>

class MutableFunction : public Function
{
	public:
		MutableFunction(const DataPattern& parameterPattern);
		~MutableFunction();

		// Function handling
		AddErrorCode addFunction(Function* func, const DataMapping& mapping);
		AddErrorCode addFunction(Function* func, const DataMapping& mapping, const DataMapping& rMapping);
		bool validFunctionIndex(unsigned int index); // prüft, ob der übergebene index auf eine gültige Function zeigt
		bool removeFunction(unsigned int index); // entfernt die Function an der Stelle <index> aus den Functions

		bool isRunning() const;

		// LocalVars handling
		void addLocal(const DataType& type);

		// get{Stack,Parameter,Return}Pattern
		virtual DataPattern getParameterPattern() const override;
		virtual DataPattern getStackPattern() const override;
		virtual DataPattern getReturnDataPattern() const override;
	protected:
		virtual void call(Data& stack, Data* returnValues) const override; // führt die Function aus
	private:
		AddErrorCode checkAddFunction(Function* func, const DataMapping& pMapping) const;
		AddErrorCode checkAddFunction(Function* func, const DataMapping& pMapping, const DataMapping& rMapping) const;
		DataPattern parameterPattern_;
		DataPattern localsPattern_;
		DataPattern returnDataPattern_;
		int stackSize_;
		std::vector<Caller*> caller_;
};

#endif
