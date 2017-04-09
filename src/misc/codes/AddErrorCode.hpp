#ifndef __ADDERRORCODE_CLASS__
#define __ADDERRORCODE_CLASS__

#include <string>

enum AddErrorCode { NONE, WRONG_PARAMETER_SIZE, TYPE_MISMATCH, MUTATE_WHILE_RUNNING };

std::string getString(const AddErrorCode code);

#endif
