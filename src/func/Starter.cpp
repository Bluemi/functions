#include "Starter.hpp"

#include <misc/Debug.hpp>

Starter::Starter(Function* f)
	: function_(f)
{}

StartErrorCode Starter::start()
{
	// Check Parameter Types
	if (!DataPattern::matches(function_->getParameterPattern(), dataPattern_))
	{
		return StartErrorCode::PARAMETER_TYPE_MISMATCH;
	}
	// allocate Stack
	if (!data_.allocate(function_->getStackPattern().getBytesSize()))
		return StartErrorCode::DATA_ALLOC_FAIL;
	// initiate returnValues
	returnValues_.reset(function_->getReturnPattern().getBytesSize());
	// call
	function_->call(data_, &returnValues_);
	return StartErrorCode::START_NONE;
}

template <typename T>
Starter& Starter::operator<<(T t)
{
	data_ << t;
	dataPattern_ << Typer<T>::toDataType();
	return *this;
}

#define T(data_type, c_type) template Starter& Starter::operator<<(c_type t);
#define U(data_type, c_type) ;
#include <data/types/types.list>
#undef T
#undef U

const Data& Starter::getReturnValues() const
{
	return returnValues_;
}
