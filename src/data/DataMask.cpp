#include "DataMask.hpp"

DataMask::DataMask()
{}

void DataMask::addOffset(const unsigned int value)
{
	offsets.push_back(value);
}

void DataMask::addOffset(const unsigned int index, const unsigned int value)
{
	offsets.insert(offsets.begin()+index, value);
}

unsigned int DataMask::getOffset(const unsigned int index) const
{
	return offsets[index];
}

bool DataMask::validIndex(const unsigned int index) const
{
	return (index >= 0) && (index < offsets.size());
}

unsigned int DataMask::getSize() const
{
	return offsets.size();
}
