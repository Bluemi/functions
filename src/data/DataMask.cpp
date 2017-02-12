#include "DataMask.hpp"

DataMask::DataMask()
{}

DataMask& DataMask::operator<< (const unsigned int value)
{
	offsets_.push_back(value);
	return *this;
}

void DataMask::addOffset(const unsigned int index, const unsigned int value)
{
	offsets_.insert(offsets_.begin()+index, value);
}

unsigned int DataMask::getOffset(const unsigned int index) const
{
	return offsets_[index];
}

bool DataMask::validIndex(const unsigned int index) const
{
	return (index >= 0) && (index < offsets_.size());
}

unsigned int DataMask::getSize() const
{
	return offsets_.size();
}
