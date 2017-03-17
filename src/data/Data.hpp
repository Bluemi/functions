#ifndef __DATA_CLASS__
#define __DATA_CLASS__

class Data
{
	public:
		Data();
		Data(unsigned int c); // reserviert einen Speicher mit c Bytes vor
		~Data();
		template<typename T>
		T getAt(const unsigned int offset) const;

		template <typename T>
		Data& operator<<(T t);

		template <typename T>
		void setAt(const T& value, const unsigned int offset);

		void addDataFrom(const Data& source, const unsigned int offset, const unsigned int size);
		void addData(void *source, unsigned int size);
		bool validIndex(unsigned int offset) const;
		// the data object contains <size> bytes after this operation, unless it contained more before
		bool allocate(const unsigned int size);

		void printString() const;

		unsigned int getSize() const;
	private:
		void* data_;
		unsigned int size_;
		unsigned int capacity_;
};

#include <misc/Debug.hpp>
#include <misc/Converter.hpp>

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

template<typename T>
Data& Data::operator<<(T t)
{
	addData(&t, sizeof(t));
	return *this;
}

template <typename T>
void Data::setAt(const T& value, const unsigned int offset)
{
	char* c = ((char*) data_)+offset;
	*c = value;
}

#endif
