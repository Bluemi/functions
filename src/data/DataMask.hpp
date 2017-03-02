#ifndef __DATAMASK_CLASS__
#define __DATAMASK_CLASS__

/*
	Speichert die für einen Funktionsaufruf nötigen offsets bezüglich des void-Pointers
*/

#include <vector>

class DataMask
{
	public:
		DataMask();
		DataMask& operator<< (const unsigned int value);
		void addOffset(const unsigned int index, const unsigned int value);

		unsigned int operator[](const unsigned int index) const;

		bool validIndex(const unsigned int index) const;
		unsigned int getSize() const;
	private:
		std::vector<unsigned int> offsets_;
};

#endif
