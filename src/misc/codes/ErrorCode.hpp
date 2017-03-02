#ifndef __ERRORCODE_CLASS__
#define __ERRORCODE_CLASS__

#include <string>

enum ErrorCode { NONE, WRONG_PARAMETER_SIZE, TYPE_MISMATCH };

std::string getString(const ErrorCode code);

#endif
