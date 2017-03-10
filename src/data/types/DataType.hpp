#ifndef __DATATYPE_CLASS__
#define __DATATYPE_CLASS__

#include <string>

enum DataType : char {
	#define T(data_type,c_type) data_type,
	#define U(data_type,c_type) data_type
	#include "types.list"
	#undef T
	#undef U
};

unsigned int getTypeSize(const DataType& t);
std::string getTypeName(DataType);

// UNDEFINED does not match UNDEFINED
bool matches(const DataType&, const DataType&);

#endif
