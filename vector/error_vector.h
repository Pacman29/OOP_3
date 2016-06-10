#ifndef LENGTH_ERROR_H
#define LENGTH_ERROR_H
#include "base_error_vector.h"

namespace vector_error {

class length_error : public base_error_vector
{
public:
    length_error(){}
    const char* what() override
    {
        return "vector_error::length of the vector is incorrect";
    }
};

class memory_error : public base_error_vector
{
public:
    memory_error(){}
    const char* what() override
    {
        return "vector_error::memory is not allocated";
    }
};

class index_error : public base_error
{
public:
    index_error(){}
    const char* what() override
    {
        return "vector_error::input incorrect index";
    }
};


}

#endif // LENGTH_ERROR_H
