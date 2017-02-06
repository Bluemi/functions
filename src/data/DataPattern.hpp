#ifndef __DATAPATTERN_CLASS__
#define __DATAPATTERN_CLASS__

#include <stdlib.h>
#include <vector>

enum DataType : char { ERROR, INT, FLOAT, BOOL };

class DataPattern
{
	public:
		DataPattern();
		void addType(const DataType& t);
		size_t getSize() const; // gibt die Anzahl der Typen an
		size_t getBytesSize() const; // gibt die Anzahl der Bytes aller Typen an
		bool validIndex(unsigned int index) const;
		DataType operator[](unsigned int index) const;

		static size_t getTypeSize(const DataType&);
		static bool matches(const DataPattern& p1, const DataPattern& p2);
	private:
		std::vector<DataType> pattern;
};

#endif
