#include "DataPattern.hpp"

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

DataPattern::DataPattern()
{}

DataPattern& DataPattern::operator<< (const DataType& t)
{
	pattern_.push_back(t);
	return *this;
}

unsigned int DataPattern::getSize() const
{
	return pattern_.size();
}

unsigned int DataPattern::getBytesSize() const
{
	size_t s = 0;
	for (auto iter = pattern_.begin(); iter != pattern_.end(); ++iter)
	{
		s += getTypeSize(*iter);
	}
	return s;
}

bool DataPattern::validIndex(unsigned int index) const
{
	return (index >= 0) && (index < pattern_.size());
}

DataType DataPattern::operator[](unsigned int index) const
{
	if (!validIndex(index))
	{
		Debug::warn("DataPattern::operator[](): invalid index; index=" + Converter::intToString(index) + " size=" + Converter::intToString(pattern_.size()));
		return DataType::UNDEFINED;
	}
	return pattern_[index];
}

DataType DataPattern::getTypeAt(unsigned int offset) const
{
	if (getSize() == 0)
	{
		return DataType::UNDEFINED;
	}
	unsigned int countOffset = 0;
	unsigned int i = 0;
	while (true)
	{
		if (i >= getSize())
		{
			// offsetOutOfRange
			return DataType::UNDEFINED;
		}
		if (countOffset == offset)
		{
			return pattern_[i];
		}
		else if (countOffset > offset)
		{
			return DataType::UNDEFINED;
		}
		countOffset += getTypeSize(pattern_[i]);
		i++;
	}
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

std::string DataPattern::toString() const
{
	std::string s = "";
	for (unsigned int i = 0; i < pattern_.size(); i++)
	{
		s += " " + getTypeName(pattern_[i]);
	}
	return s;
}
