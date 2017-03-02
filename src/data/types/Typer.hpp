#ifndef __TYPER_CLASS__
#define __TYPER_CLASS__

#include "DataType.hpp"
#include "TypeMatcher.hpp"

template<typename T>
class Typer
{
	public:
		static DataType toDataType();
		static bool matches(const DataType& t);
};

template<typename T>
DataType Typer<T>::toDataType()
{
	if (Typer<T>::matches(DataType::INT)) {
		return DataType::INT;
	} else if (Typer<T>::matches(DataType::FLOAT)) {
		return DataType::FLOAT;
	} else if (Typer<T>::matches(DataType::BOOL)) {
		return DataType::BOOL;
	}
	return DataType::UNDEFINED;
}

template <typename T>
bool Typer<T>::matches(const DataType& t)
{
	switch (t)
	{
		case INT:
		{
			return TypeMatcher<T,int>::equals;
		}
		case FLOAT:
		{
			return TypeMatcher<T,float>::equals;
		}
		case BOOL:
		{
			return TypeMatcher<T,bool>::equals;
		}
		case UNDEFINED:
		{
			return false;
		}
	}
	return false;
}

#endif
