#include "Data.hpp"

#include <string.h>
#include <stdlib.h>
#include <bitset>

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

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

// Diese Funktion überprüft nicht, ob der Zugriff über denn reservierten Speicherplatz hinaus geht
template<typename T>
T Data::getAt(const unsigned int offset) const
{
	if (!validIndex(offset))
	{
		Debug::warn("Data::getIntAt(index=" + Converter::intToString(offset) + "): invalid index");
		return 0;
	}
	char *c = (char*)data_;
	T *x = (T*)(c+offset);
	return *x;
}

#define T(data_type, c_type) template c_type Data::getAt(const unsigned int offset) const;
#define U(data_type, c_type) ;
#include <data/types/types.list>
#undef T
#undef U

template<typename T>
Data& Data::operator<<(T t)
{
	addData(&t, sizeof(t));
	return *this;
}

#define T(data_type, c_type) template Data& Data::operator<<(c_type t);
#define U(data_type, c_type) ;
#include <data/types/types.list>
#undef T
#undef U

template <typename T>
void Data::setAt(const T& value, const unsigned int offset)
{
	char* c = ((char*) data_)+offset;
	*c = value;
}

#define T(data_type, c_type) template void Data::setAt(const c_type& value, const unsigned int offset);
#define U(data_type, c_type) ;
#include <data/types/types.list>
#undef T
#undef U

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

void Data::copyFromAt(const unsigned int ownOffset, const Data& source, const unsigned int sourceOffset, const unsigned int size)
{
	char* d = (char*)data_;
	const char* s = (char*)source.data_;
	memcpy(d+ownOffset, s+sourceOffset, size);
}

bool Data::validIndex(unsigned int offset) const
{
	return (offset >= 0) && (offset < capacity_);
}

bool Data::allocate(const unsigned int size)
{
	if (size < capacity_) // data soll nicht durch allocate kleiner werden
		return false;
	data_ = realloc(data_, size);
	capacity_ = size;
	return true;
}

void Data::reset(unsigned int c)
{
	free(data_);
	data_ = malloc(c);
	size_ = 0;
	capacity_ = c;
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
