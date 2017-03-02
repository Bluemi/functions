#ifndef __STARTERRORCODE_CLASS__
#define __STARTERRORCODE_CLASS__

#include <string>

enum StartErrorCode { START_NONE, PARAMETER_TYPE_MISMATCH, DATA_ALLOC_FAIL };

std::string getString(const StartErrorCode code);

#endif
