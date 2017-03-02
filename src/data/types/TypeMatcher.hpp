#ifndef __TYPEMATCHER_CLASS__
#define __TYPEMATCHER_CLASS__

template<typename U, typename V>
class TypeMatcher
{
	public:
		enum { equals = 0 };
};

template<typename U>
class TypeMatcher<U, U>
{
	public:
		enum { equals = 1 };
};

#endif
