#include "DataMapping.hpp"

DataMapping::DataMapping()
{}

DataMapping& DataMapping::operator<< (const unsigned int value)
{
	offsets_.push_back(value);
	return *this;
}

void DataMapping::addOffset(const unsigned int index, const unsigned int value)
{
	offsets_.insert(offsets_.begin()+index, value);
}

unsigned int DataMapping::operator[](const unsigned int index) const
{
	return offsets_[index];
}

bool DataMapping::validIndex(const unsigned int index) const
{
	return (index >= 0) && (index < offsets_.size());
}

unsigned int DataMapping::getSize() const
{
	return offsets_.size();
}
