#include "DataPattern.hpp"

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

DataPattern::DataPattern()
{}

void DataPattern::addType(const DataType& t)
{
	pattern.push_back(t);
}

size_t DataPattern::getSize() const
{
	return pattern.size();
}

size_t DataPattern::getBytesSize() const
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
		return ERROR;
	}
	return pattern[index];
}

size_t DataPattern::getTypeSize(const DataType& t)
{
	switch (t)
	{
		case INT:
			return sizeof(int);
		case FLOAT:
			return sizeof(float);
		case BOOL:
			return sizeof(bool);
		case ERROR:
			Debug::warn("DataPattern::getTypeSize(): type=ERROR");
			return 0;
	}
	Debug::error("DataPattern::getTypeSize(): invalid type = " + Converter::intToString(t));
	return 0;
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
