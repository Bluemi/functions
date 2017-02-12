#ifndef __DATAPATTERN_CLASS__
#define __DATAPATTERN_CLASS__

#include <stdlib.h>
#include <vector>
#include <string>

#include "DataType.hpp"

class DataPattern
{
	public:
		DataPattern();
		void addType(const DataType& t);
		unsigned int getSize() const; // gibt die Anzahl der Typen an
		unsigned int getBytesSize() const; // gibt die Anzahl der Bytes aller Typen an
		bool validIndex(unsigned int index) const;
		DataType operator[](unsigned int index) const;

		DataType getTypeAt(unsigned int offset) const; // returnt den Datentyp an der Stelle index

		static bool matches(const DataPattern& p1, const DataPattern& p2);

		std::string toString() const;
	private:
		std::vector<DataType> pattern_;
};

#endif
