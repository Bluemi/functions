#include "Data.hpp"

#include <string.h>
#include <stdlib.h>
#include <bitset>

Data::Data()
	: size_(0), capacity_(0)
{
	data_ = malloc(0);
}

Data::Data(unsigned int c)
	: size_(0), capacity_(c)
{
	data_ = malloc(c);
}

Data::~Data()
{
	free(data_);
}

void Data::copyFrom(const Data& source, const unsigned int offset, const unsigned int size)
{
	copyData(((char*)source.data_)+offset, size);
}

void Data::copyData(void *source, unsigned int size)
{
	if (capacity_ < size_+size)
	{
		data_ = realloc(data_, size_+size);
		capacity_ = size_+size;
	}
	char* c = (char*) data_;
	memcpy(c+size_, source, size);
	size_ += size;
}

bool Data::validIndex(unsigned int offset) const
{
	return (offset >= 0) && (offset < size_);
}

void Data::printString() const
{
	for (unsigned int i = 0; i < size_; i++)
	{
		char* c = (char*)data_;
		std::bitset<8> b(*(c+i));
		std::cout << b << std::endl;
	}
}

unsigned int Data::getSize() const
{
	return size_;
}
