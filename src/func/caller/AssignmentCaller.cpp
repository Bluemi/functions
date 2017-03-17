#include "AssignmentCaller.hpp"

AssignmentCaller::AssignmentCaller(const DataMask& targetValues, const DataPattern& targetPattern)
	: targetValues_(targetValues), targetPattern_(targetPattern)
{}

AssignmentCaller::~AssignmentCaller() {}

void AssignmentCaller::call(Data& data)
{
	for (unsigned int i = 0; i < targetValues_.getSize(); i++)
	{
		data.setAt(2, targetValues_[i]);
	}
}
