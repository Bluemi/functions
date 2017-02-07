#ifndef __DATATYPE_CLASS__
#define __DATATYPE_CLASS__

enum DataType : char { UNDEFINED, INT, FLOAT, BOOL };

unsigned int getTypeSize(const DataType& t);

// UNDEFINED does not match UNDEFINED
bool matches(const DataType&, const DataType&);

#endif
