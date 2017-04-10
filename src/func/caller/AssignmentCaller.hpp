#ifndef __ASSIGNMENTCALLER_CLASS__
#define __ASSIGNMENTCALLER_CLASS__

#include "Caller.hpp"

#include <data/DataMapping.hpp>
#include <data/DataPattern.hpp>

class AssignmentCaller : public Caller
{
	public:
		AssignmentCaller(const DataMapping& targetValues, const DataPattern& targetPattern);
		virtual ~AssignmentCaller();
		virtual void call(Data&) override;
	private:
		DataMapping targetValues_;
		DataPattern targetPattern_;
};

#endif
