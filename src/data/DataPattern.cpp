#include "DataPattern.hpp"

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

DataPattern::DataPattern()
{}

void DataPattern::addType(const DataType& t)
{
	pattern.push_back(t);
}

unsigned int DataPattern::getSize() const
{
	return pattern.size();
}

unsigned int DataPattern::getBytesSize() const
{
	size_t s = 0;
	for (auto iter = pattern.begin(); iter != pattern.end(); ++iter)
	{
		s += getTypeSize(*iter);
	}
	return s;
}

bool DataPattern::validIndex(unsigned int index) const
{
	return (index >= 0) && (index < pattern.size());
}

DataType DataPattern::operator[](unsigned int index) const
{
	if (!validIndex(index))
	{
		Debug::warn("DataPattern::operator[](): invalid index; index=" + Converter::intToString(index) + " size=" + Converter::intToString(pattern.size()));
		return DataType::UNDEFINED;
	}
	return pattern[index];
}

DataType DataPattern::getTypeAt(unsigned int offset) const
{
	if (getSize() == 0)
	{
		Debug::warn("DataPattern::getTypeAt(): no Types in here: return DataType::UNDEFINED");
		return DataType::UNDEFINED;
	}
	unsigned int n = 0;
	unsigned int i = 0;
	while (n < offset)
	{
		n += getTypeSize(pattern[i]);
		i++;
	}
	return pattern[i];
}

bool DataPattern::matches(const DataPattern& p1, const DataPattern& p2)
{
	if (p1.getSize() != p2.getSize())
	{
		return false;
	}
	for (unsigned int i = 0; i < p1.getSize(); i++)
	{
		if (p1[i] != p2[i])
		{
			return false;
		}
	}
	return true;
}
