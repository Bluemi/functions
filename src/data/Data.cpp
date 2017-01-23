#include "Data.hpp"

Data::Data()
{}

void Data::addDate(Date d)
{
	data.push_back(d);
}

Date Data::getDate(unsigned int index) const
{
	if (!validIndex(index))
	{
		return Date(); // ERROR Date
	}
	return data[index];
}

bool Data::validIndex(unsigned int index) const
{
	return (index >= 0) && (index < data.size());
}

unsigned int Data::size()
{
	return data.size();
}
