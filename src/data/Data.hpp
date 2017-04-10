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
		void copyFromAt(const unsigned int ownOffset, const Data& source, const unsigned int sourceOffset, const unsigned int size);
		bool validIndex(unsigned int offset) const;
		// the data object contains <size> bytes after this operation, unless it contained more before
		bool allocate(const unsigned int size);

		void reset(unsigned int c = 0);

		void printString() const;

		unsigned int getSize() const;
	private:
		void* data_;
		unsigned int size_;
		unsigned int capacity_;
};

#endif
