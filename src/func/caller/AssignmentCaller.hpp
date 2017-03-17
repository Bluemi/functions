#ifndef __ASSIGNMENTCALLER_CLASS__
#define __ASSIGNMENTCALLER_CLASS__

#include "Caller.hpp"

#include <data/DataMask.hpp>

class AssignmentCaller : public Caller
{
	public:
		AssignmentCaller(const DataMask& lvalue);
		virtual ~AssignmentCaller();
		virtual void call(Data&) override;
	private:
		DataMask lvalue_;
};

#endif
