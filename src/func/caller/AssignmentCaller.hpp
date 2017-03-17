#ifndef __ASSIGNMENTCALLER_CLASS__
#define __ASSIGNMENTCALLER_CLASS__

#include "Caller.hpp"

#include <data/DataMask.hpp>
#include <data/DataPattern.hpp>

class AssignmentCaller : public Caller
{
	public:
		AssignmentCaller(const DataMask& targetValues, const DataPattern& targetPattern);
		virtual ~AssignmentCaller();
		virtual void call(Data&) override;
	private:
		DataMask targetValues_;
		DataPattern targetPattern_;
};

#endif
