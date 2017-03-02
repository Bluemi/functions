#ifndef __DATA_CLASS__
#define __DATA_CLASS__

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

class Data
{
	public:
		Data();
		Data(unsigned int c); // reserviert einen Speicher mit c Bytes vor
		~Data();
		template<typename T>
		T getAt(unsigned int offset) const;

		template <typename T>
		Data& operator<<(T t);

		void copyFrom(const Data& source, const unsigned int offset, const unsigned int size);
		void copyData(void *source, unsigned int size);
		bool validIndex(unsigned int offset) const;
		bool allocate(const unsigned int size);

		void printString() const;

		unsigned int getSize() const;
	private:
		void* data_;
		unsigned int size_;
		unsigned int capacity_;
};

// Diese Funktion überprüft nicht, ob der Zugriff über denn reservierten Speicherplatz hinaus geht
template<typename T>
T Data::getAt(unsigned int offset) const
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

template<typename T>
Data& Data::operator<<(T t)
{
	copyData(&t, sizeof(t));
	return *this;
}

#endif
