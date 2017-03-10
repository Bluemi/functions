#include "DataType.hpp"

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

unsigned int getTypeSize(const DataType& t)
{
	switch (t)
	{
		#define T(data_type,c_type) case DataType::data_type: { return sizeof(c_type); }
		#define U(data_type,c_type) case DataType::UNDEFINED: { Debug::error("DataType::getTypeSize(): type=UNDEFINED"); return 0; }
		#include <data/types/types.list>
		#undef T
		#undef U
	}
	Debug::error("DataType::getTypeSize(): invalid type = " + Converter::intToString(t));
	return 0;
}

std::string getTypeName(const DataType t)
{
	switch (t)
	{
		#define T(data_type,c_type) case DataType::data_type: { return #data_type; }
		#define U(data_type,c_type) case DataType::data_type: { return #data_type; }
		#include <data/types/types.list>
		#undef T
		#undef U
	}
	Debug::warn("Unknown DataType: " + Converter::intToString(t));
	return "";
}

bool matches(const DataType& a, const DataType& b)
{
	if (a == DataType::UNDEFINED)
	{
		return false;
	}
	return (a == b);
}
