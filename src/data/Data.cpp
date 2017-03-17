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

void Data::addDataFrom(const Data& source, const unsigned int offset, const unsigned int size)
{
	addData(((char*)source.data_)+offset, size);
}

void Data::addData(void *source, unsigned int size)
{
	allocate(size_+size); // ausreichend Speicher reservieren
	char* c = (char*) data_;
	memcpy(c+size_, source, size);
	size_ += size;
}

bool Data::validIndex(unsigned int offset) const
{
	return (offset >= 0) && (offset < size_);
}

bool Data::allocate(const unsigned int size)
{
	if (size < capacity_) // data soll nicht durch allocate kleiner werden
		return false;
	data_ = realloc(data_, size);
	capacity_ = size;
	return true;
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
