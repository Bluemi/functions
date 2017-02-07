#include "Data.hpp"

#include <string.h>
#include <stdlib.h>

Data::Data()
	: size(0)
{}

Data::~Data()
{
	free(data);
}

Data& Data::operator<<(int i)
{
	if (size == 0) // Wenn noch nie speicher zugewiesen wurde
	{
		data = malloc(sizeof(int));
		memcpy(data, &i, sizeof(int));
	}
	else
	{
		data = realloc(data, size+sizeof(int));
		char* c = (char*) data;
		memcpy(c+size, &i, sizeof(int));
	}
	size += sizeof(int);
	return *this;
}

int Data::getIntAt(unsigned int offset) const
{
	char *c = (char*)data;
	int *x = (int*)(c+offset);
	return *x;
}
