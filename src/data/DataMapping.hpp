#ifndef __DATAMAPPING_CLASS__
#define __DATAMAPPING_CLASS__

/*
	Speichert die für einen Funktionsaufruf nötigen offsets bezüglich des void-Pointers
*/

#include <vector>

typedef unsigned int data_offset;

class DataMapping
{
	public:
		DataMapping();
		DataMapping& operator<< (const data_offset value);
		void addOffset(const unsigned int index, const data_offset value);

		data_offset operator[](const unsigned int index) const;

		bool validIndex(const unsigned int index) const;
		unsigned int getSize() const;
	private:
		std::vector<data_offset> offsets_;
};

#endif
