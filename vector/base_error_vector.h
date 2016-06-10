#ifndef BASE_ERROR_VECTOR_H
#define BASE_ERROR_VECTOR_H
#include "base_error/base_error.h"

class base_error_vector : public base_error
{
public:
    virtual const char* what() = 0;
};

#endif // BASE_ERROR_VECTOR_H
