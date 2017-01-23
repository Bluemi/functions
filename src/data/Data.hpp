#ifndef __DATA_CLASS__
#define __DATA_CLASS__

#include <vector>

#include "Date.hpp"

class Data
{
	public:
		Data();
		void addDate(Date d);
		Date getDate(unsigned int index) const;
		bool validIndex(unsigned int index) const;
		unsigned int size();
	private:
		std::vector<Date> data;
};

#endif
