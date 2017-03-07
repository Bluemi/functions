#ifndef __ASSIGNMENTCALLER_CLASS__
#define __ASSIGNMENTCALLER_CLASS__

#include "Caller.hpp"

class AssignmentCaller : public Caller
{
	public:
		AssignmentCaller();
		virtual ~AssignmentCaller();
		virtual void call(const Data&);
};

#endif
