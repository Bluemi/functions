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
	#define U(data_type,c_type) {}
	#define T(data_type,c_type) if (Typer<T>::matches(DataType::data_type)) { return DataType::data_type; }
	#include <data/types/types.list>
	#undef U
	#undef T
	return DataType::UNDEFINED;
}

template <typename T>
bool Typer<T>::matches(const DataType& t)
{
	switch (t)
	{
		#define U(data_type,c_type) case UNDEFINED: { return false; }
		#define T(data_type,c_type) case data_type: { return TypeMatcher<T,c_type>::equals; }
		#include <data/types/types.list>
		#undef U
		#undef T
	}
	return false;
}

#endif
