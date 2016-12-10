#ifndef __FUNCTION_CLASS__
#define __FUNCTION_CLASS__

class Function
{
	public:
		template<typename func>
		void addFunction(func f); // f is Function to add
};

#endif
