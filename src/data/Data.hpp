#ifndef __DATA_CLASS__
#define __DATA_CLASS__

class Data
{
	public:
		Data();
		~Data();
		int getIntAt(unsigned int offset) const;
		Data& operator<<(int i);
	private:
		void* data;
		unsigned int size;
};

#endif
