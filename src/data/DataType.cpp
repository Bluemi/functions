#include "DataType.hpp"

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

unsigned int getTypeSize(const DataType& t)
{
	switch (t)
	{
		case DataType::INT:
			return sizeof(int);
		case DataType::FLOAT:
			return sizeof(float);
		case DataType::BOOL:
			return sizeof(bool);
		case DataType::UNDEFINED:
			Debug::warn("DataPattern::getTypeSize(): type=UNDEFINED");
			return 0;
	}
	Debug::error("DataPattern::getTypeSize(): invalid type = " + Converter::intToString(t));
	return 0;
}
